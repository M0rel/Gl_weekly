#include "io.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    rcc_periph_clock_enable(RCC_GPIOD);
	io_init(led_green,false);
	io_pin_set(led_green, true);

    while (1) {
    }
}
