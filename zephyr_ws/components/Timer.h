
#ifndef __TIMER_H__
#define __TIMER_H__

#include <cstdint>

#include "Component.h"


class Timer : public Component
{
public:
    Timer(uint32_t periodMs);

    void initialize();
    void update();

    bool elapsed() const;
    uint32_t period() const;

private:
    uint32_t _periodMs;
    uint64_t _lastTick;
    bool _elapsed;
};

#endif