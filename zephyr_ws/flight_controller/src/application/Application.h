
#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "BatteryMonitoringService.h"
#include "BatteryLedService.h"
#include "EscDriver.h"

#include "imu/Mpu6050.h"
#include "ImuService.h"

#include "Component.h"
#include "TimeSource.h"

#include "Adc.h"
#include "Gpio.h"
#include "I2c.h"
#include "Pwm.h"

#include <cstdlib>


class Application
{
public:
    Application(AdcSpec& adc, GpioSpec& greenLed, GpioSpec& yellowLed, GpioSpec& redLed, I2cSpec& imuSpec, PwmSpec& esc1)
        : _adc(adc)
        , _greenLed(greenLed, GpioMode::Output)
        , _yellowLed(yellowLed, GpioMode::Output)
        , _redLed(redLed, GpioMode::Output)
        , _imuI2c(imuSpec)
        , _esc1(esc1)
        , _batteryMonitoringService(_adc, _state)
        , _batteryLedService(_greenLed, _yellowLed, _redLed, _state)
        , _mpu6050(_imuI2c)
        , _mpu6050Service(_mpu6050)
        , _escDriver(_esc1)
    {
        _components[0] = &_batteryMonitoringService;
        _components[1] = &_batteryLedService;
        _components[2] = &_mpu6050Service;
        _components[3] = &_escDriver;
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

    TimeSource& time()
    {
        return _time;
    }

private:
    Adc _adc;
    Gpio _greenLed;
    Gpio _yellowLed;
    Gpio _redLed;
    I2c _imuI2c;
    Pwm _esc1;

    BatteryMonitoringService _batteryMonitoringService;
    BatteryLedService _batteryLedService;
    BatteryState _state;

    Mpu6050 _mpu6050;
    ImuService _mpu6050Service;

    EscDriver _escDriver;

    size_t const _count = 4;
    uint64_t _tickStorage[4];
    Component* _components[4];

    TimeSource _time;
};


#endif
