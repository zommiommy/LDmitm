#include "../../core.h"

typedef void* (*orig_calloc_f_type)(size_t num, size_t size);
orig_calloc_f_type orig_calloc = NULL;

void* calloc(size_t num, size_t size)
{   
    SETUP(orig_calloc,orig_calloc_f_type,"calloc");

    // prologue
    
    void* result = orig_calloc(num, size);
        
    // epilogue
    
    if (result != NULL)
        LOG("calloc(%u, %u) -> 0x%x\n", num, size, result);


    return result;
}