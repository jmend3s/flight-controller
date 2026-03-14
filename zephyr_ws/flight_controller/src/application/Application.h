
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "../services/BatteryMonitoringService.h"
#include "../components/EscDriver.h"

#include "Component.h"
#include "SystemTime.h"

#include "Adc.h"
#include "Gpio.h"
#include "Pwm.h"

#include <cstdlib>


class Application
{
public:
    Application(AdcSpec& adc, GpioSpec& greenLed, GpioSpec& yellowLed, GpioSpec& redLed, PwmSpec& esc1)
        : _adc(adc)
        , _greenLed(greenLed, Gpio::Mode::Output)
        , _yellowLed(yellowLed, Gpio::Mode::Output)
        , _redLed(redLed, Gpio::Mode::Output)
        , _esc1(esc1)
        , _batteryMonitoringService(_adc, _greenLed, _yellowLed, _redLed)
        , _escDriver(_esc1)
    {
        _components[0] = &_batteryMonitoringService;
        _components[1] = &_escDriver;
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
    Pwm _esc1;

    BatteryMonitoringService _batteryMonitoringService;
    EscDriver _escDriver;

    size_t const _count = 2;
    uint64_t _tickStorage[2];
    Component* _components[2];

    SystemTime _time;
};


#endif
