
#ifndef __GPIO_H__
#define __GPIO_H__

#include "Component.h"

#include <zephyr/drivers/gpio.h>


class Gpio : public Component
{
public:
    enum class Mode { Input, Output };
    enum class State { Low, High };

    Gpio(gpio_dt_spec const& spec, Mode mode);

    void initialize() override;
    void update() override;

    void set(State state);
    void toggle();

    State read() const;

private:
    gpio_dt_spec _spec;
    Mode _mode;
    State _state;
};

#endif