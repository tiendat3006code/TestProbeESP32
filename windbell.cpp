#include "windbell.h"

unsigned int Windbell::crc_check(unsigned char* ptr, unsigned char length)  // crc12
{
   unsigned int crc12out = 0;
   unsigned char i, j;
   for (j = 0; j < length; j++) {
      for (i = 0; i < 8; i++) {
         if (*(ptr + j) & (0x80 >> i))
            crc12out |= 0x1;
         if (crc12out >= 0x1000)
            crc12out ^= 0x180d;
         crc12out <<= 1;
      }
   }
   for (i = 0; i < 12; i++) {
      if (crc12out >= 0x1000)
         crc12out ^= 0x180d;
      crc12out <<= 1;
   }
   crc12out >>= 1;
   return (crc12out);
}

void Windbell::askProbeLevel() {
   Serial.println("Ask level");
   uint8_t dataToSend[10];
   dataToSend[0] = FRAME_HEAD;
   dataToSend[1] = static_cast<uint8_t>(5);
   dataToSend[2] = static_cast<uint8_t>((ADDRESS >> 16) & 0xFF);
   dataToSend[3] = static_cast<uint8_t>((ADDRESS >> 8) & 0xFF);
   dataToSend[4] = static_cast<uint8_t>((ADDRESS >> 0) & 0xFF);
   dataToSend[5] = ASK_LEVEL;
   dataToSend[6] = 0x00;

   uint8_t dataToCRC[5];
   for (int i = 0; i < 5; i++) {
      dataToCRC[i] = dataToSend[2 + i];
   }

   unsigned int crc = crc_check(dataToCRC, 5);
   dataToSend[7] = (crc >> 8) & 0xFF;
   dataToSend[8] = (crc >> 0) & 0xFF;
   dataToSend[9] = FRAME_TAIL;

   Serial.print("High byte: ");
   Serial.println(dataToSend[7], HEX);
   Serial.print("Low byte: ");
   Serial.println(dataToSend[8], HEX);

   Serial2.write(dataToSend, sizeof(dataToSend) / sizeof(dataToSend[0]));
   Serial2.flush();
}

void Windbell::askProbeAverageTemperature() {
   Serial.println("Ask average temperature");
   uint8_t dataToSend[10];
   dataToSend[0] = FRAME_HEAD;
   dataToSend[1] = static_cast<uint8_t>(5);
   dataToSend[2] = static_cast<uint8_t>((ADDRESS >> 16) & 0xFF);
   dataToSend[3] = static_cast<uint8_t>((ADDRESS >> 8) & 0xFF);
   dataToSend[4] = static_cast<uint8_t>((ADDRESS >> 0) & 0xFF);
   dataToSend[5] = ASK_AVERAGE_TEMPERATURE;
   dataToSend[6] = 0x00;

   uint8_t dataToCRC[5];
   for (int i = 0; i < 5; i++) {
      dataToCRC[i] = dataToSend[2 + i];
   }

   unsigned int crc = crc_check(dataToCRC, 5);
   dataToSend[7] = (crc >> 8) & 0xFF;
   dataToSend[8] = (crc >> 0) & 0xFF;
   dataToSend[9] = FRAME_TAIL;

   Serial.print("High byte: ");
   Serial.println(dataToSend[7], HEX);
   Serial.print("Low byte: ");
   Serial.println(dataToSend[8], HEX);

   Serial2.write(dataToSend, sizeof(dataToSend) / sizeof(dataToSend[0]));
   Serial2.flush();
}

void Windbell::askProbeFiveTemperatures() {
   Serial.println("Ask five temperature");
   uint8_t dataToSend[10];
   dataToSend[0] = FRAME_HEAD;
   dataToSend[1] = static_cast<uint8_t>(5);
   dataToSend[2] = static_cast<uint8_t>((ADDRESS >> 16) & 0xFF);
   dataToSend[3] = static_cast<uint8_t>((ADDRESS >> 8) & 0xFF);
   dataToSend[4] = static_cast<uint8_t>((ADDRESS >> 0) & 0xFF);
   dataToSend[5] = ASK_FIVE_TEMPERATURES;
   dataToSend[6] = 0x00;

   uint8_t dataToCRC[5];
   for (int i = 0; i < 5; i++) {
      dataToCRC[i] = dataToSend[2 + i];
   }

   unsigned int crc = crc_check(dataToCRC, 5);
   dataToSend[7] = (crc >> 8) & 0xFF;
   dataToSend[8] = (crc >> 0) & 0xFF;
   dataToSend[9] = FRAME_TAIL;

   Serial.print("High byte: ");
   Serial.println(dataToSend[7], HEX);
   Serial.print("Low byte: ");
   Serial.println(dataToSend[8], HEX);

   Serial2.write(dataToSend, sizeof(dataToSend) / sizeof(dataToSend[0]));
   Serial2.flush();
}
