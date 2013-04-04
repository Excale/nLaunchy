/*
    Build_LinuxOS - for building a boot2 compatible Linux image
    Copyright (C) 2013  Daniel Tang

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

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
