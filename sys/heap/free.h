#include "../../core.h"

typedef void (*orig_free_f_type)(void* ptr);
orig_free_f_type orig_free = NULL;

void free(void* ptr)
{   
    SETUP(orig_free,orig_free_f_type,"free");

    // prologue
    if (ptr != NULL)
        LOG("free(0x%x)\n", ptr);
    
    orig_free(ptr);
        
    // epilogue
    
}