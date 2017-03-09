/*******************************************************************************
 * filename: lcd_I2C.c
 *
 * Implements the functions and its helpers for lcd_I2C.h
 *
 * written by: James Ross
 ******************************************************************************/

#include "lcd_I2C.h"

#undef DELAY_USE_INTERRUPTS

#define DISP_ON_LEN 2
#define CMD_DISP_ON "\x00\x0C"

void setupLCD_I2C(uint32_t baseAddr)
{
    I2C1ModuleClkConfig(); // set with system clock

    /* sets the pins on the P8 rail to go to I2C1 in mode2.
     * SCL: mode0-spi0_cs0, mode2: I2C1_SCL, gpio0[5]
     * SDA: mode0-spi0_d1, mode2: I2C1_SDA, gpio0[4]
     */
    I2CPinMuxSetup(I2C_P9_17_18);

    /* Put i2c in reset/disabled state */
    I2CMasterDisable(baseAddr);

    /* Upon reset Auto Idel is enabled.*/
    I2CAutoIdleDisable(baseAddr);

    /* Configure i2c bus speed to 100khz */
    I2CMasterInitExpClk(baseAddr, SYS_CLK, I2C_INTERNAL_CLK, I2C_OUT_CLK);

    /* Set i2c slave address */
    I2CMasterSlaveAddrSet(baseAddr, SLAVE_ADDR_I2C);

    /* Bring I2C module out of reset */
    I2CMasterEnable(baseAddr);
}//end setupI2C

void clearDisplay(uint32_t baseAddr){
	char clearCmd[] = {SLAVE_ADDR_I2C, 0x00, 0x01};
	transmit_I2C(baseAddr, clearCmd, 3);

}


void sendMsg(uint32_t baseAddr, char *msg)
{
	char dataToSlave[MSG_LEN_MAX] = {'\0'};
	dataToSlave[0] = 0x40;
	snprintf(dataToSlave+1, MSG_LEN_MAX-1, msg);

	transmit_I2C(baseAddr, dataToSlave, strlen(dataToSlave));
}// end sendMsg

void turnOnLCD(uint32_t baseAddr)
{
	char dispCmd[20] = {'\0'};

	dispCmd[0] = SLAVE_ADDR_I2C;
	dispCmd[1] = 0x00;

	dispCmd[2] = 0x38;
	transmit_I2C(baseAddr, dispCmd, 3);
	delay(10);

	dispCmd[2] = 0x39;
	transmit_I2C(baseAddr, dispCmd, 3);
	delay(10);

	dispCmd[2] = 0x14;
	transmit_I2C(baseAddr, dispCmd, 3);
	delay(10);

	dispCmd[2] = 0x78;
	transmit_I2C(baseAddr, dispCmd, 3);
	delay(10);

	dispCmd[2] = 0x5E;
	transmit_I2C(baseAddr, dispCmd, 3);
	delay(10);

	dispCmd[2] = 0x6D;
	transmit_I2C(baseAddr, dispCmd, 3);
	delay(10);

	dispCmd[2] = 0x0F;
	transmit_I2C(baseAddr, dispCmd, 3);
	delay(10);

	dispCmd[2] = 0x01;
	transmit_I2C(baseAddr, dispCmd, 3);
	delay(10);

	dispCmd[2] = 0x06;
	transmit_I2C(baseAddr, dispCmd, 3);
	delay(10);
}// end turnOnLCD

void transmit_I2C(uint32_t baseAddr, uint8_t *toSlave, uint32_t transLen)
{
	int i = 0;

	/* Data Count specifies the number of bytes to be transferred, acceess
	 * and fills offset: 0x98 I2C_CNT */
    I2CSetDataCount(baseAddr, transLen);

    /*
    ** Configure I2C controller in Master Transmitter mode.A stop
    ** condition will be generated after data count number of
    ** bytes are transferred.
    */
    I2CMasterControl(baseAddr, I2C_CFG_MST_TX | I2C_CFG_STOP | I2C_CFG_7BIT_SLAVE_ADDR);

    /* Generated Start Condition over I2C bus */
    I2CMasterStart(baseAddr);

    do{
    	if(I2CMasterIntRawStatus(baseAddr) & 0x10){
    		/* Put data to data transmit register of i2c */
    		I2CMasterDataPut(baseAddr, toSlave[i]);
    		runDelay(10);
    		++i;
    	 }
    }while(i < transLen);

    /* generate stop */
    I2CMasterStop(baseAddr);
}// end setTransmit_I2C

void runDelay(uint32_t milliSec)
{
    while(milliSec != 0)
    {
        DMTimerCounterSet(SOC_DMTIMER_7_REGS, 0);
        DMTimerEnable(SOC_DMTIMER_7_REGS);
        while(DMTimerCounterGet(SOC_DMTIMER_7_REGS) < TIMER_1MS_COUNT);
        DMTimerDisable(SOC_DMTIMER_7_REGS);
        milliSec--;
    }
}// end runDelay

/******** EOF ******/
