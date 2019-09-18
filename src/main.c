/*
 * main.c
 *
 *  Created on: Sep 18, 2019
 *      Author: jttaylor
 */


#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "LED/RGB.h"
#include <stdlib.h>

#define RED_BASE GPIOB
#define RED_PIN 18U

#define GREEN_BASE GPIOB
#define GREEN_PIN 19U

#define BLUE_BASE GPIOD
#define BLUE_PIN 1U

//define objects
RGBLEDHandle rgbLED;

int main(void)
{
	//initialization
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();

    //initialize the RGB LED object
    rgbLED = malloc(sizeof(RGBLEDObject));
    rgbLED = RGBLED_Constructor((void*) rgbLED, sizeof(RGBLEDObject), RED_BASE, RED_PIN, GREEN_BASE, GREEN_PIN, BLUE_BASE, BLUE_PIN);

    RGBLED_set(rgbLED, true, true, false);

    return 0 ;
}
