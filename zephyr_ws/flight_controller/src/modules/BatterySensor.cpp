
#include "BatterySensor.h"


BatterySensor::BatterySensor(IAdc& adc)
    : _adc(adc)
{
}

void BatterySensor::initialize()
{
    _adc.initialize();
}

uint32_t BatterySensor::readMillivolts()
{
    _adc.read();
    return getVoltage();
}

uint32_t BatterySensor::getVoltage()
{
    auto const raw = _adc.lastReading();
    return static_cast<uint32_t>(raw * _scale * 1000.0f);
}
