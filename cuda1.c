#include <stdio.h>
#include "/usr/include/linux/cuda.h"
#define N 8

__global__ void add(int *a, int *b, int *c)
{

}

int main() {
	int *a; int *b; int *res;
	cudaMalloc((void**)&res, sizeof(int)*N);
}
