
#ifndef __PWM_H__
#define __PWM_H__

#include <zephyr/drivers/pwm.h>


class Pwm
{
public:
    Pwm(pwm_dt_spec const& spec);

    bool initialize() const;

    bool setPulseNs(uint32_t pulseNs) const;
    bool setPulseUs(uint32_t pulseUs) const;
    bool setDutyCycle(float duty) const;

    uint32_t periodNs() const;

private:
    pwm_dt_spec _spec;
};


#endif
