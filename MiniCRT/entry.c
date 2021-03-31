#include "minicrt.h"

extern int main(int agrc, char** argv);
void exit(int);

static void crt_fatal_error(const char* msg){
	printf("fatal error: %s\n", msg);
	exit(1);
}

void mini_crt_entry(void)
{
	int ret;
	
	int argc;
	char** argv;
	char* ebp_reg =0;

printf("Entered");

	asm volatile ("movl %%esp, %0 ;":"=r"(ebp_reg));
	argc = *(int*)(ebp_reg + 4);
	argv = (char**)(ebp_reg + 8);

	if (!mini_crt_init_heap()){
		crt_fatal_error("Heap Initialization failed");
	}

	if (!mini_crt_init_io()){
		crt_fatal_error("IO Initialization failed");
	}

	ret = main(argc,argv);
	exit(ret);
}

void exit(int exitCode){
	mini_crt_call_exit_routine();
	
	asm volatile ("movl %0, %%ebx ; \
				movl $1, %%eax;		\
				int $0x80;			\
				hlt;"				\
				::"m"(exitCode));
}
