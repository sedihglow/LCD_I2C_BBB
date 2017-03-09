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

#include "hsi2c.h"
#include "interrupt.h"
#include "soc_AM335x.h"
#include "consoleUtils.h"
#include "beaglebone.h"
#include "delay.h"
#include "string.h"


/******************************************************************************
**              INTERNAL FUNCTION PROTOTYPES
******************************************************************************/
//void I2CIsr(void); // interupt service routine
static void SetupI2C(void);
//static void I2CAintcConfigure(void);// for Aint interrupts
//static void cleanupInterrupts(void);// interupt junk
static void SetupI2CTransmit(unsigned int dcount);
static void nextLine(void);
static void sendtext(unsigned char *text,unsigned char count);
static void cleardisplay(void);

//static void SetupI2CReception(unsigned int dcount);

/******************************************************************************
**              GLOBAL VARIABLE DEFINITIONS
******************************************************************************/
volatile unsigned char dataFromSlave[2];
volatile unsigned char dataToSlave[21];
volatile unsigned int numOfBytes;
volatile unsigned int flag = 1;
volatile unsigned int tCount;
volatile unsigned int rCount;
volatile unsigned char I2C_SLAVE_ADDR = 0x3C;
volatile unsigned char COMMAND = 0x00;
unsigned char line1[20] = "Hi Doug..!!";			//Change this text to display on 1st line of LCD
volatile unsigned char line2[20] = "How are you...??!!";	//Change this text to display on 2nd line of LCD


/******************************************************************************
**              FUNCTION DEFINITIONS
******************************************************************************/

int main(void)
{


    /* Enable IRQ in CPSR */
    IntMasterIRQEnable();

    /* Configures AINTC to generate interrupt */
    I2CAintcConfigure();

    DelayTimerSetup();

    /*
    ** Configures HSI2C to Master mode to generate start
    ** condition on HSI2C bus and to transmit data at a
    ** speed of 100khz
    */

    SetupI2C();


    tCount = 0;
    dataToSlave[0] = ;		//Write your LCD Initialization commands here
    dataToSlave[1] = ;
    dataToSlave[2] = ;

    dataToSlave[3]=;
    dataToSlave[4]=;
    dataToSlave[5]=;
    dataToSlave[6]=;
    dataToSlave[7]=;
    dataToSlave[8]=;

    SetupI2CTransmit(9);
    delay(1);
	tCount = 0;
	dataToSlave[0]=;	//Write data initialization command here
	dataToSlave[1]='H';
	dataToSlave[2]='e';
	dataToSlave[3]='l';
	dataToSlave[4]='l';
	dataToSlave[5]='o';
	dataToSlave[6]='!';
	dataToSlave[7]='!';
	SetupI2CTransmit(8);
	delay(1000);

    while(1){

    	cleardisplay();
    	delay(1000);
    	sendtext(line1,strlen(line1));
    	delay(1000);
    	nextLine();
    	sendtext(line2,strlen(line2));
    	delay(3000);

    }


}
static void nextLine (void){
	tCount = 0;
	dataToSlave[0] = 0x00;
	dataToSlave[1] = 0xC0; // set DDRAM ADdress command, sets cursor to the next
						   // vertical line on the screen. The Address of the second
						   // line is 0x40, the 0x80 bit lets the LCD screen know the
						   // command is Set DDRAM Address
	SetupI2CTransmit(2);

}

static void cleardisplay (void){
	tCount = 0;
	dataToSlave[0] = 0x00;
	dataToSlave[1] = 0x01;
	SetupI2CTransmit(2);
	delay(1);

}

static void sendtext(unsigned char *text, unsigned char count){
	tCount = 0;
	unsigned char i = 0;
	dataToSlave[0] = 0x40;
	while(i!=count)
	{
		dataToSlave[i+1]=text[i];
		i = i + 1;
	}
	SetupI2CTransmit(count+1);
	delay(1);

}

