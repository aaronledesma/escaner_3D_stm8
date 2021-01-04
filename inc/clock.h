#ifndef CLOCK_H
#define CLOCK_H

void CLOCK_Init( void );

#define enableClockSwitch 0x02
#define disableClockSwitch 0xFD

#define HSI_clockSource 0xE1
#define LSI_clockSource 0xD2
#define HSE_clockSource 0xB4

#define HSE_enable 0x01
#define HSI_enable 0x01
#define LSI_enable 0x08

#define SWBSYmask 0x01

#define clockOutputEnable 0x01

#define f_HSI_DIV 0x00
#define f_LSI			0x02
#define f_HSE			0x04
#define f_CPU		  0x08
#define f_CPU_2   0x0A
#define f_CPU_4   0x0C
#define f_CPU_8   0x0E
#define f_CPU_16  0x10
#define f_CPU_32  0x12
#define f_CPU_64  0x14
#define f_HSI     0x16
#define f_MASTER  0x18

#define fHSI_RC_1 0x00
#define fHSI_RC_2 0x08
#define fHSI_RC_4 0x10
#define fHSI_RC_8 0x18

#define f_MASTER_1   0x00
#define f_MASTER_2   0x01
#define f_MASTER_4   0x02
#define f_MASTER_8   0x03
#define f_MASTER_16  0x04
#define f_MASTER_32  0x05
#define f_MASTER_64  0x06
#define f_MASTER_128 0x07

#endif
