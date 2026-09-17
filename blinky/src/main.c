/*
 * Copyright (c) 2016 Intel Corporation
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <stdio.h>
#include <zephyr/kernel.h>
#include <zephyr/drivers/gpio.h>

/* The devicetree node identifier for our custom LED alias. */
#define LED0_NODE DT_ALIAS(led5180)

/* The devicetree node identifier for the board's default button alias (sw0). */
#define BUTTON0_NODE DT_ALIAS(button5180)

static const struct gpio_dt_spec led = GPIO_DT_SPEC_GET(LED0_NODE, gpios);
static const struct gpio_dt_spec button = GPIO_DT_SPEC_GET(BUTTON0_NODE, gpios);

int main(void)
{
	int ret;
	bool led_state = false;
	int last_button_state = 0;

	if (!gpio_is_ready_dt(&led)) {
		return 0;
	}
	if (!gpio_is_ready_dt(&button)) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&led, GPIO_OUTPUT_INACTIVE);
	if (ret < 0) {
		return 0;
	}

	ret = gpio_pin_configure_dt(&button, GPIO_INPUT);
	if (ret < 0) {
		return 0;
	}

	while (1) {
		int button_state = gpio_pin_get_dt(&button);

		if (button_state && !last_button_state) {
			led_state = !led_state;
			gpio_pin_set_dt(&led, (int)led_state);
			printf("Button pressed - LED state: %s\n", led_state ? "ON" : "OFF");
		}

		last_button_state = button_state;
		k_msleep(50);
	}
	return 0;
}
