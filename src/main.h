/*
 * main.h
 *
 *  Created on: Sep 20, 2019
 *      Author: john
 */

#ifndef SRC_MAIN_H_
#define SRC_MAIN_H_

#ifdef FREEDOM
void delay_ms(uint32_t delayInMilliseconds);
void initFreedom(void);
#else
uint32_t getTimeInMicroseconds();
#endif
void printDebug();
void printLEDStatus();


#endif /* SRC_MAIN_H_ */
