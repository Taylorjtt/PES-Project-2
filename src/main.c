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
#include "TSS/touch.h"
#include <stdlib.h>



#define RED_BASE GPIOB
#define RED_PIN 18U

#define GREEN_BASE GPIOB
#define GREEN_PIN 19U

#define BLUE_BASE GPIOD
#define BLUE_PIN 1U

#define TIMING_ARRAY_SIZE 20

//amount of times to run
#define TIMES_TO_RUN 10

//timing array in milliseconds
const uint16_t timing[TIMING_ARRAY_SIZE] = {3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600};


//define objects
RGBLEDHandle rgbLED;

bool red = true;
bool green = false;
bool blue = false;

float seconds = 0.0;
int32_t touchOffset = 0;

void delay_ms(float delayInMilliseconds)
{
	float entryTime = seconds;
	while(seconds - entryTime < delayInMilliseconds/1e3)
	{
		TOUCH_SECTION section = getSection();
		if(section == LEFT)
		{
			red = true;
			green = false;
			blue = false;
		}
		else if (section == MIDDLE)
		{
			red = false;
			green = true;
			blue = false;
		}
		else if (section == RIGHT)
		{
			red = false;
			green = false;
			blue = true;
		}
	}
}
int main(void)
{
	//initialization
    BOARD_InitBootPins();
    BOARD_InitBootClocks();
    BOARD_InitBootPeripherals();
    BOARD_InitDebugConsole();
    initializeTouch();
    touchOffset = getTouchValue();
    /*
     * The board is running at 48MZ therfore 12000 ticks equals 0.25 millisecond
     */
    SysTick_Config(12000);
    PRINTF("HELLO WORLD");

    //initialize the RGB LED object
    rgbLED = malloc(sizeof(RGBLEDObject));
    rgbLED = RGBLED_Constructor((void*) rgbLED, sizeof(RGBLEDObject), RED_BASE, RED_PIN, GREEN_BASE, GREEN_PIN, BLUE_BASE, BLUE_PIN);

    for(int i = 0; i < TIMES_TO_RUN; i++)
    {
    	for(int j = 0; j < TIMING_ARRAY_SIZE; j++)
    	{
    		//if j is even
    		if(j % 2 == 0)
    		{
    			RGBLED_set(rgbLED, red, green, blue);
    		}
    		else
    		{
    			RGBLED_set(rgbLED, false, false, false);
    		}
    		delay_ms(timing[j]);
    	}
    }



    return 0 ;
}

void SysTick_Handler(void)
{
	//add a quarter of a millisecond to the seconds count
	seconds += 0.25e-3;
}

