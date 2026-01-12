
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/spi.h>
#include <zephyr/sys/printk.h>

#define SPI_OP (SPI_OP_MODE_MASTER | \
                SPI_WORD_SET(8) | \
                SPI_LINES_SINGLE)

static const struct spi_dt_spec spiSpec =
    SPI_DT_SPEC_GET(DT_ALIAS(spitest), SPI_OP, 0);

void debug_spi_config(const struct spi_dt_spec *spec)
{
    const struct device *bus = spec->bus;
    struct spi_config config = spec->config;
    
    printk("SPI Config:\n");
    printk("  Bus: %s\n", bus->name);
    printk("  Frequency: %u Hz\n", config.frequency);
    printk("  Operation: 0x%08X\n", config.operation);
    printk("  Slave: %u\n", config.slave);
    
    uint8_t mode = 0;
    if (config.operation & SPI_MODE_CPOL) mode |= 0x02;
    if (config.operation & SPI_MODE_CPHA) mode |= 0x01;
    printk("  SPI Mode: %u\n", mode);
    
    uint8_t word_size = SPI_WORD_SIZE_GET(config.operation);
    printk("  Word size: %u bits\n", word_size);
}

int main()
{
    if (!spi_is_ready_dt(&spiSpec))
    {
        printk("SPI not ready\n");
        return 0;
    }
    
    uint8_t tx = 0xAA;
    uint8_t rx = 0x00;

    struct spi_buf txBuf = { .buf = &tx, .len = 1 };
    struct spi_buf rxBuf = { .buf = &rx, .len = 1 };

    struct spi_buf_set txSet = { .buffers = &txBuf, .count = 1 };
    struct spi_buf_set rxSet = { .buffers = &rxBuf, .count = 1 };

    while (1)
    {
        rx = 0x00;  /* Clear receive buffer */

        int ret = spi_transceive_dt(&spiSpec, &txSet, &rxSet);
        if (ret == 0)
        {
            if (rx == tx)
            {
                printk("SUCCESS: TX=0x%02X RX=0x%02X\n", tx, rx);
            }
            else
            {
                printk("MISMATCH: TX=0x%02X RX=0x%02X\n", tx, rx);
            }
        }
        else
        {
            printk("SPI error: %d\n", ret);
        }

        k_sleep(K_MSEC(1000));
    }
}