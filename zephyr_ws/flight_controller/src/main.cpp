
#include "System.h"
#include "SystemTime.h"
#include "Gpio.h"

#include "application/Application.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>


static constexpr gpio_dt_spec ledDt = GPIO_DT_SPEC_GET(DT_ALIAS(gpioled0), gpios);
static  GpioSpec ledSpec(reinterpret_cast<uintptr_t>(&ledDt));

static constexpr adc_dt_spec adcChannel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));
static AdcSpec adcSpec(reinterpret_cast<uintptr_t>(&adcChannel));

int main()
{
    Application app(ledSpec, adcSpec);
    System system(app.components(), app.storage(), app.count(), app.time());

    system.run();
}
