
#include <zephyr/kernel.h>
#include <zephyr/device.h>
#include <zephyr/devicetree.h>
#include <zephyr/drivers/spi.h>


#define SPI_OP  (SPI_OP_MODE_MASTER |SPI_MODE_CPOL | SPI_MODE_CPHA | SPI_WORD_SET(8) | SPI_LINES_SINGLE)
static const struct spi_dt_spec spi_dev = SPI_DT_SPEC_GET(DT_ALIAS(spitest), SPI_OP, 0);


int main()
{

}
