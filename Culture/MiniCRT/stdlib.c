#include "minicrt.h"

int
fputc (int c, FILE* stream){
	if (fwrite(&c, 1, 1, stream) != 1)
		return EOF;
	else 
		return c;
}
int
fputs (const char* str, FILE* stream){
	int len = strlen(str);
	if (fwrite(str, 1, len, stream) != len)
		return EOF;
	else
		return len;
}

#define va_list char*
#define va_start(ap,arg) (ap=(va_list)&arg + sizeof(arg))
#define va_arg(ap,t) (*(t*)((ap+=sizeof(t))-sizeof(t)))
#define va_end(ap) (ap=(va_list)0)

int 
vfprintf(FILE* stream, const char* format, va_list arglist){
	int ret = 0;
	const char* p = 0;
	for (p=format; *p != '\0'; ++p){
		if (*p != '%'){
			if (fputc(*p, stream) <0 )
				return EOF;
			else
				++ret;
			break;
		}
		p++;
		switch (*p)
		{
		case 'd': ;
			char buf[16];
			itoa(va_arg(arglist, int), buf, 10);
			if (fputs(buf, stream) < 0)
				return EOF;
			ret += strlen(buf);
			break;
		case 's': ;
			const char* str = va_arg(arglist, const char*);
			if (fputs(str, stream) < 0)
				return EOF;
			ret += strlen(str);
			break;
		}
	}
	return ret;
}
int
printf(const char* format, ...){
	va_list(arglist);
	va_start(arglist, format);
	return vfprintf(stdout, format, arglist);
}
int
fprintf(FILE* stream, const char* format, ...){
	va_list(arglist);
	va_start(arglist, format);
	return vfprintf(stream, format, arglist);
}
void
mini_crt_call_exit_routine(){
	return ;
}
