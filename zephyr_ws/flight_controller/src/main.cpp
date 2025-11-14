
#include "Application.h"
#include "Gpio.h"

#include <zephyr/kernel.h>
#include <zephyr/usb/usb_device.h>
#include <zephyr/drivers/gpio.h>


extern "C" int main(void)
{
    printk("\n=== Teensy 4.1 DT-based LED Blink ===\n");

    gpio_dt_spec constexpr ledSpec = GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios);
    gpio_dt_spec constexpr externalLedSpec = GPIO_DT_SPEC_GET(DT_ALIAS(led1), gpios);

    Gpio led(ledSpec, Gpio::Mode::Output);
    Gpio externalLed(externalLedSpec, Gpio::Mode::Output);

    Application application;

    application.add(led);
    application.add(externalLed);
    application.initialize();

    while (true)
    {
        externalLed.toggle();
        led.toggle();
        k_msleep(1500);
    }
}
