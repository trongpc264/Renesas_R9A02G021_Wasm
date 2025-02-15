#include "platform_api_vmcore.h"
#include "platform_api_extension.h"

void *
os_mmap(void *hint, size_t size, int prot, int flags, os_file_handle file)
{
    void *buf_origin;
    void *buf_fixed;
    uintptr_t *addr_field;

    buf_origin = malloc(size + 8 + sizeof(uintptr_t));
    if (!buf_origin) {
        return NULL;
    }

    buf_fixed = buf_origin + sizeof(void *);
    if ((uintptr_t)buf_fixed & (uintptr_t)0x7) {
        buf_fixed = (void *)((uintptr_t)(buf_fixed + 8) & (~(uintptr_t)7));
    }

    addr_field = buf_fixed - sizeof(uintptr_t);
    *addr_field = (uintptr_t)buf_origin;

    memset(buf_origin, 0, size + 8 + sizeof(uintptr_t));
    return buf_fixed;
}


void
os_munmap(void *addr, size_t size)
{
    void *mem_origin;
    uintptr_t *addr_field;

    if (addr) {
        addr_field = addr - sizeof(uintptr_t);
        mem_origin = (void *)(*addr_field);
        free(mem_origin);
    }
}

void *
os_mremap(void *in, size_t old_size, size_t new_size)
{
    return os_realloc(in, new_size);
}

int
os_mprotect(void *addr, size_t size, int prot){
	return 0;
}
