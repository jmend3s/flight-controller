
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "../services/BatteryMonitoringService.h"

#include "Component.h"
#include "SystemTime.h"

#include "Adc.h"
#include "Gpio.h"

#include <cstdlib>


class Application
{
public:
    Application(GpioSpec& led, AdcSpec& adc)
        : _adc(adc)
        , _led(led, Gpio::Mode::Output)
        , _batteryMonitoringService(_adc, _led)
    {
        _components[0] = &_batteryMonitoringService;
    }

    Component** components()
    {
        return _components;
    }

    uint64_t* storage()
    {
        return _tickStorage;
    }

    size_t count()
    {
        return _count;
    }

    SystemTime& time()
    {
        return _time;
    }

private:
    Adc _adc;
    Gpio _led;

    BatteryMonitoringService _batteryMonitoringService;

    size_t const _count = 1;
    uint64_t _tickStorage[1];
    Component* _components[1];

    SystemTime _time;
};


#endif
