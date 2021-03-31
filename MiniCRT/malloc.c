#include "minicrt.h"

typedef struct _heap_header
{
	enum{
		HEAP_BLOCK_FREE = 0xABABABAB,
		HEAP_BLOCK_USED = 0xCDCDCDCD,
	} type;

	unsigned size;
	struct _heap_header* prev;
	struct _heap_header* next;
} heap_header;

static heap_header* list_head = NULL;

#define ADDR_ADD(a,o) ((char*)(a) + o)
#define HEADER_SIZE (sizeof(heap_header))

void free(void* ptr)
{
	heap_header* header = (heap_header*)ADDR_ADD(ptr, -HEADER_SIZE);
	if(header->type != HEAP_BLOCK_USED){
		return;
	}
	header->type = HEAP_BLOCK_FREE;
	
	if(header->prev != NULL && header->prev->type == HEAP_BLOCK_FREE){
		//Merge
		header->prev->next = header->next;
		if (header->next != NULL){
			header->next->prev = header->prev;
		}
		header->prev->size += header->size;

		header = header->prev;
	}
	if(header->next != NULL && header->next->type == HEAP_BLOCK_FREE){
		//Merge
		header->size += header->next->size;
		header->next = header->next->next;
	}
}

void* malloc(unsigned size)
{
	heap_header* header;

	if (size==0){
		return NULL;
	}
	
	header = list_head;
	while(header != 0){
		if(header->type == HEAP_BLOCK_FREE){
			header = header->next;
			continue;
		}
		if(header->size > size + HEADER_SIZE && header->size <= size + HEADER_SIZE * 2){
			header->type = HEAP_BLOCK_USED;
		}
		if(header->size > size + HEADER_SIZE * 2){
			//split
			heap_header* next =(heap_header*)ADDR_ADD(header, size+HEADER_SIZE);

			next->prev = header;
			next->next = header->next;
			next->type = HEAP_BLOCK_FREE;
			next->size = header->size - (size + HEADER_SIZE);
			header->next = next;
			header->type = HEAP_BLOCK_USED;
			header->size = size + HEADER_SIZE;

			return ADDR_ADD(header, HEADER_SIZE);
		}
		header = header->next;
	}
	return NULL;
}

static int brk(void* end_data_segment)
{
	int ret = 0;
	asm volatile ("movl $45, %%eax;	\
				movl %1, %%ebx;		\
				int $0x80;			\
				movl %%eax, %0;"	\
				:"=r"(ret):"m"(end_data_segment));
}

int mini_crt_init_heap()
{
	void* base = NULL;
	heap_header* header = NULL;
	//32 MiB
	unsigned heap_size = 1024 * 1024 * 32;

	base = (void*)brk(0);
	void* end = ADDR_ADD(base, heap_size);
	end = (void*)brk(end);
	if (!end && !base){
		return 0;
	}
printf("base address:%d, end address:%d.",base ,end);

	header->size = heap_size;
	header->type = HEAP_BLOCK_FREE;
	header->next = NULL;
	header->prev = NULL;

	list_head = header;
	return 1;
}
