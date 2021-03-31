#include <stdio.h>
#include <setjmp.h>

jmp_buf b;

int
main()
{
//	setjmp(b);
	printf("I'm the main function\n");
}

//__attribute__((section(".init")))
//void before(){
//	printf("I'm the Alpha\n");
////	longjmp(b,1);
//}
//
__attribute__((section(".fini")))
void After(){
	printf("I'm the Omega\n");
//	longjmp(b,1);
}
