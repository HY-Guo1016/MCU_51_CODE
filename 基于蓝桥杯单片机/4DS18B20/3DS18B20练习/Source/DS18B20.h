#ifndef __DS18B20_H__
#define __DS18B20_H__

#include "OneWire.h"

//ROM COMMANDS 
#define  SEARCH_ROM         0xF0
#define  READ_ROM           0x33
#define  MATCH_ROM          0x55
#define  SKIP_ROM           0xCC
#define  ALARM_SEARCH       0xEC


//DS18B20 FUNCTION COMMANDS
#define  CONVERT_T          0x44
#define  WRITE_SCRATCHPAD   0x4E
#define  READ_SCRATCHPAD    0xBE
#define  COPY_SCRATCHPAD    0x48
#define  RECALL_E2          0xB8
#define  READ_POWER_SUPPLY  0xB4

bit Start18B20();
bit Read18B20(int *tmp);
#endif