static void SetupI2C(void)
{
    I2C1ModuleClkConfig(); // set with system clock

    /* sets the pins on the P8 rail to go to I2C1 in mode2.
     * SCL: mode0-spi0_cs0, mode2: I2C1_SCL, gpio0[5]
     * SDA: mode0-spi0_d1, mode2: I2C1_SDA, gpio0[4]
     */
    I2CPinMuxSetup(1);

    /* Put i2c in reset/disabled state */
    I2CMasterDisable(SOC_I2C_1_REGS);

    /*
    ** Upon reset Auto Idel is enabled.
    ** Hence it is disabled after reset
    */
    I2CAutoIdleDisable(SOC_I2C_1_REGS);

    /* Configure i2c bus speed to 100khz */
    I2CMasterInitExpClk(SOC_I2C_1_REGS, 48000000, 12000000, 100000);

    /* Set i2c slave address */
    I2CMasterSlaveAddrSet(SOC_I2C_1_REGS, I2C_SLAVE_ADDR);

    /* Bring I2C module out of reset */
    I2CMasterEnable(SOC_I2C_1_REGS);
}

/*
** Transmits data over I2C bus
*/
static void SetupI2CTransmit(unsigned int dcount)
{
    /* Data Count specifies the number of bytes to be transferred */
    I2CSetDataCount(SOC_I2C_1_REGS, dcount);

    numOfBytes = I2CDataCountGet(SOC_I2C_1_REGS);


    cleanupInterrupts();

    /*
    ** Configure I2C controller in Master Transmitter mode.A stop
    ** condition will be generated after data count number of
    ** bytes are transferred.
    */
    I2CMasterControl(SOC_I2C_1_REGS, I2C_CFG_MST_TX | I2C_CFG_STOP | I2C_CFG_7BIT_SLAVE_ADDR);

    /* Transmit and Stop Condition Interrupts are enabled */
    I2CMasterIntEnableEx(SOC_I2C_1_REGS, I2C_INT_TRANSMIT_READY |
                                         I2C_INT_STOP_CONDITION );

    /* Generated Start Condition over I2C bus */
    I2CMasterStart(SOC_I2C_1_REGS);

    while(flag);

    /* Wait untill I2C registers are ready to access */
    while(0 == (I2CMasterIntRawStatus(SOC_I2C_1_REGS) & I2C_INT_ADRR_READY_ACESS));

    flag = 1;
}

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
static void I2CAintcConfigure(void)
{
    /* Intialize the ARM Interrupt Controller(AINTC) */
    IntAINTCInit();

    /* Registering I2C0 ISR in AINTC */
    IntRegister(SYS_INT_I2C1INT, I2CIsr);

    /* Setting the priority for the system interrupt in AINTC. */
    IntPrioritySet(SYS_INT_I2C1INT, 0, AINTC_HOSTINT_ROUTE_IRQ );

    /* Enabling the system interrupt in AINTC. */
    IntSystemEnable(SYS_INT_I2C1INT);
}

static void cleanupInterrupts(void)
{
    I2CMasterIntEnableEx(SOC_I2C_1_REGS, 0x7FF);
    I2CMasterIntClearEx(SOC_I2C_1_REGS,  0x7FF);
    I2CMasterIntDisableEx(SOC_I2C_1_REGS, 0x7FF);
}


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

    if(status & I2C_INT_RECV_READY)
    {
         /* Receive data from data receive register */
         dataFromSlave[rCount++] = I2CMasterDataGet(SOC_I2C_1_REGS);

         /* Clear receive ready interrupt status */
         I2CMasterIntClearEx(SOC_I2C_1_REGS,  I2C_INT_RECV_READY);

         if(rCount == numOfBytes)
         {
              /* Disable the receive ready interrupt */
              I2CMasterIntDisableEx(SOC_I2C_1_REGS, I2C_INT_RECV_READY);

              /* Generate a STOP */
              I2CMasterStop(SOC_I2C_1_REGS);

         }
    }
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
}
/***************************** End Of File ************************************/

