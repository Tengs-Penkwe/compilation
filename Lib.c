#include <stdio.h>
#include <unistd.h>

void foobar(int i)
{
	printf("Printing fromd Lib.so %d\n",i);
	sleep(-1);
}
