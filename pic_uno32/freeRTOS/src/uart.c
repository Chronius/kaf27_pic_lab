#include <plib.h>

void tx_char(int c) {
    while ((U1STA & (1 << 9)));
    U1TXREG = c;
}

char rx_char() {
    while (!(U1STA & (1 << 0)));
    return U1RXREG;
}

void tx_str(char *ptr) {
    while (*ptr)
        tx_char(*ptr++);
	tx_char('\r');
}

void init_uart() {
    U1STA |= (1 << 12);
    U1STA |= (1 << 10);
    //U1BRG = 42;
    U1BRG = 21;
    U1MODE = (1 << 15);
}
