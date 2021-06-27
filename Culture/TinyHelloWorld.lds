ENTRY(nomain)

SECTIONS
{
	. = 0x08048000 + SIZEOF_HEADERS;

	tinytext : { *(.data)*(.text)*(.rodata)}

	/DISCARD/ : { *(.eh_frame)*(.symtab)*(.strtab)*(.shstrtab)*(.comment) }
}
