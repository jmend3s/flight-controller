
#include "BatteryMonitoringService.h"

#include "SystemPrint.h"


BatteryMonitoringService::BatteryMonitoringService(Adc& adc, Gpio& led)
    : _sensor(adc)
    , _led(led)
{
}

void BatteryMonitoringService::initialize()
{
    _sensor.initialize();
    _led.configure();
    SystemPrint::print("Battery monitoring service initialized\n");
}

void BatteryMonitoringService::update()
{
    auto const batteryLevel = _sensor.readMillivolts();
    SystemPrint::print("Last reading: %u mV\n", batteryLevel);
}

uint32_t BatteryMonitoringService::period() const
{
    return 10000;
}
