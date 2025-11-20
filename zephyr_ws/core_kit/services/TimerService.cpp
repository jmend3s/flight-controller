
#include "TimerService.h"

TimerService::TimerService()
    : _1ms(1)
    , _10ms(10)
    , _20ms(20)
    , _100ms(100)
{
}

void TimerService::initialize()
{
    _1ms.initialize();
    _10ms.initialize();
    _20ms.initialize();
    _100ms.initialize();
}

void TimerService::update()
{
    _1ms.update();
    _10ms.update();
    _20ms.update();
    _100ms.update();
}

bool TimerService::ms1() const
{
    return _1ms.elapsed();
}

bool TimerService::ms10() const
{
    return _10ms.elapsed();
}

bool TimerService::ms20() const
{
    return _20ms.elapsed();
}

bool TimerService::ms100() const
{
    return _100ms.elapsed();
}
