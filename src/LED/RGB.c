/*
 * RGB.c
 *
 *  Created on: Sep 17, 2019
 *      Author: jttaylor
 */
#include "RGB.h"


RGBLEDHandle RGBLED_Constructor(void *pmemory, const size_t numbytes, GPIO_Type *redBase, uint32_t redPin,
		GPIO_Type *greenBase, uint32_t greenPin,GPIO_Type *blueBase,uint32_t bluePin)
{
	RGBLEDHandle handle;
	RGBLEDObject *obj;

	if(numbytes < sizeof(RGBLEDHandle))
	{
		return ((RGBLEDHandle)NULL);
	}

	handle = (RGBLEDHandle)pmemory;
	obj = (RGBLEDObject *)handle;

	obj->redBase = redBase;
	obj->redPin = redPin;

	obj->greenBase = greenBase;
	obj->greenPin = greenPin;

	obj->blueBase = blueBase;
	obj->bluePin = bluePin;

	obj->red = false;
	obj->green = false;
	obj->blue = false;

	obj->red_config.pinDirection = kGPIO_DigitalOutput;
	obj->red_config.outputLogic = 1U;
	GPIO_PinInit(obj->redBase, obj->redPin, &(obj->red_config));

	obj->green_config.pinDirection = kGPIO_DigitalOutput;
	obj->green_config.outputLogic = 1U;
	GPIO_PinInit(obj->greenBase, obj->greenPin, &(obj->green_config));

	obj->blue_config.pinDirection = kGPIO_DigitalOutput;
	obj->blue_config.outputLogic = 1U;
	GPIO_PinInit(obj->blueBase, obj->bluePin, &(obj->blue_config));
	return handle;
}

void RGBLED_set(RGBLEDHandle handle, bool red, bool green, bool blue)
{
	RGBLEDObject *obj = (RGBLEDObject *)handle;

	if(!red)
	{
		GPIO_SetPinsOutput(obj->redBase, 1<<obj->redPin);
	}
	else
	{
		GPIO_ClearPinsOutput(obj->redBase, 1<<obj->redPin);
	}
	if(!blue)
	{
		GPIO_SetPinsOutput(obj->blueBase, 1<<obj->bluePin);
	}
	else
	{
		GPIO_ClearPinsOutput(obj->blueBase,1<<obj->bluePin);
	}
	if(!green)
	{
		GPIO_SetPinsOutput(obj->greenBase,1<<obj->greenPin);
	}
	else
	{
		GPIO_ClearPinsOutput(obj->greenBase, 1<< obj->greenPin);
	}
}

