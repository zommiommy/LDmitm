#include "../../core.h"

typedef  size_t (*orig_fwrite_f_type)( const void * ptr, size_t size, size_t count, FILE * stream );
orig_fwrite_f_type orig_fwrite = NULL;

size_t fwrite ( const void * ptr, size_t size, size_t count, FILE * stream )
{   
    SETUP(orig_fwrite,orig_fwrite_f_type,"fwrite");

    // prologue
    
    size_t result = orig_fwrite(ptr,size,count,stream);
        
    // epilogue
    
    LOG("fwrite(");
    display_buffer(ptr,size * count);
    LOG("%u,%u,%u) -> %u\n",size,count,stream, result);

    return result;
}