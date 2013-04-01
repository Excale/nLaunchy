#ifndef  __OS_H__
#define  __OS_H__
/// Set this! [0=CLASSIC, 1=CX]
#define MODEL 0
#if MODEL==0
  #define M(x,y) x
#elif MODEL==1
  #define M(x,y) y
#endif


//Replacement for Ndless
typedef __builtin_va_list va_list;
#define va_start(ap,p)  __builtin_va_start(ap, p)
#define va_arg(ap,type) __builtin_va_arg(ap, type)
#define va_end(ap) __builtin_va_end(ap)

/* As a non-inline function to be called from Thumb state */
void clear_cache(void);

typedef enum BOOL {FALSE = 0, TRUE = 1} BOOL;
typedef void FILE;
struct stat {
    unsigned short st_dev;
    unsigned int st_ino; // 0
    unsigned int st_mode; // see S_ macros above
    unsigned short st_nlink; // 1
    unsigned short st_uid; // 0
    unsigned short st_gid; // 0
    unsigned short st_rdev; // = st_dev
    unsigned int st_size;
    unsigned int st_atime;
    unsigned int st_mtime;
    unsigned int st_ctime;
};

int hwtype(void);
#define is_touchpad FALSE


//Functions from boot2

//! fopen from boot2
#define fopen    ((void *(*)(const char *, const char *))M(0x11856590,0x118AB7B8))
//! fclose from boot2
#define fclose   ((void(*)(void *))M(0x1185634C,0x118AB53C))
//! fread from boot2
#define fread    ((unsigned int(*)(void *, unsigned int, unsigned int, FILE *))M(0x118566CC,0x118AB8A4))
//! fgets from boot2
#define fgets    ((char *(*)(char *, int, FILE *))M(0x11902DBC,0x118D7158))
//! stat from boot2
#define _stat    ((int(*)(const char *, void *))M(0x11859F5C,0x11A58CAC))
int stat(const char *, void *);
int feof(FILE *);

//! display_msg_to_screen from boot2
#define display_msg_to_screen   ((void(*)(const char *, int, int))M(0x11801C94,0x1187F9F8))

//! strlen from boot2
#define strlen   ((unsigned int(*)(const char *))M(0x11856E40,0x118AC2BC))
//! strcpy from boot2
#define strcpy   ((char *(*)(char *, const char *))M(0x11857A44,0x118AC2A0))
//! strncpy from boot2
#define strncpy  ((char *(*)(char *, const char *, int))M(0x11856EC8,0x118AC398))
//! strcmp from boot2
#define strcmp   ((int(*)(const char *, const char *))M(0x11856E00,0x118AC250))
//! strncmp from boot2
#define strncmp  ((int(*)(const char *, const char *, int))M(0x11856E68,0x118AC2E4))

#define strtol strtoul
#if MODEL==0
//! strtoul from boot2
#define strtoul  ((unsigned long int(*)(const char *, char **, int))0x11923094)
#elif MODEL==1
#define strtoul _strtoul
unsigned long int _strtoul(const char *, char **, int);
#endif

//! memset from boot2
#define memset   ((void *(*)(void *, int, unsigned int))M(0x11856D54,0x118AC0C8))
//! vsprintf from boot2
#define vsprintf ((int(*)(char *, const char *, ...))M(0x11855100,0x118A9CE4))

//! malloc from boot2
#define malloc  ((void *(*)(unsigned int))M(0x11854E9C,0x118A9A34))
//! Custom realloc
void * realloc(void *, unsigned long int);
//! free from boot2
#define free  ((void(*)(void *))M(0x11854E90,0x118A99FC))


//Replacement for nIO
typedef int nio_console;
#define NIO_MAX_COLS 0
#define NIO_MAX_ROWS 0
#define NIO_COLOR_WHITE 0
#define NIO_COLOR_BLACK 0
void nio_init(int *, int, int, int, int, int, int, int);
void nio_set_default(int *);
int  nio_gets(char *);
int  uart_puts(const char *);
void uart_printf(char *, ...);
int  nio_puts(const char*);
int  nio_printf(const char *, ...);
void nio_free(int *);

//Other
int main2(int, char *[]);
#define main    main(void){char* argv[] = {"","/documents/linux/linux.ll2.tns"};main2(2,argv); return 0;} int main2

#endif