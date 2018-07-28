#include <ti/devices/msp432p4xx/driverlib/driverlib.h>

/* Standard Includes */
#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#define delay_ms(x)  __delay_cycles((x*4021))
int main(void)
{
    /* Stop Watchdog  */
    MAP_WDT_A_holdTimer();
    FlashCtl_setWaitState(FLASH_BANK0, 2);
    FlashCtl_setWaitState(FLASH_BANK1, 2);
    PCM_setCoreVoltageLevel(PCM_VCORE1);
    CS_setDCOCenteredFrequency(CS_DCO_FREQUENCY_24);    \\set main DCO frequency to 24MHz
    int counter=0;
    while(1)
    {
        printf("\r\nhello world %d", counter++);
        delay_ms(1000);
        
    }
}
