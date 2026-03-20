
#include "../../corekit/runtime/System.h"
#include "../../corekit/time/TimeSource.h"
#include "Gpio.h"

#include "application/Application.h"

#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/drivers/gpio.h>
#include <zephyr/drivers/pwm.h>

static constexpr gpio_dt_spec redLedDt = GPIO_DT_SPEC_GET(DT_ALIAS(redled), gpios);
static  GpioSpec redLedSpec(reinterpret_cast<uintptr_t>(&redLedDt));

static constexpr gpio_dt_spec yellowLedDt = GPIO_DT_SPEC_GET(DT_ALIAS(yellowled), gpios);
static  GpioSpec yellowLedSpec(reinterpret_cast<uintptr_t>(&yellowLedDt));

static constexpr gpio_dt_spec greenLedDt = GPIO_DT_SPEC_GET(DT_ALIAS(greenled), gpios);
static  GpioSpec greenLedSpec(reinterpret_cast<uintptr_t>(&greenLedDt));

static constexpr adc_dt_spec adcChannel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));
static AdcSpec adcSpec(reinterpret_cast<uintptr_t>(&adcChannel));

static constexpr pwm_dt_spec pwmLedSpec = PWM_DT_SPEC_GET(DT_ALIAS(pwm_led0));
static PwmSpec ledSpec(reinterpret_cast<uintptr_t>(&pwmLedSpec));

int main()
{
    Application app(adcSpec, greenLedSpec, yellowLedSpec, redLedSpec, ledSpec);
    System system(app.components(), app.storage(), app.count(), app.time());

    system.run();
}
