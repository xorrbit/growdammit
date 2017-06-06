// comment out this next line to enable debug mode
// this sets the reporting period to 10 seconds instead of one minute
// and outputs on the serial port
#define DEBUG

// ssid info goes in here
#include "config.h"

#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <WiFiUdp.h>

#include <SparkFunHTU21D.h>
#include <Wire.h>

// Soil Moisture Sensor
//    SIG pin connected to AD0
//    GND pin connected to GND
//    VCC pin connected to D2 (GPIO4)
#define SOIL_ENABLE  4
//
// Ambient Light Sensor
//    SIG pin connected to AD0
//    GND pin connected to GND
//    VCC pin connected to D1 (GPIO5)
#define LIGHT_ENABLE 5
//
// Temperature and Humidity Sensor
//    GND pin connected to GND
//    3.3V pin connected to 3.3V
//    DA pin connected to D6 (GPIO12)
//    CL pin connected to D5 (GPIO14)
#define WEATHER_DA 12
#define WEATHER_CL 14

// humidity and temp sensor library
HTU21D weather;

// HTTPS client
WiFiClientSecure https;

// for NTP client
WiFiUDP udp;
unsigned long unix_time;
unsigned long reset_time;

unsigned long inline ntp_unix_time();
String urlencode(String str);

unsigned long chip_id;
// Jan++4+2017+11%3A11%3A11
char build_time_cstr[25];
// 100.00
char humidity_cstr[7];
char temperature_cstr[7];
String build_time;
int ambient_light, soil_moisture;
float humidity, temperature;

unsigned int i, len;

char https_url[256];

void setup() {
  // disables soil and light sensors on boot
  pinMode(SOIL_ENABLE, OUTPUT);
  digitalWrite(SOIL_ENABLE, LOW);
  pinMode(LIGHT_ENABLE, OUTPUT);
  digitalWrite(LIGHT_ENABLE, LOW);

  Wire.begin(WEATHER_DA, WEATHER_CL);
  weather.begin();

  WiFi.begin(wifi_ssid, wifi_password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
  }

  // figure out roughly when our reset time was
  reset_time = 0;
  while (reset_time == 0)
    reset_time = ntp_unix_time();
  reset_time -= (millis() / 1000);

  chip_id = ESP.getChipId();
  sprintf(build_time_cstr, "%s %s", __DATE__, __TIME__);
  build_time = urlencode(String(build_time_cstr));

  pinMode(LED_BUILTIN, OUTPUT);
#ifdef DEBUG
  Serial.begin(115200);
  Serial.println();
  Serial.println("GROW DAMMIT!");
#endif
}

void loop() {
  digitalWrite(LED_BUILTIN, LOW);

  // read light sensor
  digitalWrite(LIGHT_ENABLE, HIGH);
  delay(100);
  ambient_light = analogSample();
  digitalWrite(LIGHT_ENABLE, LOW);
  delay(100);

  // read soil sensor
  digitalWrite(SOIL_ENABLE, HIGH);
  delay(100);
  soil_moisture = analogSample();
  digitalWrite(SOIL_ENABLE, LOW);
  delay(100);

  // read humidity and temperature
  humidity = humiditySample();
  dtostrf(humidity, 5, 2, humidity_cstr);
  temperature = temperatureSample();
  dtostrf(temperature, 5, 2, temperature_cstr);

  unix_time = reset_time + (millis() / 1000);
  
  len = sprintf(https_url, "%s", logging_url);
  len += sprintf(https_url+len, "?unix_time=%d", unix_time);
  len += sprintf(https_url+len, "&temperature=%s", temperature_cstr);
  len += sprintf(https_url+len, "&humidity=%s", humidity_cstr);
  len += sprintf(https_url+len, "&ambient_light=%d", ambient_light);
  len += sprintf(https_url+len, "&soil_moisture=%d", soil_moisture);
  len += sprintf(https_url+len, "&chip_id=%d", chip_id);
  len += sprintf(https_url+len, "&build_time=%s", build_time.c_str());
  len += sprintf(https_url+len, "&reset_time=%d", reset_time);

  https.connect(logging_host, 443);
  https.print(String("GET ") + https_url + " HTTP/1.1\r\n" +
               "Host: " + logging_host + "\r\n" +
               "User-Agent: growdammit\r\n" +
               "Connection: close\r\n\r\n");

  digitalWrite(LED_BUILTIN, HIGH);
#ifdef DEBUG
  Serial.println(https_url);
  delay(10000);
#else
  delay(LOG_PERIOD);
#endif
}

