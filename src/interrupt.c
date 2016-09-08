#include "types.h"
#include "screen.h"

void isr_default_int(void) {
    print("interrupt\n");
}

void isr_clock_int(void) {
    static int tic = 0;
    static int sec = 0;
    tic++;
    if (tic % 100 == 0) {
        sec++;
        tic = 0;
        print("clock\n");
    }
}

void isr_kbd_int(void) {
    print("keyboard\n");
}
