
#ifndef __BATTERY_MONITORING_SERVICE_H__
#define __BATTERY_MONITORING_SERVICE_H__

#include "Component.h"
#include "Adc.h"
#include "Gpio.h"

#include <cstdint>


class BatteryMonitoringService : public Component
{
public:
    BatteryMonitoringService(Adc& adc, Gpio& led);

    void initialize() override;
    void update() override;
    uint32_t period() const override;

    uint32_t getReading() const;

private:
    Adc& _adc;
    Gpio& _led;
};


#endif
