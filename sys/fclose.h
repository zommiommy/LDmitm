#include "../core.h"

typedef int (*orig_fclose_f_type)(FILE *stream);
orig_fclose_f_type orig_fclose = NULL;

int fclose(FILE * stream)
{   
    SETUP(orig_fclose,orig_fclose_f_type,"fclose");

    // prologue
    
    int result = orig_fclose(stream);
        
    // epilogue
    
    if (result != -1)
        LOG("fclose(%d) -> %d\n",stream,result);

    return result;
}