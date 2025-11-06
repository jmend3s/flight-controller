
#include "Gpio.h"

#include <zephyr/sys/printk.h>
#include <zephyr/drivers/gpio.h>


Gpio::Gpio(char const* deviceLabel, uint32_t pin, Direction direction, Pull pull)
    : _device(nullptr)
    , _deviceLabel(deviceLabel)
    , _pin(pin)
    , _direction(direction)
    , _pull(pull)
    , _state(State::Low)
{
}

void Gpio::initialize()
{
    _device = device_get_binding(_deviceLabel);
    if (_device)
    {
        uint32_t flags = 0;
        flags |= _direction == Direction::Output ? GPIO_OUTPUT_INACTIVE : GPIO_INPUT;

        if (_pull != Pull::None)
        {
            flags |= _pull == Pull::Down ? GPIO_PULL_DOWN : GPIO_PULL_UP;
        }

        if (gpio_pin_configure(_device, _pin, flags) != 0)
        {
            printk("[Gpio] Failed to configure pin %d\n", static_cast<int>(_pin));
        }
    }
    else
    {
        printk("[Gpio] Cannot find device %s\n", _deviceLabel);
    }
}

void Gpio::update()
{
}

void Gpio::set(State state)
{
    if (_device)
    {
        _state = state;
        gpio_pin_set(_device, _pin, static_cast<bool>(state));
    }
}

void Gpio::toggle()
{
    if (_device)
    {
        _state = _state == State::Low ? State::High : State::Low;
        gpio_pin_set(_device, _pin, static_cast<bool>(_state));
    }
}

Gpio::State Gpio::read() const
{
    auto state= State::Low;
    if (_device)
    {
        state = gpio_pin_get(_device, _pin) ? State::High : State::Low;
    }

    return state;
}
