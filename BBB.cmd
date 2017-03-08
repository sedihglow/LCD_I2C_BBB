/****************************************************************************/
/*  AM335x.cmd                                                              */
/*  Copyright (c) 2014  Texas Instruments Incorporated                      */
/*  Author: Rafael de Souza                                                 */
/*                                                                          */
/*    Description: This file is a sample linker command file that can be    */
/*                 used for linking programs built with the C compiler and  */
/*                 running the resulting .out file on an AM335x device.     */
/*                 Use it as a guideline.  You will want to                 */
/*                 change the memory layout to match your specific          */
/*                 target system.  You may want to change the allocation    */
/*                 scheme according to the size of your program.            */
/*                                                                          */
/****************************************************************************/
-stack	0x0008
-heap	0x2000
-e Entry

--diag_suppress=10063

MEMORY
{
    DDR0:     org = 0x80000000  len = 0x40000000  /* 1GB external DDR Bank 0 */
}

SECTIONS
{
    .text:Entry : load > 0x80000000

    .text    : load > DDR0              /* CODE                          */
    .data    : load > DDR0              /* INITIALIZED GLOBAL AND STATIC VARIABLES */
    .bss     : load > DDR0              /* UNINITIALIZED OR ZERO INITIALIZED */
                                           /* GLOBAL & STATIC VARIABLES */
                    RUN_START(bss_start)
                    RUN_END(bss_end)
    .const   : load > DDR0              /* GLOBAL CONSTANTS              */
    .stack   : load > 0x87FFFFF0           /* SOFTWARE SYSTEM STACK         */
}
