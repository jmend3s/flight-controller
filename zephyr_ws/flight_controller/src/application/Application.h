
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
    Application(AdcSpec& adc, GpioSpec& greenLed, GpioSpec& yellowLed, GpioSpec& redLed)
        : _adc(adc)
        , _greenLed(greenLed, Gpio::Mode::Output)
        , _yellowLed(yellowLed, Gpio::Mode::Output)
        , _redLed(redLed, Gpio::Mode::Output)
        , _batteryMonitoringService(_adc, _greenLed, _yellowLed, _redLed)
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
    Gpio _greenLed;
    Gpio _yellowLed;
    Gpio _redLed;

    BatteryMonitoringService _batteryMonitoringService;

    size_t const _count = 1;
    uint64_t _tickStorage[1];
    Component* _components[1];

    SystemTime _time;
};


#endif
