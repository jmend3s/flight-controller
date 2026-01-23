
#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>
#include <zephyr/sys/printk.h>

#include "Adc.h"


static constexpr adc_dt_spec adcChannel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));
static AdcSpec adcSpec(reinterpret_cast<uintptr_t>(&adcChannel));

int main()
{

    while (true)
    {
        k_sleep(K_MSEC(1000));
    }
}