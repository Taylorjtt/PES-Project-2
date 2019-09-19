/*****************************************************************************
* Copyright (C) 2017 by Alex Fosdick
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. Alex Fosdick and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/*
 * @file touch.h
 * @brief
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

void initializeTouch();
int32_t getTouchValue();
TOUCH_SECTION getSection();

#endif /* SRC_TSS_TOUCH_H_ */
