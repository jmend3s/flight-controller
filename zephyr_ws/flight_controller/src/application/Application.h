
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Component.h"
#include "SystemTime.h"

#include "../services/BatteryMonitoringService.h"

#include <cstdlib>


class Application
{
public:
    Application(AdcSpec adcSpec)
        : _adcInstance(adcSpec)
        , _batteryMonitoringService(_adcInstance)
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
    Adc _adcInstance;
    BatteryMonitoringService _batteryMonitoringService;

    size_t _count = 1;
    uint64_t _tickStorage[1];
    Component* _components[1];
    SystemTime _time;
};


#endif
