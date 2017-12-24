#include <plib.h>

int main()
{
    // first Disable CPU interrupts
    INTDisableInterrupts();
    // set pins as ouput
    TRISE = 0x0;
    // off led 1-8
    PORTE = 0x0;
    // Enable CN module
    CNCON |= (1 << 15);
    // on individual pins associated with CN module 
    // look at the ChipKit Uno_rm datasheet For RD 7 - CN16
    CNEN |= (1 << 16);
    // Set priority
    IPC6 |= (1 << 18);
    // Clear Interrupt Flag Status Register
    IFS1 = 0;
    // Set Interrupt Enable Control Register
    IEC1 = 1;
    // Enable MultiVector Mode
    INTEnableSystemMultiVectoredInt();

    while( 1)
    {
        int i;
        for(i = 0; i < 1000000; i++);
        PORTE ^= 1;
    } 
}

// Function associated with CN module (_CHANGE_NOTICE_VECTOR = 26 vector number)
void __ISR(_CHANGE_NOTICE_VECTOR, ipl6) ChangeNotice_Handler(void)
{
    // Need clear flag status register 
    mCNClearIntFlag();
    PORTE = 1;
}