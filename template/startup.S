/* Public domain. Do whatever you want with this */

#define STACK_BEGIN	0x12000000

.section .text.startup

.global _start
_start:
	mov sp, #STACK_BEGIN

	bl main

	mov r0, #2
	ldr r1, =0x900A0008
	str r0, [r1]

	/* Should never return here but who knows? */
	b .
