#include <stdio.h>
#include <stdlib.h>

unsigned long long maximum = 0;

int 
main(int argc, char * argv[])
{
	unsigned blocksize[] = {1024*1024*1024,1024*1024, 1024, 1};
	for (int i=0; i<4; i++){
		for (int count=1; ; count++){
			printf("Mallocing i = %d, count = %d, Maximum = %llxbytes\n",i,count,maximum);
			void* block = malloc(maximum + blocksize[i] * count);
			if (block) {
				maximum += blocksize[i] * count;
				free(block);
			} else {
				break;
			}
			printf("Malloced %llu bytes\n",maximum);
		}
	}

	printf("Maximum malloc size = %llu bytes\n", maximum);
}
