#include <libopencm3/stm32/gpio.h>
#include <stdint.h>
#include <stdbool.h>

enum kit_port {
	PORTA = 0,
	PORTB = 1,
	PORTC = 2,
	PORTD = 3,
	PORTE = 4,
	PORTF = 5,
	PORTG = 6,
	PORTH = 7,
	PORTI = 8,
	PORTJ = 9,
	PORTK = 10
};

struct kit_pin {
	uint16_t port       : 4;
	/** Pin number (0 .. 15) */
	uint16_t pin        : 4;
	/** Set to true if port input or output should be inverted */
	uint16_t isinverse  : 1;
	/** Packing residue reserved for furter use */
	uint16_t __reserved : 7;  // 7 bits left. Reserve them for further use
};


typedef struct kit_pin kit_pin;

inline uint32_t pin_port_to_gpio(enum kit_port port)
{
	// GPIO_PORT_A_BASE (PERIPH_BASE_AHB1 + 0x0000)
	// GPIO_PORT_B_BASE (PERIPH_BASE_AHB1 + 0x0400)
	return GPIO_PORT_A_BASE + (GPIO_PORT_B_BASE - GPIO_PORT_A_BASE) * port;
}

void io_pin_set(kit_pin pin, bool value);
void io_init(kit_pin pin, bool in_out);

// Leds
extern const kit_pin led_orange;
extern const kit_pin led_red;
extern const kit_pin led_green;
extern const kit_pin led_blue;

// buttons
extern const kit_pin btn_usr;
extern const kit_pin btn_right;
extern const kit_pin btn_mid;
extern const kit_pin btn_left;
extern const kit_pin btn_up;
extern const kit_pin btn_down;

// LCD
extern const kit_pin lcd_bkl;
extern const kit_pin lcd_rs;
extern const kit_pin lcd_rw;
extern const kit_pin lcd_en;
