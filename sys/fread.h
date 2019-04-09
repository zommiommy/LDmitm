#include "../core.h"

typedef  size_t (*orig_fread_f_type)( void * ptr, size_t size, size_t count, FILE * stream );
orig_fread_f_type orig_fread = NULL;

size_t fread ( void * ptr, size_t size, size_t count, FILE * stream )
{   
    SETUP(orig_fread,orig_fread_f_type,"fread");

    // prologue
    
    size_t result = orig_fread(ptr,size,count,stream);
        
    // epilogue
    
    LOG("fread(%x,%u,%u,%u) -> ",ptr,size,count,stream);
    display_buffer(ptr,size * count);
    LOG("\n");

    return result;
}