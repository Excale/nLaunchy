#include "os.h"
#include "common.h"

void clear_cache(void) {
    unsigned dummy;
    __asm volatile(
        " .arm \n"
        "0: mrc p15, 0, r15, c7, c10, 3 @ test and clean DCache \n"
        " bne 0b \n"
        " mov %0, #0 \n"
        " mcr p15, 0, %0, c7, c7, 0 @ invalidate ICache and DCache \n"
    : "=r" (dummy));
}
int hwtype(void) {
    return M(0,1);
}

int stat(const char * filename, void * stats) {
    return _stat(filename, stats);
}

int feof(FILE * stream __attribute__((unused))) {
    return 0;
}

void * realloc(void * ptr __attribute__((unused)), unsigned long int size) {
	if(size>=0x1700000)
	{
		return (void *)NULL;
	} else
	{
		return (void *)0x10100000;
	}
}

void nio_init(int *a __attribute__((unused)), int b __attribute__((unused)),
              int  c __attribute__((unused)), int d __attribute__((unused)),
              int  e __attribute__((unused)), int f __attribute__((unused)),
              int  g __attribute__((unused)), int h __attribute__((unused))) {}

void nio_set_default(int * a __attribute__((unused))) {}

int  nio_gets(char * a __attribute__((unused))) { return 0; }

void nio_free(int * a __attribute__((unused))) {}

int  uart_puts(const char *str __attribute__((unused))) { return 1; }

void uart_printf(char *format __attribute__((unused)), ...) {}

int nio_puts(const char* str) {
    if (strlen(str)!=2)
    {
        display_msg_to_screen(str, 1, 1);
    }
    return 1;
}

int nio_printf(const char *format, ...) {
    char buf[1000];
    memset(buf,'\0',sizeof(buf));
    __builtin_va_list arglist;
    __builtin_va_start(arglist,format);
    vsprintf(buf,format,*(char **)&arglist);
    #if MODEL==0
    nio_puts(buf);
    #elif MODEL==1
    char bufu[2000];                                                   
    memset(bufu,'\0',sizeof(buf));
    unsigned int s=0;
    while (s<sizeof(buf)) {
        bufu[2*s]=buf[s];
        s++;
    }
    nio_puts(bufu);
    #endif
    __builtin_va_end(arglist);
    return strlen(buf);
}

#if MODEL==1
unsigned long int _strtoul(const char * a __attribute__((unused)), char ** b __attribute__((unused)), int c __attribute__((unused))) {
    return 0;
}
#endif
