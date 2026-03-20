
#include "BatteryMonitoringService.h"

#include "Printer.h"


BatteryMonitoringService::BatteryMonitoringService(IAdc& adc, BatteryState& state)
    : _sensor(adc)
    , _state(state)
{
}

void BatteryMonitoringService::initialize()
{
    _sensor.initialize();
    _state.level = _batteryLevel;
}

void BatteryMonitoringService::update()
{
    auto const raw = _sensor.readMillivolts();
    auto const filtered = _filter.filter(raw);

    determineBatteryLevel(filtered);

    _state.voltage = filtered;
    _state.level = _batteryLevel;
}

uint32_t BatteryMonitoringService::period() const
{
    return 10000;
}

BatteryLevel BatteryMonitoringService::batteryLevel() const
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
            }
            else
            {
                _warningCounter = 0;
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
                _criticalCounter = 0;
            }
            break;
        }
        case BatteryLevel::Critical:
        {
             break;
        }

    }
}
