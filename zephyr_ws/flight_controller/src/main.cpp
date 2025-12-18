
#include <zephyr/kernel.h>
#include <zephyr/drivers/adc.h>

static const adc_dt_spec adcChannel = ADC_DT_SPEC_GET(DT_PATH(zephyr_user));

int main()
{
    adc_is_ready_dt(&adcChannel);
    adc_channel_setup_dt(&adcChannel);

    int16_t buf = 0;
    adc_sequence sequence
    {
        .buffer = &buf,
        .buffer_size = sizeof(buf)
    };

    adc_sequence_init_dt(&adcChannel, &sequence);

    while (1)
    {
        adc_read_dt(&adcChannel, &sequence);
        int32_t const value = buf;
        printk("value = %ld\n", value);
        k_sleep(K_MSEC(500));
    }
}
