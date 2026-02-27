
#include "System.h"
#include "SystemTime.h"
#include "Gpio.h"

#include "application/Application.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>


static constexpr gpio_dt_spec redLedDt = GPIO_DT_SPEC_GET(DT_ALIAS(redled), gpios);
static  GpioSpec redLedSpec(reinterpret_cast<uintptr_t>(&redLedDt));

static constexpr gpio_dt_spec yellowLedDt = GPIO_DT_SPEC_GET(DT_ALIAS(yellowled), gpios);
static  GpioSpec yellowLedSpec(reinterpret_cast<uintptr_t>(&yellowLedDt));

static constexpr gpio_dt_spec greenLedDt = GPIO_DT_SPEC_GET(DT_ALIAS(greenled), gpios);
static  GpioSpec greenLedSpec(reinterpret_cast<uintptr_t>(&greenLedDt));

static constexpr adc_dt_spec adcChannel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));
static AdcSpec adcSpec(reinterpret_cast<uintptr_t>(&adcChannel));

int main()
{
    Application app(adcSpec, greenLedSpec, yellowLedSpec, redLedSpec);
    System system(app.components(), app.storage(), app.count(), app.time());

    system.run();
}
