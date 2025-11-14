
#include "Timer.h"

#include <zephyr/kernel.h>


Timer::Timer(uint32_t const periodMs)
    : _periodMs(periodMs)
    , _lastTick(0)
    , _elapsed(false)
{
}

void Timer::initialize()
{
    _lastTick = k_uptime_get();
    _elapsed = false;
}

void Timer::update()
{
    auto const now = k_uptime_get();
    if (now - _lastTick >= _periodMs)
    {
        _lastTick = now;
        _elapsed = true;
    }
    else
    {
        _elapsed = false;
    }
}

bool Timer::elapsed() const
{
    return _elapsed;
}

uint32_t Timer::period() const
{
    return _periodMs;
}
