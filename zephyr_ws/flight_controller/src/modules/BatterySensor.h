
#ifndef __BATTERY_SENSOR_H__
#define __BATTERY_SENSOR_H__

#include "Adc.h"


class BatterySensor
{
public:
    BatterySensor(IAdc& adc);

    void initialize();

    uint32_t readMillivolts();

private:
    uint32_t getVoltage();

    IAdc& _adc;

    float const _scale = 0.003566f;
};


#endif
