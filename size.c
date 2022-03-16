#include "stdio.h"
#include "stdbool.h"
#include "MacTypes.h"

int main(){
	printf("bool:%d, Byte:%d, short:%d, int:%d, long:%d, long long:%d, float:%d, double:%d",sizeof(bool), sizeof(Byte), sizeof(short), sizeof(int), sizeof(long), sizeof(long long), sizeof(float), sizeof(double));
}
