
#include "BatteryMonitoringService.h"

#include "SystemPrint.h"


BatteryMonitoringService::BatteryMonitoringService(Adc& adc, Gpio& led)
    : _adc(adc)
    , _led(led)
{
}

void BatteryMonitoringService::initialize()
{
    _adc.initialize();
    _led.configure();
    SystemPrint::print("Battery monitoring service initialized\n");
}

void BatteryMonitoringService::update()
{
    _adc.read();
    SystemPrint::print("Last reading: %i\n", _adc.lastReading());
    if (_adc.lastReading() < 1000)
    {
        SystemPrint::print("HIGH\n");
        _led.set(Gpio::State::Low);
    }
    else
    {
        _led.set(Gpio::State::High);
    }
}

uint32_t BatteryMonitoringService::period() const
{
    return 10000;
}
