
#include "Pwm.h"

Pwm::Pwm(pwm_dt_spec const& spec)
    : _spec(spec)
{
}

bool Pwm::initialize() const
{
    bool initialized = false;
    if (pwm_is_ready_dt(&_spec))
    {
        initialized = true;
    }

    return initialized;
}

bool Pwm::setPulseNs(uint32_t const pulseNs) const
{
    auto const error = pwm_set_dt(&_spec, _spec.period, pulseNs);
    return error == 0;
}

bool Pwm::setPulseUs(uint32_t const pulseUs) const
{
    uint32_t const pulseNs = pulseUs * 1000U;
    return setPulseNs(pulseNs);
}

bool Pwm::setDutyCycle(float duty) const
{
    if (duty < 0.0f)
    {
        duty = 0.0f;
    }
    else if (duty > 1.0f)
    {
        duty = 1.0f;
    }

    auto const temp = duty * static_cast<float>(_spec.period);
    auto const pulseNs = static_cast<uint32_t>(temp);

    return setPulseNs(pulseNs);
}

uint32_t Pwm::periodNs() const
{
    return _spec.period;
}
