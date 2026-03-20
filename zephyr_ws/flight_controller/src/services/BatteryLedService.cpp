
#include "BatteryLedService.h"


BatteryLedService::BatteryLedService(IGpio& greenLed, IGpio& yellowLed, IGpio& redLed, BatteryState& state)
    : _greenLed(greenLed)
    , _yellowLed(yellowLed)
    , _redLed(redLed)
    , _state(state)
{
}

void BatteryLedService::initialize()
{
    _greenLed.configure();
    _yellowLed.configure();
    _redLed.configure();
}

void BatteryLedService::update()
{
    lightLed(_state.level);
}

uint32_t BatteryLedService::period() const
{
    return 10000;
}

void BatteryLedService::lightLed(BatteryLevel level)
{
    switch (level)
    {
    case BatteryLevel::Normal:
        _greenLed.set(GpioState::High);
        _yellowLed.set(GpioState::Low);
        _redLed.set(GpioState::Low);
        break;
    case BatteryLevel::Warning:
        _greenLed.set(GpioState::Low);
        _yellowLed.set(GpioState::High);
        _redLed.set(GpioState::Low);
        break;
    case BatteryLevel::Critical:
        _greenLed.set(GpioState::Low);
        _yellowLed.set(GpioState::Low);
        _redLed.set(GpioState::High);
        break;
    }
}