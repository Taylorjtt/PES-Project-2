/*****************************************************************************
* Copyright (C) 2019 by John Taylor
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. John Taylor and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/*
 * @file touch.h
 * @brief simple api for the touch sensor
 *
 *  @author John Taylor 
 * 	@date Sep 19, 2019
 *      
 */

#ifndef SRC_TSS_TOUCH_H_
#define SRC_TSS_TOUCH_H_

#include <stdint.h>
#include "../../board/board.h"
#include "fsl_debug_console.h"
#include "fsl_tsi_v4.h"

#define MIDDLE_SECTION_START -999
#define MIDDLE_SECTION_END 1000

typedef enum {LEFT,MIDDLE,RIGHT}TOUCH_SECTION;

/**
* @brief Function to initialize the capacitive touch sensor
*
* sets up the registers and turns the module on
*
* @return void
*/
void initializeTouch();
/**
* @brief Function to return the difference in values between electrode 2 and 1
*
* the difference represents the pressed position on the touch sensor (leftmost) -3000 to 3000 (rightmost)
*
* @return the difference between the two electrode measurements
*/
int32_t getTouchValue();

/**
* @brief Function to return the touched position on the capacitive sensor
*
* returns LEFT MIDDLE or RIGHT depending on where the capacitive sensor is touched
*
* @return where the sensor is touched
*/
TOUCH_SECTION getSection();

#endif /* SRC_TSS_TOUCH_H_ */
