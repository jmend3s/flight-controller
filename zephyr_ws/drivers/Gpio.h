
#ifndef __GPIO_H__
#define __GPIO_H__

#include "Component.h"

#include <zephyr/device.h>

#include <cstdint>


class Gpio : public Component
{
public:
    enum class Direction { Input, Output };
    enum class Pull { None, Down, Up };
    enum class State { Low, High };

    Gpio(char const* deviceLabel, uint32_t pin, Direction direction, Pull pull = Pull::None);

    void initialize() override;
    void update() override;

    void set(State state);
    void toggle();

    State read() const;

private:
    device const* _device;
    char const* _deviceLabel;
    uint32_t _pin;
    Direction _direction;
    Pull _pull;
    State _state;
};

#endif