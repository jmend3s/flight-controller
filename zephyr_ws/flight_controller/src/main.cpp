#include <zephyr/kernel.h>
#include <stdio.h>
#include <zephyr/usb/usb_device.h>
#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(MyApp, LOG_LEVEL_INF);

#include <zephyr/drivers/gpio.h>

extern "C" int main(void)
{
    printk("Starting application");
    printk("Application started successfully!\n");
    k_sleep(K_SECONDS(1));

    printk("configuring pin\n");
    k_sleep(K_SECONDS(2));
    const struct device* dev = device_get_binding("GPIO_1");
    printk("pin configured\n");
    gpio_pin_configure(dev, 13, GPIO_OUTPUT);

    k_sleep(K_SECONDS(5));

    while (1)
    {
        printk("loop\n");
        printk("Heartbeat: %s\n", dev->name);
        k_sleep(K_SECONDS(1));
    }
}
