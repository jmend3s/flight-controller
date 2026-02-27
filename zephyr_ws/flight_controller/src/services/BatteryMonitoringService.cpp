
#include "BatteryMonitoringService.h"

#include "SystemPrint.h"


BatteryMonitoringService::BatteryMonitoringService(Adc& adc, Gpio& greenLed, Gpio& yellowLed, Gpio& redLed)
    : _sensor(adc)
    , _greenLed(greenLed)
    , _yellowLed(yellowLed)
    , _redLed(redLed)
{
}

void BatteryMonitoringService::initialize()
{
    _sensor.initialize();
    _greenLed.configure();
    _yellowLed.configure();
    _redLed.configure();
    SystemPrint::print("Battery monitoring service initialized\n");
}

void BatteryMonitoringService::update()
{
    determineBatteryLevel(_sensor.readMillivolts());
    lightLed();
    SystemPrint::print("Last reading: %u mV\n", _sensor.readMillivolts());
}

uint32_t BatteryMonitoringService::period() const
{
    return 10000;
}

void BatteryMonitoringService::determineBatteryLevel(uint32_t const millivolts)
{
    if (millivolts > _lowMillivolts)
    {
        _batteryLevel = BatteryLevel::High;
    }
    else
    {
        if (millivolts > _criticalMillivolts)
        {
            _batteryLevel = BatteryLevel::Low;
        }
        else
        {
            _batteryLevel = BatteryLevel::Critical;
        }
    }
}

void BatteryMonitoringService::lightLed()
{
    switch (_batteryLevel)
    {
        case BatteryLevel::High:
            _greenLed.set(Gpio::State::High);
            _yellowLed.set(Gpio::State::Low);
            _redLed.set(Gpio::State::Low);
            break;
        case BatteryLevel::Low:
            _greenLed.set(Gpio::State::Low);
            _yellowLed.set(Gpio::State::High);
            _redLed.set(Gpio::State::Low);
            break;
        case BatteryLevel::Critical:
            _greenLed.set(Gpio::State::Low);
            _yellowLed.set(Gpio::State::Low);
            _redLed.set(Gpio::State::High);
            break;
    }
}
