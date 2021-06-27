#include <stdio.h>
#include <stddef.h>
int main(void)
{
    struct foo {
        char c;
        int x;
    } __attribute__((packed));
    struct foo arr[2] = { { 'a', 10 }, {'b', 20 } };
    int *p0 = &arr[0].x;
    int *p1 = &arr[1].x;
    printf("sizeof(struct foo)      = %d\n", (int)sizeof(struct foo));
    printf("offsetof(struct foo, c) = %d\n", (int)offsetof(struct foo, c));
    printf("offsetof(struct foo, x) = %d\n", (int)offsetof(struct foo, x));
    printf("arr[0].x = %d\n", arr[0].x);
    printf("arr[1].x = %d\n", arr[1].x);
    printf("p0 = %p\n", (void*)p0);
    printf("p1 = %p\n", (void*)p1);
    printf("*p0 = %d\n", *p0);
    printf("*p1 = %d\n", *p1);
    return 0;
}
