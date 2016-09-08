#include "types.h"
#include "gdt.h"
#include "screen.h"
#include "io.h"
#include "idt.h"

void init_pic(void);

void kmain(void) {
    kY = 16;
    kattr = 0x0E;

    init_idt();
    print("kernel : idt loaded\n");

    init_pic();
    print("kernel : pic configured\n");

    /* initialisation de la GDT et des segments */
    init_gdt();

    /* Initialisation du pointeur de pile %esp */
    asm("	movw $0x18, %ax \n \
		movw %ax, %ss \n \
		movl $0x20000, %esp");

    print("kernel : gdt loaded\n");

    sti;

    kattr = 0x47;
    print("kernel : allowing interrupt\n");
    kattr = 0x07;

    while (1);
}
