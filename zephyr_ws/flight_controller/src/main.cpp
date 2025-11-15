
#include "Application.h"
#include "Gpio.h"
#include "Timer.h"

#include <zephyr/kernel.h>
#include <zephyr/usb/usb_device.h>
#include <zephyr/drivers/gpio.h>


extern "C" int main(void)
{
    printk("\n=== Teensy 4.1 DT-based LED Blink ===\n");

    Gpio led(GPIO_DT_SPEC_GET(DT_ALIAS(led0), gpios), Gpio::Mode::Output);
    Gpio externalLed(GPIO_DT_SPEC_GET(DT_ALIAS(led1), gpios), Gpio::Mode::Output);

    Timer timer(2000);

    Application application;

    application.add(led);
    application.add(externalLed);
    application.add(timer);
    application.initialize();

    while (true)
    {
        application.update();
        if (timer.elapsed())
        {
            externalLed.toggle();
            led.toggle();
        }
        // k_sleep(K_SECONDS(1));
    }
}
