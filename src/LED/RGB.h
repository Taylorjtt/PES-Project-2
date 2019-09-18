/*
 * RGB.h
 *
 *  Created on: Sep 17, 2019
 *      Author: jttaylor
 */

#ifndef LED_RGB_H_
#define LED_RGB_H_

#include <stdbool.h>
#include <stdint.h>
#include "../../CMSIS/MKL25Z4.h"
#include "../../drivers/fsl_gpio.h"

typedef struct RGB_LED_OBJ
{
	uint32_t redPin;
	uint32_t greenPin;
	uint32_t bluePin;

	GPIO_Type *redBase;
	GPIO_Type *greenBase;
	GPIO_Type *blueBase;

	gpio_pin_config_t red_config;
	gpio_pin_config_t green_config;
	gpio_pin_config_t blue_config;

	bool red;
	bool green;
	bool blue;
}RGBLEDObject;

typedef struct RGB_LED_OBJ *RGBLEDHandle;


RGBLEDHandle RGBLED_Constructor(void *pmemory, const size_t numbytes, GPIO_Type *redBase, uint32_t redPin,
		GPIO_Type *greenBase, uint32_t greenPin,GPIO_Type *blueBase,uint32_t bluePin);

void RGBLED_set(RGBLEDHandle handle, bool red, bool green, bool blue);
#endif /* LED_RGB_H_ */
