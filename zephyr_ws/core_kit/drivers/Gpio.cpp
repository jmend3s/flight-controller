
#include "Gpio.h"

#include <zephyr/drivers/gpio.h>
#include <zephyr/sys/printk.h>


Gpio::Gpio(gpio_dt_spec const& spec, Mode mode)
    : _spec(spec)
    , _mode(mode)
    , _state(State::Low)
{
}

void Gpio::initialize()
{
    if (device_is_ready(_spec.port))
    {
        auto flags = _mode == Mode::Input ? GPIO_INPUT : GPIO_OUTPUT;
        if (gpio_pin_configure_dt(&_spec, flags) != 0)
        {
            printk("[Gpio] Failed to configure %s pin %u\n",
               _spec.port->name, _spec.pin);
        }
    }
    else
    {
        printk("[Gpio] Device not ready: %s\n", _spec.port->name);
    }
}

void Gpio::update()
{
}

void Gpio::set(State const state)
{
    if (_mode == Mode::Output)
    {
        _state = state;
        gpio_pin_set_dt(&_spec, (state == State::High) ? 1 : 0);
    }
}

void Gpio::toggle()
{
    if (_mode == Mode::Output)
    {
        gpio_pin_toggle_dt(&_spec);
        _state = _state == State::Low ? State::High : State::Low;
    }
}

Gpio::State Gpio::read() const
{
    return gpio_pin_get_dt(&_spec) ? State::High : State::Low;
}
