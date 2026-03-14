
#ifndef __ESC_DRIVER_H__
#define __ESC_DRIVER_H__

#include "Component.h"
#include "Pwm.h"


class EscDriver : public Component
{
public:
    enum class State { Disarmed, Arming, Armed };

    EscDriver(Pwm& pwm);

    void initialize() override;
    void update() override;
    uint32_t period() const override;
    void arm();
    void disarm();
    void setThrottle(float value);
    bool isArmed() const;

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
