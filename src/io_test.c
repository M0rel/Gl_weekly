#include "io.h"
#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

void softdelay(volatile uint32_t N)
{
    while (N--);
    // or: while (N--) __asm__("nop");
}

int main(void)
{
    rcc_periph_clock_enable(RCC_GPIOD);

	io_init(led_green,false);
	io_init(led_orange,false);
	io_init(led_red,false);
	io_init(led_blue,false);

	io_pin_set(led_green, true);

    while (1) {
		io_pin_toggle(led_green);
		softdelay(400000);
		io_pin_toggle(led_orange);
		softdelay(400000);
		io_pin_toggle(led_red);
		softdelay(400000);
		io_pin_toggle(led_blue);
		softdelay(400000);
    }
}
