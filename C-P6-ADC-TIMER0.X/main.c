
#include <xc.h>
#include "main.h"
#include "clock.h"
#include "gpio.h"
#include "adc.h"
#include "timer0.h"

void main(void) {
    
    unsigned char i;
    unsigned int ADCsample[16];
    unsigned char ADCresult;
    
    /* System Clock Initialization */
	CLOCK_Initialize();
    
    /* Config PortA */
    PortA_Initialize();
    
    /* Config PortB */
    PortB_Initialize();

    /* Config PortC */
    PortC_Initialize();
    
    /* Config PortD */
    PortD_Initialize();
    
    /* Config PortE */
    PortE_Initialize();
    
    /* Config PortF */
    PortF_Initialize();
    
    /* Config ADC */
    ADC_Initialize();
    
    /* Config TIMER0 */
    TIMER0_Initialize();
        
    /* infinite loop */
    while(1)
    {
             
     for (i=0; i<16; i++)
     {
         /* Start ADC conversion */
        ADC_Start();
        
        TIMER0_Delay_ms(100);
        
        /* Wait for Go = 0 */
        while (ADC_conversionComplete)
             ;
        
        ADCsample[i] += ADRESH;
         
     }
     
     
     ADCresult = (unsigned char) ADCsample / (unsigned int) 16;
     
         
     } /* while */
            
    return;
} /* main*/
