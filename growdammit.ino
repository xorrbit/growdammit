// comment out this next line to enable debug mode
// this sets the reporting period to 2 seconds instead of five minutes
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

unsigned long inline ntp_unix_time ();

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
  while(reset_time == 0)
    reset_time = ntp_unix_time();
  reset_time -= (millis()/1000);
  
  pinMode(LED_BUILTIN, OUTPUT);
#ifdef DEBUG
  Serial.begin(115200);
  Serial.println();
  Serial.println("GROW DAMMIT!");
  Serial.print("built on ");
  Serial.print(__DATE__);
  Serial.print(" at ");
  Serial.println(__TIME__);
  Serial.print("Reset time: ");
  Serial.println(reset_time);
#endif
}

void loop() {
  int light, soil;
  float humidity, temperature;
  
  digitalWrite(LED_BUILTIN, LOW);

  // read light sensor
  digitalWrite(LIGHT_ENABLE, HIGH);
  delay(100);
  light = analogRead(A0);
  digitalWrite(LIGHT_ENABLE, LOW);
  delay(100);
  
  // read soil sensor
  digitalWrite(SOIL_ENABLE, HIGH);
  delay(100);
  soil = analogRead(A0);
  digitalWrite(SOIL_ENABLE, LOW);
  delay(100);

  // read humidity and temperature
  humidity = weather.readHumidity();
  temperature = weather.readTemperature();

  unix_time = reset_time + (millis() / 1000);
                                
  digitalWrite(LED_BUILTIN, HIGH);
#ifdef DEBUG
  Serial.print("Light: ");
  Serial.print(light);
  Serial.print("  Soil: ");
  Serial.print(soil);
  Serial.print("  Temperature: ");
  Serial.print(temperature);
  Serial.print("  Humiditiy: ");
  Serial.print(humidity);
  Serial.print("  Time: ");
  Serial.print(unix_time);
  Serial.println();
  delay(10000);
#else
  delay(60000);
#endif
}

unsigned long ntp_unix_time()
{
  unsigned long unix_time = 0;
  int i, len;
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
