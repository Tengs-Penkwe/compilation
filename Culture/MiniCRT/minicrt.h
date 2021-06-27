#ifndef __MINI_CRT_H__
#define __MINI_CRT_H__

#ifdef __cplusplus
extern "C" {
#endif

//malloc
#ifndef NULL
#define NULL (0) // (void*)0
#endif
void free(void* ptr);
void* malloc(unsigned size);
int mini_crt_init_heap();

//! string.c
char* itoa(int, char* str, int radix);
int strcmp(const char* src, const char* dst);
char* strcpy(char* dst, char* src);
unsigned strlen(const char* str);

//! stdio.c
typedef int FILE;
#define EOF (-1)
#define stdin	((FILE*)0)
#define stdout	((FILE*)1)
#define stderr	((FILE*)2)

int mini_crt_init_io();
FILE* fopen(const char* filename, const char* mode);
int fread(void* buffer, int size, int count, FILE* stream);
int fwrite(const void* buffer, int size, int count, FILE* stream);
int fclose(FILE* fp);
int fseek(FILE* fp, int offset, int set);

//! stdlib.c
int fputc(int c, FILE* stream);
int fputs(const char* str, FILE* stream);
int printf(const char* format, ...);
int fprintf(FILE* stream, const char* format, ...);

void do_global_ctors();
void mini_crt_call_exit_routine();

//! atexit
typedef void (*atexit_func_t) (void);
int atexit(atexit_func_t func);

#ifdef __cplusplus
}
#endif

#endif //__MINI_CRT_H__
