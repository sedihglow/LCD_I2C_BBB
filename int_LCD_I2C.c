/*
 * I2CLCD.c
 *
 *  Created on: Feb 25, 2016
 *      Author: Prasad Pandit
 */

/**
 * \file   i2clcd.c
 *
 * \brief  This application invokes APIs of HSI2C to control NHD LCD.
 *         It displays the text data by accessing the data array and 
 *         forwarding the ascii data to LCD over I2C interface.
 *
 *         Application configuration:
 *
 *             Modules Used:
 *                 I2C1
 *                 Interrupt Controller
 *
 *             Configurable Parameters:
 *                 None.
 *
 *             Hard-coded configuration of other parameters:
 *                 Bus frequency   - 100kHz
 *                 Addressing mode - 7bit
 *                 I2C Instances   - 1
 *                 Slave Address   - 0x78 (It will be 0x3c due to 7 bit addressing mode and right shift)
 *
 *         Application Usecase:
 *         1. I2C controller will be configured in master mode.
 *         2. Master will configure the NHD-C0220BiZ
 *            by writing configuration values to LCD's registers.
 *         3. Master will read the array value from sensor and
 *            displays on the console.
 *
 *         Running the example:
 *         1. On executing the example application depending on commands you give
 *            the ascii data in array will be displayed on LCD.
 *         2. You can add functions by clubbing the commands ex. scrolling,
 *			  moving text on button press etc.
 *
 */

/*
* Copyright (C) 2010 Texas Instruments Incorporated - http://www.ti.com/
*/
/*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*    Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*
*    Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in the
*    documentation and/or other materials provided with the
*    distribution.
*
*    Neither the name of Texas Instruments Incorporated nor the names of
*    its contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*/

#include "int_LCD_I2C.h"

/******************************************************************************
**              INTERNAL FUNCTION PROTOTYPES
******************************************************************************/
void I2CIsr(void); // interupt service routine
static void initLCD(uint32_t baseAddr);  // initializes the LCD screen
static void SetupI2C(uint32_t baseAddr);
static void intcConfigureI2C(void (*isr_ptr)(void));
static void cleanupInterrupts(uint32_t baseAddr);
static void SetupI2CTransmit(uint32_t baseAddr, unsigned int dcount);
static void nextLine(uint32_t baseAddr);
static void sendText(uint32_t baseAddr, uint8_t *text, uint8_t count);
static void clearDisplay(uint32_t baseAddr);

//static void SetupI2CReception(unsigned int dcount);

/******************************************************************************
**              GLOBAL VARIABLE DEFINITIONS
******************************************************************************/
//volatile unsigned char dataFromSlave[2];
volatile unsigned char dataToSlave[21];
volatile unsigned int numOfBytes;
volatile unsigned int flag = 1;
volatile unsigned int tCount;
//volatile unsigned int rCount;

/*******************************************************************************
 * 				GENERAL #DEFINES
 ******************************************************************************/// messeges
#define MSG_OPEN "Hello!"
#define MSG_L1   "James Ross."
#define MSG_L2   "Indeed."

// message lengths (only valid if not altered. strLen is appropriate get these)
#define MSG_OPEN_LEN  6
#define MSG_L1_LEN    11
#define MSG_L2_LEN    7

/******************************************************************************
**              FUNCTION DEFINITIONS
******************************************************************************/

int main(void)
{
    /* Enable IRQ in CPSR */
    IntMasterIRQEnable();

    /* Configures AINTC to generate interrupt */
    intcConfigureI2C(I2CIsr);

    // set timer 7 settings and enable clock
    DelayTimerSetup();

    /*
    ** Configures HSI2C to Master mode to generate start
    ** condition on HSI2C bus and to transmit data at a
    ** speed of 100khz
    */
    SetupI2C(SOC_I2C_1_REGS);

    // sets the LCD settings and turns it on
    initLCD(SOC_I2C_1_REGS);

    // opening message
    sendText(SOC_I2C_1_REGS, MSG_OPEN, MSG_OPEN_LEN);
	delay(1000);

    while(true){
    	clearDisplay(SOC_I2C_1_REGS);
    	delay(1000); // blink time
    	sendText(SOC_I2C_1_REGS, MSG_L1,MSG_L1_LEN);
    	delay(1000);
    	nextLine(SOC_I2C_1_REGS);
    	sendText(SOC_I2C_1_REGS, MSG_L2,MSG_L2_LEN);
    	delay(3000);
    }
}// end main

static void nextLine(uint32_t baseAddr)
{
	tCount = 0;
	dataToSlave[0] = LCD_CMD;
	dataToSlave[1] = NXT_LN;
	/* set DDRAM aDdress command, sets cursor to the next
     * vertical line on the screen. The Address of the second
     * line is 0x40, the 0x80 bit lets the LCD screen know the
     * command is Set DDRAM Address */
	SetupI2CTransmit(baseAddr, 2);
}// end nextLine

