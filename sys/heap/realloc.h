#include "../../core.h"

typedef void* (*orig_realloc_f_type)(void* ptr, size_t size);
orig_realloc_f_type orig_realloc = NULL;

void* realloc(void* ptr, size_t size)
{   
    SETUP(orig_realloc,orig_realloc_f_type,"realloc");

    // prologue
    
    void* result = orig_realloc(ptr,size);
        
    // epilogue
    
    if (result != NULL)
        LOG("realloc(0x%x, %u) -> 0x%x\n", ptr, size, result);


    return result;
}