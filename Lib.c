#include <stdio.h>
#include <unistd.h>

void foobar(int i)
{
	printf("Printing fromd Lib.so %d\n",i);
	sleep(10);
}

void __attribute__((constructor)) init_function(void){
	printf("Initialize Dynamic Library\n");
}
void __attribute__((destructor)) fini_function(void){
	printf("Closing Dynamic Library\n");
}
