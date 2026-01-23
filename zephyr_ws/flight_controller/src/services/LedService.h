
#ifndef __LED_SERVICE_H__
#define __LED_SERVICE_H__

#include "Component.h"

#include "Gpio.h"
#include "TimerService.h"


class LedService : public Component
{
public:
    LedService(Gpio const& gpio, TimerService& timer);

    void initialize() override;
    void update() override;
    uint32_t period() const override;

private:
    Gpio& _gpio;
    TimerService& _timer;
};


#endif
