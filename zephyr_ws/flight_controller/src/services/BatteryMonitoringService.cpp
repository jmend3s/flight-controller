
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
    auto const raw = _sensor.readMillivolts();
    auto const filtered = _filter.filter(raw);

    determineBatteryLevel(filtered);
    lightLed();

    SystemPrint::print("Last reading: %u mV\n", _sensor.readMillivolts());
}

uint32_t BatteryMonitoringService::period() const
{
    return 10000;
}

BatteryMonitoringService::BatteryLevel BatteryMonitoringService::batteryLevel() const
{
    return _batteryLevel;
}

void BatteryMonitoringService::determineBatteryLevel(uint32_t const millivolts)
{
    switch (_batteryLevel)
    {
        case BatteryLevel::Normal:
        {
            if (millivolts < _warningEnter)
            {
                _warningCounter++;
                if (_warningCounter >= _warningDebounceSeconds)
                {
                    _batteryLevel = BatteryLevel::Warning;
                    _warningCounter = 0;
                }
                else
                {
                    _warningCounter = 0;
                }
            }
                break;
        }
        case BatteryLevel::Warning:
        {
            if (millivolts < _criticalEnter)
            {
                _criticalCounter++;
                if (_criticalCounter >= _criticalDebounceSeconds)
                {
                    _batteryLevel = BatteryLevel::Critical;
                    _criticalCounter = 0;
                }
            }
            else
            {
                if (millivolts > _warningExit)
                {
                    _batteryLevel = BatteryLevel::Normal;
                    _warningCounter = 0;
                }
                else
                {
                    _criticalCounter = 0;
                }
            }
            break;
        }
        case BatteryLevel::Critical:
        {
            if (millivolts < _criticalExit)
            {
                _batteryLevel = BatteryLevel::Warning;
            }
            break;
        }

    }
}

void BatteryMonitoringService::lightLed()
{
    switch (_batteryLevel)
    {
        case BatteryLevel::Normal:
            _greenLed.set(Gpio::State::High);
            _yellowLed.set(Gpio::State::Low);
            _redLed.set(Gpio::State::Low);
            break;
        case BatteryLevel::Warning:
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
