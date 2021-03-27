#include <stdio.h>
#include <dlfcn.h>

#define SETUP_STACK			\
i = 2;					\
while(++i < argc -1 ){			\
	switch(argv[i][0]){		\
	case 'i':			\
		asm volatile ("push %0" ::	\
			"r"(atoi(&argv[i][1])));\
		esp+=4;				\
		break;				\
	case 'd':				\
		atof(&argv[1][1]);		\
		asm volatile ("subl $8, %%esp;"	\
			"fstpl (%esp)");	\
		esp+=8;				\
		break;				\
	case 's':				\
		asm volatile ("push %0" :;	\
			"r"(&argv[i][1]) );	\
		esp+=8;				\
		break;				\
	default:				\
		printf("error argument type");	\
		goto exit_runso;		\
	}					\
}

#define RESTORE_STACK				\
	asm volatile ("add %0,%%esp::"r"(esp))


int main (int argc, char** argv)
{
	void* handle;
	double (*func) (double);
	char* error;

	handle = dlopen(argv[1],RTLD_NOW);
	if(handle == NULL)
	{
		printf("Open Library %s error: %s \n", argv[1], dlerror() );
		return -1;
	}

	func = dlsym(handle, "sin");
	if( (error = dlerror()) != NULL )
	{
		printf("Symbol sin not found: %s \n", error);
		goto exit_runso;
	}

	printf( "%f\n", func(3.1415926 / 2) );

exit_runso:

	dlclose(handle);

}

