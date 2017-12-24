#include <plib.h>

#define SET_BIT(x, n)       (x |= (1 << n))
#define CLEAT_BIT(x, n)     (x &= ~(1 << n))
#define TOOGLE_BIT(x, n)    (x ^= (1 << n))
#define CHECK_BIT(x, n)     ((x >> n) & 1)

/*
 * SW4 - 35 pin associated with IC4/PMCS1/PMA14/INT4/RD11
 * and Vector Number 14
 */
int main()
{
    // first Disable CPU interrupts
    INTDisableInterrupts();
    // set pins as ouput
    TRISE = 0x0;
    // off led 1-8
    PORTE = 0x0;
    // clear PORTD
    PORTD = 0x0;
    // set SW4 as input
    SET_BIT(PORTD, 11);
    // 1 - external interrupt pin x triggers on a 
    // rising edge, 0 = triggers on a falling edge 
    // SET_BIT(INTCON, 4); // Set on a rising
    CLEAT_BIT(INTCON, 4); // Set on a falling
    // Set priority
    SET_BIT(IPC4, 26);
    // Clear Interrupt Flag Status Register
    CLEAT_BIT(IFS0, 19);
    // Set Interrupt Enable Control Register
    SET_BIT(IEC0, 19);
    // Enable MultiVector Mode
    INTEnableSystemMultiVectoredInt();

    while( 1)
    {
        int i;
        for(i = 0; i < 1000000; i++);
        // do something
    } 
}

// PIN35 associated with vector number 19
void __ISR(19, ipl6) ChangeNotice_Handler(void)
{
    CLEAT_BIT(IFS0, 19);
    PORTE ^= 1;
}