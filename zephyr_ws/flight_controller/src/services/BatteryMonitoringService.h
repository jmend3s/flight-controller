
#ifndef __BATTERY_MONITORING_SERVICE_H__
#define __BATTERY_MONITORING_SERVICE_H__

#include "../components/BatterySensor.h"
#include "../components/LowPassFilter.h"

#include "Component.h"
#include "Adc.h"
#include "Gpio.h"

#include <cstdint>


class BatteryMonitoringService : public Component
{
public:
    enum class BatteryLevel { Normal, Warning, Critical };

    BatteryMonitoringService(Adc& adc, Gpio& greenLed, Gpio& yellowLed, Gpio& redLed);

    void initialize() override;
    void update() override;
    uint32_t period() const override;

    BatteryLevel batteryLevel() const;

private:
    void determineBatteryLevel(uint32_t millivolts);
    void lightLed(); // Needs to get out

    BatterySensor _sensor;
    LowPassFilter _filter;

    Gpio& _greenLed;
    Gpio& _yellowLed;
    Gpio& _redLed;

    BatteryLevel _batteryLevel = BatteryLevel::Normal;

    uint64_t _warningCounter = 0;
    uint64_t _criticalCounter = 0;

    static constexpr uint64_t _warningDebounceSeconds = 3;
    static constexpr uint64_t _criticalDebounceSeconds = 2;

    static constexpr uint32_t _warningEnter = 10800;
    static constexpr uint32_t _warningExit = 11000;
    static constexpr uint32_t _criticalEnter = 9900;
    static constexpr uint32_t _criticalExit = 10200;
};


#endif