unsigned long ntp_unix_time()
{
  unsigned long unix_time = 0;
  const byte NTP_HEADER[4] = { 0xEC, 0x06, 0x00, 0xE3 };
  const byte NULL_DATA[1] = { 0x00 };

  if (!udp.begin(ntp_local_port))
    return 0;

  // send our NTP packet
  udp.flush();
  udp.beginPacket(ntp_server, ntp_port);
  udp.write(NTP_HEADER, 4);
  for (i = 0; i < 44; i++)
    udp.write(NULL_DATA, 1);
  udp.endPacket();

  // read response
  for (i = 0; i < 20; i++)
  {
    if ((len = udp.parsePacket()) == 48)
      break;
    delay(200);
  }
  if (len != 48)
    return 0;
  for (int i = 0; i < 32; i++)
    udp.read();
  unix_time = udp.read();
  for (int i = 0; i < 3; i++)
    unix_time = unix_time << 8 | udp.read();
  udp.flush();

  return unix_time - 2208988800ul;
}

String urlencode(String str)
{
  String encodedString = "";
  char c;
  char code0;
  char code1;
  char code2;
  for (int i = 0; i < str.length(); i++) {
    c = str.charAt(i);
    if (c == ' ') {
      encodedString += '+';
    } else if (isalnum(c)) {
      encodedString += c;
    } else {
      code1 = (c & 0xf) + '0';
      if ((c & 0xf) > 9) {
        code1 = (c & 0xf) - 10 + 'A';
      }
      c = (c >> 4) & 0xf;
      code0 = c + '0';
      if (c > 9) {
        code0 = c - 10 + 'A';
      }
      code2 = '\0';
      encodedString += '%';
      encodedString += code0;
      encodedString += code1;
      //encodedString+=code2;
    }
    yield();
  }
  return encodedString;
}

#define NUM_SAMPLES 100
#define NUM_DISCARD 10
unsigned int samples[NUM_SAMPLES];

void bubble_sort(unsigned int samples[], unsigned int len) {
  for (int i = 0; i < (len-1); i++) {
    for (int j = 0; j < (len-(i+1)); j++) {
      if(samples[j] > samples[j+1]) {
        unsigned int t = samples[j];
        samples[j] = samples[j+1];
        samples[j+1] = t;
      }
    }
  }
}

// read in 100 values, sort them, and
// discard the largest and smallest 10
// then take the average of the rest
unsigned int analogSample()
{
  unsigned int i;
  unsigned long average;

  for (i = 0; i < NUM_SAMPLES; i++)
  {
    samples[i] = analogRead(A0);
    delay(1);
  }

  bubble_sort(samples, NUM_SAMPLES);

  for (i = NUM_DISCARD; i < (NUM_SAMPLES-NUM_DISCARD); i++)
  {
    average += samples[i];
  }
  average = average / (NUM_SAMPLES - (2*NUM_DISCARD));

  return (unsigned int)average;
}

void bubble_sort(float samples[], unsigned int len) {
  for (int i = 0; i < (len-1); i++) {
    for (int j = 0; j < (len-(i+1)); j++) {
      if(samples[j] > samples[j+1]) {
        float t = samples[j];
        samples[j] = samples[j+1];
        samples[j+1] = t;
      }
    }
  }
}

#define TEMP_SAMPLES 20
#define TEMP_DISCARD 2
float tsamples[TEMP_SAMPLES];

float temperatureSample()
{
  unsigned int i;
  float average;

  for (i = 0; i < TEMP_SAMPLES; i++)
  {
    tsamples[i] = weather.readTemperature();
    delay(1);
  }

  bubble_sort(tsamples, TEMP_SAMPLES);

  for (i = TEMP_DISCARD; i < (TEMP_SAMPLES-TEMP_DISCARD); i++)
  {
    average += tsamples[i];
  }
  average = average / (TEMP_SAMPLES - (2*TEMP_DISCARD));

  return average;
}

float humiditySample()
{
  unsigned int i;
  float average;

  for (i = 0; i < TEMP_SAMPLES; i++)
  {
    tsamples[i] = weather.readHumidity();
    delay(1);
  }

  bubble_sort(tsamples, TEMP_SAMPLES);

  for (i = TEMP_DISCARD; i < (TEMP_SAMPLES-TEMP_DISCARD); i++)
  {
    average += tsamples[i];
  }
  average = average / (TEMP_SAMPLES - (2*TEMP_DISCARD));

  return average;
}
