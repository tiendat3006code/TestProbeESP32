#include "magnetic.h"

uint16_t Magnetic::crc_check(uint8_t* array, uint32_t arrayLength) {
   int i, j;
   uint16_t crc = _seed;
   for (i = 0; i < arrayLength; i++) {
      crc ^= (array[i]);
      for (j = 0; j < 8; ++j) {
         if (crc & 0x0001)
            crc = (crc >> 1) ^ _poly;
         else
            crc >>= 1;
      }
   }
   return crc;
}

void Magnetic::getSensorAddress() {
   Serial.println("Get sensor address");
   uint8_t dataToSend[8];

   dataToSend[0] = BROADCAST_MODE;
   dataToSend[1] = READ_REGISTER_ADDRESS;
   dataToSend[2] = 0x00;
   dataToSend[3] = MODBUS_REGISTER_ADDRESS;
   dataToSend[4] = 0x00;
   dataToSend[5] = 0x01;

   uint8_t dataToCRC[6];
   for (int i = 0; i < 6; i++) {
      dataToCRC[i] = dataToSend[i];
   }

   uint16_t crc = crc_check(dataToCRC, 6);
   dataToSend[6] = (crc >> 0) & 0xFF;
   dataToSend[7] = (crc >> 8) & 0xFF;

   Serial.print("Low byte CRC: ");
   Serial.println(dataToSend[6], HEX);
   Serial.print("High byte CRC: ");
   Serial.println(dataToSend[7], HEX);

   Serial2.write(dataToSend, sizeof(dataToSend) / sizeof(dataToSend[0]));
   Serial2.flush();
}

void Magnetic::setSensorAddress(int address) {
   Serial.print("Sensor address is set to: ");
   Serial.println(address);
   uint8_t dataToSend[8];

   dataToSend[0] = BROADCAST_MODE;
   dataToSend[1] = SET_REGISTER_ADDRESS;
   dataToSend[2] = 0x00;
   dataToSend[3] = MODBUS_REGISTER_ADDRESS;
   dataToSend[4] = 0x00;
   dataToSend[5] = static_cast<uint8_t>(address);

   uint8_t dataToCRC[6];
   for (int i = 0; i < 6; i++) {
      dataToCRC[i] = dataToSend[i];
   }

   uint16_t crc = crc_check(dataToCRC, 6);
   dataToSend[6] = (crc >> 0) & 0xFF;
   dataToSend[7] = (crc >> 8) & 0xFF;

   Serial.print("Low byte CRC: ");
   Serial.println(dataToSend[6], HEX);
   Serial.print("High byte CRC: ");
   Serial.println(dataToSend[7], HEX);

   Serial2.write(dataToSend, sizeof(dataToSend) / sizeof(dataToSend[0]));
   Serial2.flush();
}

void Magnetic::readSensorAllValue(int address) {
   Serial.println("Read sensor all value");
   Serial.print("Sensor address: ");
   Serial.println(address);
   uint8_t dataToSend[8];

   dataToSend[0] = static_cast<uint8_t>(address);
   dataToSend[1] = READ_REGISTER_ADDRESS;
   dataToSend[2] = 0x00;
   dataToSend[3] = 0x00;
   dataToSend[4] = 0x00;
   dataToSend[5] = static_cast<uint8_t>(16);

   uint8_t dataToCRC[6];
   for (int i = 0; i < 6; i++) {
      dataToCRC[i] = dataToSend[i];
   }

   uint16_t crc = crc_check(dataToCRC, 6);
   dataToSend[6] = (crc >> 0) & 0xFF;
   dataToSend[7] = (crc >> 8) & 0xFF;

   Serial.print("Low byte CRC: ");
   Serial.println(dataToSend[6], HEX);
   Serial.print("High byte CRC: ");
   Serial.println(dataToSend[7], HEX);

   Serial2.write(dataToSend, sizeof(dataToSend) / sizeof(dataToSend[0]));
   Serial2.flush();
}