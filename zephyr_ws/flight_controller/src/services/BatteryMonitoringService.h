
#ifndef __BATTERY_MONITORING_SERVICE_H__
#define __BATTERY_MONITORING_SERVICE_H__

#include "../components/BatterySensor.h"

#include "Component.h"
#include "Adc.h"
#include "Gpio.h"

#include <cstdint>


class BatteryMonitoringService : public Component
{
public:
    enum class BatteryLevel { High, Low, Critical };

    BatteryMonitoringService(Adc& adc, Gpio& greenLed, Gpio& yellowLed, Gpio& redLed);

    void initialize() override;
    void update() override;
    uint32_t period() const override;

private:
    void determineBatteryLevel(uint32_t millivolts);
    void lightLed();

    BatterySensor _sensor;

    Gpio& _greenLed;
    Gpio& _yellowLed;
    Gpio& _redLed;

    BatteryLevel _batteryLevel;

    uint32_t const _lowMillivolts = 10800;
    uint32_t const _criticalMillivolts = 9900;
};


#endif
