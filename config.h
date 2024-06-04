#ifndef CONFIG_H
#define CONFIG_H

#include <Arduino.h>
#include <HardwareSerial.h>
#include <stdbool.h>
#include <stdint.h>

/*<============== Windbell Probe ===============>*/
/*=======================================*/
#define ADDRESS                        205800
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#define FRAME_HEAD                     0x68
#define ASK_LEVEL                      0x50
#define ASK_AVERAGE_TEMPERATURE        0x51
#define ASK_FIVE_TEMPERATURES          0x52
#define ASK_PROBE_ID                   0x70
#define ASK_PROBE_LENGTH               0x71
#define FRAME_TAIL                     0x16
/***********************************************/

/*
 * DEFINE MAGNETIC SENDOR PARAMETER
 * REGISTER 00-01: Fuel level
 * REGISTER 02-03: Water level
 * REGISTER 04-05: Fuel average temperature
 * REGISTER 06-07: A point temperature
 * REGISTER 08-09: B point temperature
 * REGISTER 0A-0B: C point temperature
 * REGISTER 0C-0D: D point temperature
 * REGISTER 0E-0F: E point temperature
 */
#define MODBUS_REGISTER_ADDRESS        0x20
#define READ_REGISTER_ADDRESS          0x04
#define SET_REGISTER_ADDRESS           0x06
#define BROADCAST_MODE                 0x00
#define OIL_FLOATING_POINT             0x30
#define WATER_FLOATING_POINT           0x32
#define OIL_LEVEL_COMPENSATION_VALUE   0x34
#define WATER_LEVEL_COMPENSATION_VALUE 0x36
/*************************************************/

#endif  // CONFIG_H