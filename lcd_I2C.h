/*******************************************************************************
 * filename: lcd_I2C.h
 *
 * defines the functions neccesary to talk to a LCD screen through I2C
 *
 * written by: James Ross
 ******************************************************************************/
#ifndef _LCD_I2C_H
#define _LCD_I2C_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>

#include "beaglebone.h"
#include "soc_AM335x.h"
#include "hsi2c.h"
#include "clock.h"
#include "delay.h"
#include "dmTimer.h"

/*********************** timer definitions ************************************/
#define TIMER_1MS_COUNT (0x5DC0u)

/************************* I2C definitions ************************************/

#define SLAVE_ADDR_I2C 0x3C    // salve adderss for LCD screen
#define I2C_P9_17_18   0x1     // sets the pinmux on BBB to change 12/18 on rail P9
#define XRDY_BIT	   0x10    // location of XRDY in I2C IRQSTATUSRAW
#define BB_BIT		   0x1000  // bus busy bit found in I2C IRQSTATUSRAW

// I2C clock requirements, Master is processor
#define SYS_CLK 		 48000000 // 48Mhz, current system clock for CPU
#define I2C_INTERNAL_CLK 12000000 // 12Mhz, internal clock used by I2C
#define I2C_OUT_CLK 	 100000   // 100kbs, required I2C bus speed/freq

/************************** LCD definitions ***********************************/
#define MSG_LEN_MAX 21   // [0] = sendtype{data = 0x40 || lcdCmd = 0x0},
					     // length of 1 line on the LCD screen

// message type
#define LCD_DATA    0x40 // sent before a data input to LCD
#define LCD_CMD     0x00 // sent before a command input to LCD

// LCD commands
#define CLR_SCRN     0x01 // command to clear the screen
#define DISP_EN      0x0C // turns on the lcd display, no cursor or underscore
#define DISP_FULL_EN 0x0F // turns on lcd display, cursor and underscore
#define SET_BIAS     0x14 // default bias (1/5).
#define CONTRAST_SET 0x78 // sets contrast 3 in the contrast set command
#define PWR_ICON_HC  0x5E // Sets contrast 5, ICON disp on, BON booster enabled
#define FOLLOWER_CTL 0x6C // Turn on follower circuit. Set amp ratio 2
#define ENTRY_SET    0x06 // sets cursor to move to the rightm ++DRAM
#define FUNC_SET     0x39 // set to 8bit interface data, 1 line, default height,
                          // 01 instruction table

/* Sets up the I2C interface so it can be used to communicate to the LCD screen.
 * The LCD screen is connected to I2C1
 */
void setupLCD_I2C(uint32_t baseAddr);

/* Sends a command to turn on the LCD screen from the I2C base addr provided */
void turnOnLCD(uint32_t baseAddr);

/* sends a string message to the LCD for display */
void sendMsg(uint32_t baseAddr, uint8_t *msg);

/* transmits a string message or command to the LCD display.
 * String will not automatically have the slave ADDR sent first */
void transmit_I2C(uint32_t baseAddr, uint8_t *toSlave, uint32_t transLen);

/* Sends the clear display command to the LCD */
void clearDisplay(uint32_t baseAddr);

/* runs a timer delay */
void runDelay(uint32_t milliSec);

#endif
/*********** EOF **********/
