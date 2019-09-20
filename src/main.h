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
 * @file main.c
 * @brief Main header file for PES project 2
 *
 *  @author John Taylor
 * 	@date Sep 20, 2019
 *
 */
#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#ifdef FREEDOM
/**
* @brief Function to delay for a specified number of milliseconds on the Freedom board
* and update the LED based on the slider
*
*
* @param delayInMilliseconds	the delay, in ms
*
* @return void
*/
void delay_ms(uint32_t delayInMilliseconds);
/**
* @brief initializes the freedom board for Project 2
*
* @return void
*/
void initFreedom(void);
#else
/**
* @brief gets the system time in microseconds
*
* @return system time in microseconds
*/
uint32_t getTimeInMicroseconds();
#endif
/**
* @brief helper function to print debug information for both the
* freedom and pc application of Project 2
*
* @return void
*/
void printDebug();
/**
* @brief helper function to print LED status information for both the
* freedom and pc application of Project 2
*
* @return void
*/
void printLEDStatus();


#endif /* SRC_MAIN_H_ */
