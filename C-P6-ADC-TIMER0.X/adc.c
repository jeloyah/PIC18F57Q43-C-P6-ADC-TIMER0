#include <xc.h>
#include "adc.h"

void ADC_Initialize(void)
{
	/* ADCON0 = 0x80; */
    
    /* ADC enabled */
    ADCON0bits.ON = 1;
    
    /* ADC single conversion */
    ADCON0bits.CONT = 0;
    
    /* ADC clock is Fosc */
    ADCON0bits.CS = 0; 
    
    /* Result left justified */
    ADCON0bits.FM = 0;
	
    /* ADC clock frequency = Fosc / (2*(19+1)) = 1.6 MHz */
    ADCLK = 0x13;
	
    /* ADC Input channel is RB7/ANB7 */
    ADPCHbits.PCH = 0b000001;
}


void ADC_Start(void)
{
	/* ADCON0 |= 0x01; */
    
    /* GO = 1 */
    ADCON0bits.GO = 1;
}

