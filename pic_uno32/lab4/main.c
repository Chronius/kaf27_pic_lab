#include <plib.h>

void tx_char(char ch)
{
    while ((U1STA & (1 << 9))) ;

    U1TXREG = ch;
}

char rx_char()
{
    while (!(U1STA & (1 << 0))) ;

    return U1RXREG;
}

void tx_str(char *ptr)
{
    while (*ptr)
        tx_char(*ptr++);
}

int main()
{
    char ch;

    /*
     * Enable TX and RX.
     */
    U1STA |= (1 << 12);
    U1STA |= (1 << 10);

    /*
     * Set baudrate.
     */
    U1BRG = 42;

    /*
     * Enable UART.
     */
    U1MODE = (1 << 15);

    while (1) {
        // wait for char
        ch = rx_char();

        if (ch == 'A')
            tx_str("Hello");
    }
}