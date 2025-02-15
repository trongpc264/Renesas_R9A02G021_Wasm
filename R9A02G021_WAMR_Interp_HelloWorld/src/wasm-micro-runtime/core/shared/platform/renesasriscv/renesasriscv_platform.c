#include "platform_api_vmcore.h"
#include "platform_api_extension.h"

/**
 * Initialize the platform internal resources if needed,
 * this function is called by wasm_runtime_init() and
 * wasm_runtime_full_init()
 *
 * @return 0 if success
 */
int
bh_platform_init(void)
{
    return 0;
}

/**
 * Destroy the platform internal resources if needed,
 * this function is called by wasm_runtime_destroy()
 */
void
bh_platform_destroy(void)
{}

/**
 * printf function for the runtime system
 */
int
os_printf(const char *format, ...)
{
	  int r;
	  va_list ParamList;
	  va_start(ParamList, format);
	  r = SEGGER_RTT_vprintf(0, format, &ParamList);
	  va_end(ParamList);
	  return r;
}

/**
 * vprintf function for the runtime system
 */
int
os_vprintf(const char *format, va_list ap)
{
    return SEGGER_RTT_vprintf(0, format, ap);
}


uint64
os_time_get_boot_us(void)
{
    // Dummy os_time_get_boot_us for compilation
    return 0;
}

uint64
os_time_thread_cputime_us(void)
{
    /* FIXME if u know the right api */
    return os_time_get_boot_us();
}

uint8 *
os_thread_get_stack_boundary(void)
{
    return NULL;
}

void
os_thread_jit_write_protect_np(bool enabled)
{}

int
os_usleep(uint32 usec)
{
    // Dummy os_sleep for compilation
    return 0;
}

int
os_mutex_init(korp_mutex *mutex) {
    return 0;
}

int
os_mutex_destroy(korp_mutex *mutex) {
    return 0;
}

int
os_mutex_lock(korp_mutex *mutex){
    return 0;
}

int
os_mutex_unlock(korp_mutex *mutex){
    return 0;
}

int
os_cond_init(korp_cond *cond){
    return 0;
}

int
os_cond_destroy(korp_cond *cond){
	return 0;
}

int
os_cond_signal(korp_cond *cond){
	return 0;
}

int
os_cond_reltimedwait(korp_cond *cond, korp_mutex *mutex, uint64 useconds){
	return 0;
}

korp_tid
os_self_thread(void){
    korp_tid id = 0;
    return id;
}

int
os_thread_create(korp_tid *p_tid, thread_start_routine_t start, void *arg,
                 unsigned int stack_size){
	return 0;
}
int
os_cond_wait(korp_cond *cond, korp_mutex *mutex){
	return 0;
}

int os_thread_detach(korp_tid){
	return 0;
}

void
os_thread_exit(void *retval){}

int
os_thread_join(korp_tid thread, void **retval){
	return 0;
}

int
os_cond_broadcast(korp_cond *cond){
	return 0;
}

