#ifndef MAGNETIC_H
#define MAGNETIC_H

#include "config.h"

class Magnetic {
  private:
   uint16_t crc_check(uint8_t* array, uint32_t arrayLength);

   const uint16_t _seed = 0xFFFF;
   const uint16_t _poly = 0xA001;

  public:
   void getSensorAddress();
   void setSensorAddress(int address);
   void readSensorAllValue(int address);
};

#endif  // MAGNETIC_H