
#ifndef __BATTERY_STATE_H__
#define __BATTERY_STATE_H__

#include <stdint.h>


enum class BatteryLevel
{
    Normal,
    Warning,
    Critical
};

struct BatteryState
{
    uint32_t voltage;
    BatteryLevel level;
};


#endif
