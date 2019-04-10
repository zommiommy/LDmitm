#include "../../core.h"

typedef void* (*orig_malloc_f_type)(size_t size);
orig_malloc_f_type orig_malloc = NULL;

void* malloc(size_t size)
{   
    SETUP(orig_malloc,orig_malloc_f_type,"malloc");

    // prologue
    
    void* result = orig_malloc(size);
        
    // epilogue
    
    if (result != NULL)
        LOG("malloc(%d) -> 0x%x\n", size, result);


    return result;
}