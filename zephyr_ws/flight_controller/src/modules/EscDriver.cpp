
#include "EscDriver.h"

EscDriver::EscDriver(IPwm& pwm)
    : _pwm(pwm)
{
}

void EscDriver::initialize()
{
    disarm();
}

void EscDriver::update()
{
    uint16_t pulse = _minPulse;

    switch (_state)
    {
    case State::Disarmed:
        pulse = _minPulse;
        break;

    case State::Arming:
        pulse = _minPulse;
        _armingCounter++;

        if (_armingCounter >= _armTimeTicks)
        {
            _state = State::Armed;
        }
        break;

    case State::Armed:
        pulse = _minPulse +
            static_cast<uint16_t>(_pendingThrottle *
            (_maxPulse - _minPulse));
        break;
    }

    _pwm.setPulseUs(pulse);
}

uint32_t EscDriver::period() const
{
    return 1;
}

void EscDriver::arm()
{
    if (_state == State::Disarmed)
    {
        _state = State::Arming;
        _armingCounter = 0;
        _pwm.setPulseUs(_minPulse);
    }
}

void EscDriver::disarm()
{
    _state = State::Disarmed;
    _pendingThrottle = 0.0f;
    _armingCounter = 0;

    _pwm.setPulseUs(_minPulse);
}

void EscDriver::setThrottle(float value)
{
    if (value < 0.0f)
    {
        value = 0.0f;
    }
    if (value > 1.0f)
    {
        value = 1.0f;
    }

    _pendingThrottle = value;
}

bool EscDriver::isArmed() const
{
    return _state == State::Armed;
}
