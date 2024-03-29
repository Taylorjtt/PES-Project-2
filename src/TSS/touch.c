/*****************************************************************************
* Copyright (C) 2019 John Taylor
*
* Redistribution, modification or use of this software in source or binary
* forms is permitted as long as the files maintain this copyright. Users are
* permitted to modify this and use it to learn about the field of embedded
* software. John Taylor and the University of Colorado are not liable for
* any misuse of this material.
*
*****************************************************************************/
/*
 * @file touch.c
 * @brief implementation of the capacitive touch api
 *
 *  @author John Taylor 
 * 	@date Sep 19, 2019
 *      
 */

#ifndef SRC_TSS_TOUCH_C_
#define SRC_TSS_TOUCH_C_
#include "touch.h"

void initializeTouch()
{
	//configuring the TSI taken directly from example code
	tsi_config_t tsiConfig_normal = {0};
	TSI_GetNormalModeDefaultConfig(&tsiConfig_normal);
	TSI_Init(TSI0, &tsiConfig_normal);
	TSI_EnableModule(TSI0, true); /* Enable module */
    TSI_EnableHardwareTriggerScan(TSI0, false); /* Enable software trigger scan */
    TSI_DisableInterrupts(TSI0, kTSI_EndOfScanInterruptEnable);
    TSI_ClearStatusFlags(TSI0, kTSI_EndOfScanFlag);
    TSI_SetMeasuredChannelNumber(TSI0, BOARD_TSI_ELECTRODE_1);

}
int32_t getTouchValue()
{
	int32_t electrodeOneValue = 0;
	int32_t electrodeTwoValue = 0;

    TSI_ClearStatusFlags(TSI0, kTSI_EndOfScanFlag);
    TSI_SetMeasuredChannelNumber(TSI0, BOARD_TSI_ELECTRODE_1);
    TSI_StartSoftwareTrigger(TSI0);
    while (!(TSI_GetStatusFlags(TSI0) & kTSI_EndOfScanFlag))
    {
    }
    electrodeOneValue = TSI_GetCounter(TSI0);

    TSI_ClearStatusFlags(TSI0, kTSI_EndOfScanFlag);
    TSI_SetMeasuredChannelNumber(TSI0, BOARD_TSI_ELECTRODE_2);
    TSI_StartSoftwareTrigger(TSI0);
    while (!(TSI_GetStatusFlags(TSI0) & kTSI_EndOfScanFlag))
    {
    }
    electrodeTwoValue = TSI_GetCounter(TSI0);
    TSI_ClearStatusFlags(TSI0, kTSI_EndOfScanFlag);
    TSI_ClearStatusFlags(TSI0, kTSI_OutOfRangeFlag);
    return electrodeTwoValue - electrodeOneValue;
}
TOUCH_SECTION getSection()
{
	int32_t value = getTouchValue();

	if(value < MIDDLE_SECTION_START)
	{
		return LEFT;
	}
	if(value > MIDDLE_SECTION_START && value < MIDDLE_SECTION_END)
	{
		return MIDDLE;
	}
	else
	{
		return RIGHT;
	}
}


#endif /* SRC_TSS_TOUCH_C_ */
