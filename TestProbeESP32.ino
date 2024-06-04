#include "config.h"
#include "magnetic.h"
#include "windbell.h"

Windbell windbell;
Magnetic magnetic;
bool probeType;

// put function declarations here:
void readDataReceived() {
   if (Serial2.available()) {
      String dataReceived = Serial2.readString();
      for (int i = 0; i < dataReceived.length(); i++) {
         Serial.print("Data received: ");
         Serial.println(dataReceived.charAt(i), HEX);
      }
   }
}

void setup() {
   // put your setup code here, to run once:
   Serial.begin(115200);
   Serial.println("Test probe starting up");
   Serial.println("Type in probe types to test: ");
   while (1) {
      if (Serial.available()) {
         String text = Serial.readString();
         if (text == "windbell") {
            Serial.println("Windbell probe test");
            Serial2.begin(2400, SERIAL_8N1, 16, 17);
            probeType = true;
            break;
         } else if (text == "magnetic") {
            Serial.println("Magnetic probe test");
            Serial2.begin(9600, SERIAL_8N1, 16, 17);
            probeType = false;
            break;
         } else {
            Serial.println("Invalid");
         }
      }
   }
}

void loop() {
   // put your main code here, to run repeatedly:
   if (probeType) {
      while (Serial.available()) {
         char l = (char)Serial.read();
         if (l == '0') {
            windbell.askProbeLevel();
         } else if (l == '1') {
            windbell.askProbeAverageTemperature();
         } else if (l == '2') {
            windbell.askProbeFiveTemperatures();
         } else {
            Serial.println("Invalid");
         }
      }
   } else {
      while (Serial.available()) {
         String str = Serial.readString();
         if (str == "get") {
            magnetic.getSensorAddress();
         } else if (str == "set") {
            Serial.println("Set sensor address");
            Serial.println("Type in sensor address: ");
            while (1) {
               if (Serial.available()) {
                  String str_1 = Serial.readString();
                  if (str_1 == "exit") {
                     Serial.println("Exit set sensor address mode");
                     break;
                  } else
                     magnetic.setSensorAddress(str_1.toInt());
               }
               readDataReceived();
            }
         } else if (str == "read") {
            Serial.println("Type in sensor address: ");
            while (1) {
               if (Serial.available()) {
                  String str_1 = Serial.readString();
                  if (str_1 == "exit") {
                     Serial.println("Exit read sensor all value mode");
                     break;
                  } else
                     magnetic.readSensorAllValue(str_1.toInt());
               }
               readDataReceived();
            }
         }
      }
   }
   readDataReceived();
}
