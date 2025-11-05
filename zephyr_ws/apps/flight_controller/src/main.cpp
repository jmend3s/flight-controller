
#include <zephyr/kernel.h>
#include <zephyr/sys/printk.h>

class FlightController {
public:
    FlightController() { printk("Constructor called!\n"); }
    void loop() { printk("Loop tick\n"); }
};

extern "C" int main(void)
{
    printk("Booting...\n");
    FlightController fc;
    while (true) {
        fc.loop();
        k_msleep(1000);
    }
}
