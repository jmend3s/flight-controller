
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/spi.h>


#define SPI_OP (SPI_OP_MODE_MASTER | \
                SPI_MODE_CPOL | \
                SPI_MODE_CPHA | \
                SPI_WORD_SET(8) | \
                SPI_LINES_SINGLE)

static const spi_dt_spec spiSpec =
    SPI_DT_SPEC_GET(DT_ALIAS(spitest), SPI_OP, 0);

int main()
{
    if (!spi_is_ready_dt(&spiSpec))
    {
        printk("SPI not ready\n");
        return 0;
    }

    uint8_t tx = 0xAA;

    spi_buf txBuf = { &tx, 1 };
    spi_buf_set const txSet = { &txBuf, 1 };

    while (1)
    {
        int ret = spi_write_dt(&spiSpec, &txSet);
        if (ret)
        {
            printk("spi_write failed: %d\n", ret);
        }
        else
            printk("Success: %d\n", ret);

        k_sleep(K_MSEC(1000));
    }
}
