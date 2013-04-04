#define STACK_BEGIN	0x12000000

.section .text.startup

.global _start
_start:
	mov sp, #STACK_BEGIN

	/* Disable interrupts and ensure we are in SVC mode */
	mrs r4, cpsr
	bic r4, r4, #0xFF
	orr r4, r4, #0xD3
	msr cpsr, r4

	/* Disable MMU and data cache */
	mrc p15, 0, r4, c1, c0, 0
	bic r4, r4, #0x05
	mcr p15, 0, r4, c1, c0,0

	bl main

	mov r0, #2
	ldr r1, =0x900A0008
	str r0, [r1]

	/* Should never return here but who knows? */

.global panic
panic:
	b .

/* Startup program max 0x100 bytes */
