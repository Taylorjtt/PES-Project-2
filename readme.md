# Project 2
**John Taylor**

## Build Notes 
This project runs on both the *FRDM-KL25Z* development board as well as on *Ubuntu 18.04.3 LTS (Bionic Beaver)*.
There are several make targets that accomplish slightly different goals. All of the make targets can be run directly from the MCUExpresso IDE

## General
All of the make targets create a program that flashes a physical or virtual LED in the following on/off timing pattern


**[3000,1000,2000,600,1000,400,1000,200,500,100,500,100,500,100,1000,200,1000,400,2000,600]**

 where the numbers represent milliseconds between next on or off event.

## fb_run
This version runs natively on the *FRDM-KL25Z*. It flashes the hardware LED on the board in the timing pattern given above. It cycles through the timing pattern 10 times.

If the capacitive touch slider is pressed during program execution then the LED color changes accordingly

Left - Red
Center - Green
Right - Blue

If the capacitive touch slider is not pressed, the color defaults to green
## fb_debug
This version performs all of the same functions as **fb_run** but it also prints debug information to the UART
These messages include the current command LED GREEN ON or LED BLUE OFF, for example, along with a timestamp and the elapsed time since the last command. Individual output debug lines will look like this:
LED GREEN ON 14:22:17 973

## pc_run
This version of the code generally runs the same as the **fb_run** version except that it runs on *Ubuntu 18.04.3 LTS (Bionic Beaver)*. 

In this version of the program, instead of toggling the LED on and off, the program sends the text LED GREEN ON or LED BLUE OFF as an alternative to triggering the LED on the Freedom board. This is  done in the same code modules that run on the Freedom board.

The color of the LED is changed after every three on and off cycles.

## pc_debug
This version of the code generally runs the same as the **pc_run** version. This version of the program sends  debug print lines to the debug console as above which look like this: 
LED GREEN ON 14:22:17 973
