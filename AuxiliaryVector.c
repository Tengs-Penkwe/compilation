#include <stdio.h>
#include <elf.h>

int main (int argc, char** argv)
{
	long* p = (long*) argv;
	Elf32_auxv_t* aux;

	printf("Argument count: %d\n",*(p-1));

	int i;
	for (i=0; i<*(p-1); ++i)
	{
		printf("Argument %d : %s\n",i,*(p+i) );
	}

	p+=i;
	p++;
	
	printf("Environments :\n");
	while(*p)
	{
		printf("%s\n",*p);
		p++;
	}

	p++;

	printf("Auxiliary Vector :\n");
	aux = (Elf32_auxv_t*)p;
	while(aux->a_type != AT_NULL)
	{
		printf("Type: %02d Value: %x\n",aux->a_type,aux->a_un.a_val);
		aux++;
	}

	return 0;

}
