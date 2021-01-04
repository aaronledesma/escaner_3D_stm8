#include "clock.h"
#include <ioSTM8L152r8.h>

void CLOCK_Init( void )
{
	/* Enable HSI oscillator */
	CLK_ICKCR = HSI_enable; 
	
	/* Wait for HSIRDY=1 */
 	while( (CLK_ICKCR & 0x02) != 0x02 );

	/* HSI y CPU prescaling */
	CLK_CKDIVR = fHSI_RC_1 | f_MASTER_1;
	
	/* Enable switch clock mechanism */
	CLK_SWCR = enableClockSwitch;  
	
	/* Select HSI as clock source */
	CLK_SWR = HSI_clockSource; 	
			
	/* Wait for SBSY = 0 */
	while( (CLK_SWCR&SWBSYmask) != 0 );
	
	/* SBSY is cleared by hardware */
			
	/* Disable switch clock mechanism */
	CLK_SWCR &= disableClockSwitch; 
}