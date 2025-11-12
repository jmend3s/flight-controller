#include <zephyr/kernel.h>
#include <stdio.h>
#include <zephyr/usb/usb_device.h>
#include <zephyr/logging/log.h>
#include <zephyr/drivers/gpio.h>

LOG_MODULE_REGISTER(MyApp, LOG_LEVEL_INF);

#define LED_NODE DT_ALIAS(led0)
static const gpio_dt_spec led_spec = GPIO_DT_SPEC_GET(LED_NODE, gpios);

extern "C" int main(void)
{
    printk("\n=== Teensy 4.1 DT-based LED Blink ===\n");

    while (true)
    {
        printk("LED port: %s\n", led_spec.port->name);
        printk("LED pin: %u\n", led_spec.pin);
        printk("LED flags: 0x%x\n", led_spec.dt_flags);
        k_msleep(500);
    }
}
