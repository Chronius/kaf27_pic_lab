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
    TRISD = 1 << 7;

    /*
     * Infinite loop
     */
    while(1) {
        /*
         * Flash led
         */
        PORTE = 0;

        if (PORTD & (1 << 7)) {
            PORTE = (1 << 2); // LD3
        }
    }
}