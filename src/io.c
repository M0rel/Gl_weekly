#include "io.h"

const kit_pin led_green  = { .port=PORTD, .pin=12, .isinverse=false };
const kit_pin led_orange = { .port=PORTD, .pin=13, .isinverse=false };
const kit_pin led_red    = { .port=PORTD, .pin=14, .isinverse=false };
const kit_pin led_blue   = { .port=PORTD, .pin=15, .isinverse=false };

// buttons
const kit_pin btn_user   = { .port=PORTA, .pin=0,  .isinverse=false };
const kit_pin btn_right  = { .port=PORTC, .pin=11, .isinverse=true  };
const kit_pin btn_mid    = { .port=PORTA, .pin=15, .isinverse=true  };
const kit_pin btn_left   = { .port=PORTC, .pin=9,  .isinverse=true  };
const kit_pin btn_up     = { .port=PORTC, .pin=6,  .isinverse=true  };
const kit_pin btn_down   = { .port=PORTC, .pin=8,  .isinverse=true  };

// LCD
const kit_pin lcd_bkl    = { .port=PORTE, .pin=9,  .isinverse=false };
const kit_pin lcd_rs     = { .port=PORTE, .pin=7,  .isinverse=false };
const kit_pin lcd_rw     = { .port=PORTE, .pin=10, .isinverse=false };
const kit_pin lcd_en     = { .port=PORTE, .pin=11, .isinverse=false };

//TODO: void io_init(kit_pin pin, bool is_rcc)

/* bool in_out: true -- in, false -- out */
void io_init(kit_pin pin, bool in_out)
{
	//TODO: Refactor pin.pin keys
	uint32_t port = pin_port_to_gpio(pin.port);

	if(in_out)
		gpio_mode_setup(port, GPIO_MODE_INPUT, GPIO_PUPD_NONE, (1 << pin.pin));
	else
		gpio_mode_setup(port, GPIO_MODE_OUTPUT, GPIO_PUPD_NONE, (1 << pin.pin));

	gpio_set_output_options(port, GPIO_OTYPE_PP, GPIO_OSPEED_2MHZ, (1 << pin.pin));
	gpio_set_af(port, 0, (1 << pin.pin));
}

void io_pin_set(kit_pin pin, bool value)
{
	if (value ^ pin.isinverse)
		gpio_set(pin_port_to_gpio(pin.port), (1 << pin.pin));
	else
		gpio_clear(pin_port_to_gpio(pin.port), (1 << pin.pin));
}

void io_pin_toggle(kit_pin pin) 
{
	gpio_toggle(pin_port_to_gpio(pin.port), (1 << pin.pin));
}

bool io_pin_read(kit_pin pin) 
{
	bool val = gpio_port_read(pin_port_to_gpio(pin.port)) & (1 << pin.pin);
	return val ^ pin.isinverse;
}
