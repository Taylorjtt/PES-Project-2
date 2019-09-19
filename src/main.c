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

typedef struct clock
{
	uint16_t hours;
	uint16_t minutes;
	uint16_t seconds;
};
//define objects
RGBLEDHandle rgbLED;

//variables to keep track of LED status
bool red = true;
bool green = false;
bool blue = false;


#ifdef DB
	bool debug = true;
#else
	bool debug = false;
#endif


float seconds = 0.0f;
float debugDelta = 0.0f;
float lastDebugTime = 0.0f;

int32_t touchOffset = 0;

void printDebug(bool on)
{
	debugDelta = seconds - lastDebugTime;
	lastDebugTime = seconds;

	if(debug)
	{
		if(red)
		{
			PRINTF("RED LED");
		}
		else if (green)
		{
			PRINTF("GREEN LED");
		}
		else if (blue)
		{
			PRINTF("BLUE LED");
		}

		if(on)
		{
			PRINTF(" ON\t%.0f\r\n",debugDelta*1000);
		}
		else
		{
			PRINTF(" OFF\t%.0f\r\n",debugDelta*1000);
		}
	}
}
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

    //set the offset value when the board isn't being touched (hopefully)
    touchOffset = getTouchValue();

    /*
     * The board is running at 48MZ therfore 12000 ticks equals 0.25 millisecond
     */
    SysTick_Config(3000);

    //initialize the RGB LED object
    rgbLED = malloc(sizeof(RGBLEDObject));
    rgbLED = RGBLED_Constructor((void*) rgbLED, sizeof(RGBLEDObject), RED_BASE, RED_PIN, GREEN_BASE, GREEN_PIN, BLUE_BASE, BLUE_PIN);

    // run the process TIMES_TO_RUN times
    for(int i = 0; i < TIMES_TO_RUN; i++)
    {
    	// loop through the timing array
    	for(int j = 0; j < TIMING_ARRAY_SIZE; j++)
    	{
    		//if j is even, turn the LED on
    		if(j % 2 == 0)
    		{
    			RGBLED_set(rgbLED, red, green, blue);
    			printDebug(true);
    		}
    		else
    		{
    			RGBLED_set(rgbLED, false, false, false);
    			printDebug(false);
    		}
    		delay_ms(timing[j]);
    	}
    }



    return 0 ;
}

void SysTick_Handler(void)
{
	//add a quarter of a millisecond to the seconds count
	seconds += 0.000063;
}

