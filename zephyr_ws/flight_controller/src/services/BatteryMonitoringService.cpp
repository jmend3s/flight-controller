
#include "BatteryMonitoringService.h"


BatteryMonitoringService::BatteryMonitoringService(Adc& adc)
    : _adc(adc)
{
}

void BatteryMonitoringService::initialize()
{
    _adc.initialize();
}

void BatteryMonitoringService::update()
{
    _adc.read();
}

uint32_t BatteryMonitoringService::period() const
{
    return 1000;
}

uint32_t BatteryMonitoringService::getReading() const
{
    return _adc.lastReading();
}
