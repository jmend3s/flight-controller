
#ifndef __TIMER_SERVICE_H__
#define __TIMER_SERVICE_H__

#include "Component.h"
#include "Timer.h"


class TimerService : public Component
{
public:
    TimerService();

    void initialize() override;
    void update() override;

    bool ms1() const;
    bool ms10() const;
    bool ms20() const;
    bool ms100() const;

private:
    Timer _1ms;
    Timer _10ms;
    Timer _20ms;
    Timer _100ms;
};

#endif