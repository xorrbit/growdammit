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

void setup() {
  // disables soil and light sensors on boot
  pinMode(SOIL_ENABLE, OUTPUT);
  digitalWrite(SOIL_ENABLE, LOW);
  pinMode(LIGHT_ENABLE, OUTPUT);
  digitalWrite(LIGHT_ENABLE, LOW);

  Wire.begin(WEATHER_DA, WEATHER_CL);
  weather.begin();
  
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.begin(115200);
  Serial.println();
  Serial.println("GROW DAMMIT!");
  Serial.print("built on ");
  Serial.print(__DATE__);
  Serial.print(" at ");
  Serial.println(__TIME__);
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
                                
  digitalWrite(LED_BUILTIN, HIGH);
  Serial.print("Light: ");
  Serial.print(light);
  Serial.print("  Soil: ");
  Serial.print(soil);
  Serial.print("  Temperature: ");
  Serial.print(temperature);
  Serial.print("  Humiditiy: ");
  Serial.print(humidity);
  Serial.println();
  delay(5000);
}
