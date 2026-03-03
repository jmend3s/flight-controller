
#ifndef __ESC_DRIVER_H__
#define __ESC_DRIVER_H__

#include "Pwm.h"


class EscDriver
{
public:
    enum class State { Disarmed, Arming, Armed };

    EscDriver(Pwm& pwm);

    void initialize();
    void update();
    void arm();
    void disarm();
    void setThrottle(float normalized);
    bool isArmed();

private:
    Pwm& _pwm;

    static uint16_t constexpr _minPulse = 1000;
    static uint16_t constexpr _maxPulse = 2000;
    static uint32_t constexpr _armTimeTicks = 15'000;

    State _state = State::Disarmed;
    uint32_t _armingCounter = 0;
    float _pendingThrottle = 0.0f;
};


#endif
