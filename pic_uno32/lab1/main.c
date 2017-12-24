#include <plib.h>

/*
 * Main fucntion
 */
int main()
{
    /*
     * Init port
     */
    TRISE = 0;
    PORTE = 0;

    /*
     * Infinite loop
     */
    while(1) {
        delay_ms(1000);
        /*
         * Flash led
         */
        PORTE ^= 1;
    }
}

void delay_ms(unsigned int ms_count)
{
    unsigned int i, j;
    for(i = 0; i < ms_Count; i++) {
        for(j = 0; j < 10000; j++);
    }
}