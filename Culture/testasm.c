int main(void)
{
    char buf[] = "test\n";
    int n;
    asm volatile (
        "movl $0x00000002, %%edi\n"  /* first argument */
        "movl $0x00000006, %%edx\n"  /* third argument */
        "movl $0x02000004, %%eax\n"  /* syscall number */
        "syscall\n"
        : "=A"(n)         /* %rax: return value */
        : "S"(buf));      /* %rsi: second argument */
    return n;
}
