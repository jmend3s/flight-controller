
#ifndef __BATTERY_MONITORING_SERVICE_H__
#define __BATTERY_MONITORING_SERVICE_H__

#include "BatteryState.h"
#include "../modules/BatterySensor.h"
#include "../modules/LowPassFilter.h"

#include "Component.h"
#include "Adc.h"

#include <cstdint>


class BatteryMonitoringService : public Component
{
public:
    BatteryMonitoringService(IAdc& adc, BatteryState& state);

    void initialize() override;
    void update() override;
    uint32_t period() const override;

    BatteryLevel batteryLevel() const;

private:
    void determineBatteryLevel(uint32_t millivolts);

    BatterySensor _sensor;
    BatteryState& _state;
    LowPassFilter _filter;

    BatteryLevel _batteryLevel = BatteryLevel::Normal;

    uint64_t _warningCounter = 0;
    uint64_t _criticalCounter = 0;

    static constexpr uint64_t _warningDebounceSeconds = 3;
    static constexpr uint64_t _criticalDebounceSeconds = 2;

    static constexpr uint32_t _warningEnter = 10800;
    static constexpr uint32_t _criticalEnter = 9900;
};


#endif