static void clearDisplay(uint32_t baseAddr)
{
	tCount = 0;
	dataToSlave[0] = LCD_CMD;
	dataToSlave[1] = CLR_SCRN;
	SetupI2CTransmit(baseAddr, 2);
	delay(1);
}// end cleardisplay

static void sendText(uint32_t baseAddr, uint8_t *text, uint8_t count){
	uint8_t i = 0;
	tCount = 0;
	dataToSlave[0] = LCD_DATA;

	while(i != count){
		dataToSlave[i+1]=text[i];
		++i;
	}
	SetupI2CTransmit(baseAddr, count+1);
	delay(1);

}

static void initLCD(uint32_t baseAddr)
{
    tCount = 0;        // resets transmit counter before every send
    dataToSlave[0] = LCD_CMD;
    dataToSlave[1] = FUNC_SET;
    dataToSlave[2] = SET_BIAS;
    dataToSlave[3] = CONTRAST_SET;
    dataToSlave[4] = PWR_ICON_HC;
    dataToSlave[5] = FOLLOWER_CTL;
    dataToSlave[6] = DISP_EN;
    dataToSlave[7] = CLR_SCRN;
    dataToSlave[8] = ENTRY_SET;
    SetupI2CTransmit(baseAddr, 9);
    delay(1);
}

static void SetupI2C(uint32_t baseAddr)
{
    I2C1ModuleClkConfig(); // set with system clock

    /* sets the pins on the P8 rail to go to I2C1 in mode2.
     * SCL: mode0-spi0_cs0, mode2: I2C1_SCL, gpio0[5]
     * SDA: mode0-spi0_d1, mode2: I2C1_SDA, gpio0[4]
     */
    I2CPinMuxSetup(I2C_P9_17_18);

    /* Put i2c in reset/disabled state */
    I2CMasterDisable(baseAddr);

    /*
    ** Upon reset Auto Idel is enabled.
    ** Hence it is disabled after reset
    */
    I2CAutoIdleDisable(baseAddr);

    /* Configure i2c bus speed to 100khz */
    I2CMasterInitExpClk(baseAddr, SYS_CLK, I2C_INTERNAL_CLK, I2C_OUT_CLK);

    /* Set i2c slave address */
    I2CMasterSlaveAddrSet(baseAddr, SLAVE_ADDR_I2C);

    /* Bring I2C module out of reset */
    I2CMasterEnable(baseAddr);
}

/*
** Transmits data over I2C bus
*/
static void SetupI2CTransmit(uint32_t baseAddr, uint32_t dcount)
{
    /* Data Count specifies the number of bytes to be transferred */
    I2CSetDataCount(baseAddr, dcount);

    numOfBytes = I2CDataCountGet(baseAddr);

    cleanupInterrupts(baseAddr);

    /*
    ** Configure I2C controller in Master Transmitter mode.A stop
    ** condition will be generated after data count number of
    ** bytes are transferred.
    */
    I2CMasterControl(baseAddr, I2C_CFG_MST_TX | I2C_CFG_STOP | I2C_CFG_7BIT_SLAVE_ADDR);

    /* Transmit and Stop Condition Interrupts are enabled */
    I2CMasterIntEnableEx(baseAddr, I2C_INT_TRANSMIT_READY |
                                         I2C_INT_STOP_CONDITION );

    /* Generated Start Condition over I2C bus */
    I2CMasterStart(baseAddr);

    while(flag);

    /* Wait untill I2C registers are ready to access */
    while(0 == (I2CMasterIntRawStatus(baseAddr) & I2C_INT_ADRR_READY_ACESS));

    flag = 1;
}// end steupTransmit_I2C

/*
** Receives data over I2C bus
*/
//static void SetupI2CReception(unsigned int dcount)
//{
//    /* Data Count specifies the number of bytes to be transmitted */
//    I2CSetDataCount(SOC_I2C_1_REGS, 1);
//
//    numOfBytes = I2CDataCountGet(SOC_I2C_1_REGS);
//
//    cleanupInterrupts();
//
//    /* Configure I2C controller in Master Transmitter mode */
//    I2CMasterControl(SOC_I2C_1_REGS, I2C_CFG_MST_TX);
//
//    /* Transmit interrupt is enabled */
//    I2CMasterIntEnableEx(SOC_I2C_1_REGS, I2C_INT_TRANSMIT_READY);
//
//    /* Generate Start Condition over I2C bus */
//    I2CMasterStart(SOC_I2C_1_REGS);
//
//    while(tCount != numOfBytes);
//
//    /* Wait untill I2C registers are ready to access */
//    while(0 == (I2CMasterIntRawStatus(SOC_I2C_1_REGS) & I2C_INT_ADRR_READY_ACESS));
//
//    /* Data Count specifies the number of bytes to be received */
//    I2CSetDataCount(SOC_I2C_1_REGS, dcount);
//
//    numOfBytes = I2CDataCountGet(SOC_I2C_1_REGS);
//
//    cleanupInterrupts();
//
//    /* Configure I2C controller in Master Receiver mode */
//    I2CMasterControl(SOC_I2C_1_REGS, I2C_CFG_MST_RX);
//
//    /* Receive and Stop Condition Interrupts are enabled */
//    I2CMasterIntEnableEx(SOC_I2C_1_REGS, I2C_INT_RECV_READY |
//                                         I2C_INT_STOP_CONDITION);
//
//    /* Generate Start Condition over I2C bus */
//    I2CMasterStart(SOC_I2C_1_REGS);
//
//    while(flag);
//
//    flag = 1;
//}

