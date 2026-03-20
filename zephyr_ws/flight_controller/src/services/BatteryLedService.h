
#ifndef __BATTERY_LED_SERVICE_H__
#define __BATTERY_LED_SERVICE_H__

#include "Component.h"
#include "IGpio.h"
#include "BatteryMonitoringService.h"


class BatteryLedService : public Component
{
public:
    BatteryLedService(IGpio& greenLed, IGpio& yellowLed, IGpio& redLed, BatteryState& state);

    void initialize() override;
    void update() override;
    uint32_t period() const override;

private:
    void lightLed(BatteryLevel level);

    IGpio& _greenLed;
    IGpio& _yellowLed;
    IGpio& _redLed;

    BatteryState& _state;
};

#endif