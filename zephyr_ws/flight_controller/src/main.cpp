
#include <Adc.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>

static constexpr adc_dt_spec adcChannel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));

int main()
{

    Adc adc(adcChannel);
    adc.initialize();

    while (1)
    {
        adc.read();
        int32_t const value = adc.lastReading();
        printk("value = %ld\n", value);
        k_sleep(K_MSEC(500));
    }
}
