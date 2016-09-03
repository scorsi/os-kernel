#include "types.h"
#include "gdt.h"
#include "screen.h"

void kmain(void)
{
	kY = 18;
	kattr = 0x5E;
	print("kernel : loading new gdt...\n");

	/* initialisation de la GDT et des segments */
	init_gdt();

	/* Initialisation du pointeur de pile %esp */
	asm("   movw $0x18, %ax \n \
                movw %ax, %ss \n \
                movl $0x20000, %esp");

	kattr = 0x4E;
	print("kernel : new gdt loaded !\n");

	while (1);
}
