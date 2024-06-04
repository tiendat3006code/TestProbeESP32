#ifndef WINDBELL_H
#define WINDBELL_H

#include "config.h"

class Windbell
{
private:
    unsigned int crc_check(unsigned char* ptr, unsigned char length);
public:
    void askProbeLevel();
    void askProbeAverageTemperature();
    void askProbeFiveTemperatures();
};

#endif //WINDBELL_h