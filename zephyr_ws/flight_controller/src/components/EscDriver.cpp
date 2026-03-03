
#include "EscDriver.h"

EscDriver::EscDriver(Pwm& pwm)
    : _pwm(pwm)
{
}

void EscDriver::initialize()
{

}

void EscDriver::update()
{
    switch (_state)
    {
        case State::Disarmed:
            _pwm.setPulseUs(_minPulse);
            break;
        case State::Arming:
            _pwm.setPulseUs(_minPulse);
            _armingCounter++;

            if (_armingCounter >= _armTimeTicks)
            {
                _state = State::Armed;
            }
            break;
        case State::Armed:
            setThrottle(_pendingThrottle);
            break;
        }
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
}

void EscDriver::setThrottle(float normalized)
{
}

bool EscDriver::isArmed()
{
}
