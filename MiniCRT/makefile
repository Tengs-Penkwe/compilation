CC			=	gcc
CFLAGS		=	-m32 -fno-builtin -nostdlib -fno-stack-protector
AR			=	ar
ARFLAGS		=	-rs
LD			=	ld
LDFLAGS		=	-static -melf_i386 -e mini_crt_entry 
SRCS		=	$(wildcard *.c)
OBJS		=	$(patsubst %.c,%.o,$(SRCS))
LIB			=	minicrt.a

all: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

lib: $(OBJS)
	$(AR) $(ARFLAGS)  $(LIB) $(filter-out entry.o test.o,$^)

test: clean all lib 
	$(CC) $(CFLAGS)	-ggdb -c test.c
	$(LD) $(LDFLAGS) entry.o test.o minicrt.a -o $@

clean: 
	@rm -f *.o *.a