/* Configures AINTC to generate interrupt */
static void intcConfigureI2C(void (*isr_ptr)(void))
{
    /* Intialize the ARM Interrupt Controller(AINTC) */
    IntAINTCInit();

    /* Registering I2C0 ISR in AINTC */
    IntRegister(SYS_INT_I2C1INT, isr_ptr);

    /* Setting the priority for the system interrupt in AINTC. */
    IntPrioritySet(SYS_INT_I2C1INT, ZERO_PRIORITY, AINTC_HOSTINT_ROUTE_IRQ);

    /* Enabling the system interrupt in AINTC. */
    IntSystemEnable(SYS_INT_I2C1INT);
}// end I2CAintConfigure

static void cleanupInterrupts(uint32_t baseAddr)
{
	// sets or clears IRQ_ENABLE_SET/CLEAR
    I2CMasterIntEnableEx(baseAddr, I2C_INT_BITS);
    I2CMasterIntClearEx(baseAddr,  I2C_INT_BITS);
    I2CMasterIntDisableEx(baseAddr, I2C_INT_BITS);
}// end cleanupInterrupts

/*
** I2C Interrupt Service Routine. This function will read and write
** data through I2C bus.
*/
void I2CIsr(void)
{
    unsigned int status = 0;

    /* Get only Enabled interrupt status */
    status = I2CMasterIntStatus(SOC_I2C_1_REGS);

    /*
    ** Clear all enabled interrupt status except receive ready and
    ** transmit ready interrupt status
    */
    I2CMasterIntClearEx(SOC_I2C_1_REGS,
                        (status & ~(I2C_INT_RECV_READY | I2C_INT_TRANSMIT_READY)));

    if (status & I2C_INT_TRANSMIT_READY)
    {
         /* Put data to data transmit register of i2c */
         I2CMasterDataPut(SOC_I2C_1_REGS, dataToSlave[tCount++]);

         /* Clear Transmit interrupt status */
         I2CMasterIntClearEx(SOC_I2C_1_REGS, I2C_INT_TRANSMIT_READY);

         if(tCount == numOfBytes)
         {
              /* Disable the transmit ready interrupt */
              I2CMasterIntDisableEx(SOC_I2C_1_REGS, I2C_INT_TRANSMIT_READY);

         }

    }

    if (status & I2C_INT_STOP_CONDITION)
    {
           /* Disable transmit data ready and receive data read interupt */
         I2CMasterIntDisableEx(SOC_I2C_1_REGS, I2C_INT_TRANSMIT_READY |
                                               I2C_INT_RECV_READY     |
                                               I2C_INT_STOP_CONDITION);
         flag = 0;
    }

    if(status & I2C_INT_NO_ACK)
    {
         I2CMasterIntDisableEx(SOC_I2C_1_REGS, I2C_INT_TRANSMIT_READY  |
                                               I2C_INT_RECV_READY      |
                                               I2C_INT_NO_ACK          |
                                               I2C_INT_STOP_CONDITION);
         /* Generate a STOP */
         I2CMasterStop(SOC_I2C_1_REGS);

         flag = 0;
    }


    /*********** Recieve ISR, not applicipal for this program ******************
    if(status & I2C_INT_RECV_READY)
    {
         // Receive data from data receive register
         dataFromSlave[rCount++] = I2CMasterDataGet(SOC_I2C_1_REGS);

         // Clear receive ready interrupt status
         I2CMasterIntClearEx(SOC_I2C_1_REGS,  I2C_INT_RECV_READY);

         if(rCount == numOfBytes)
         {
              // Disable the receive ready interrupt
              I2CMasterIntDisableEx(SOC_I2C_1_REGS, I2C_INT_RECV_READY);

              // Generate a STOP
              I2CMasterStop(SOC_I2C_1_REGS);

         }
    }
	***************************************************************************/
}
/***************************** End Of File ************************************/

