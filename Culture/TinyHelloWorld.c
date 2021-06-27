char* str = "Hallo Welt!\n";

void print(){
	asm volatile (
		"movl $0x00000013, %%edx\n\t"
		"movl str, %%ecx\n\t"
		"movl $0x00000000, %%ebx\n\t"
		"movl $0x00000004, %%eax\n\t"
		"int $0x80 \n\t"
		::"r"(str)
		);
}

void exit_(){
	asm volatile (
		"movl $42,%ebx \n\t"
		"movl $0000001,%eax \n\t"
		"int $0x80 \n\t"
		);
}

void nomain(){
	print();
	exit_();
}
