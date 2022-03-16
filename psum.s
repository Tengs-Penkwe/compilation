	.arch armv8-a
	.text
	.align	2
	.globl _psum1
_psum1:
LFB0:
	sub	sp, sp, #48
LCFI0:
	str	x0, [sp, 24]
	str	x1, [sp, 16]
	str	x2, [sp, 8]
	ldr	x0, [sp, 24]
	ldr	s0, [x0]
	ldr	x0, [sp, 16]
	str	s0, [x0]
	mov	x0, 1
	str	x0, [sp, 40]
	b	L2
L3:
	ldr	x0, [sp, 40]
	lsl	x0, x0, 2
	sub	x0, x0, #4
	ldr	x1, [sp, 16]
	add	x0, x1, x0
	ldr	s1, [x0]
	ldr	x0, [sp, 40]
	lsl	x0, x0, 2
	ldr	x1, [sp, 24]
	add	x0, x1, x0
	ldr	s0, [x0]
	ldr	x0, [sp, 40]
	lsl	x0, x0, 2
	ldr	x1, [sp, 16]
	add	x0, x1, x0
	fadd	s0, s1, s0
	str	s0, [x0]
	ldr	x0, [sp, 40]
	add	x0, x0, 1
	str	x0, [sp, 40]
L2:
	ldr	x1, [sp, 40]
	ldr	x0, [sp, 8]
	cmp	x1, x0
	blt	L3
	nop
	nop
	add	sp, sp, 48
LCFI1:
	ret
LFE0:
	.section __TEXT,__eh_frame,coalesced,no_toc+strip_static_syms+live_support
EH_frame1:
	.set L$set$0,LECIE1-LSCIE1
	.long L$set$0
LSCIE1:
	.long	0
	.byte	0x1
	.ascii "zR\0"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x1e
	.uleb128 0x1
	.byte	0x10
	.byte	0xc
	.uleb128 0x1f
	.uleb128 0
	.align	3
LECIE1:
LSFDE1:
	.set L$set$1,LEFDE1-LASFDE1
	.long L$set$1
LASFDE1:
	.long	LASFDE1-EH_frame1
	.quad	LFB0-.
	.set L$set$2,LFE0-LFB0
	.quad L$set$2
	.uleb128 0
	.byte	0x4
	.set L$set$3,LCFI0-LFB0
	.long L$set$3
	.byte	0xe
	.uleb128 0x30
	.byte	0x4
	.set L$set$4,LCFI1-LCFI0
	.long L$set$4
	.byte	0xe
	.uleb128 0
	.align	3
LEFDE1:
	.ident	"GCC: (Homebrew GCC 11.2.0_1) 11.1.0"
	.subsections_via_symbols
