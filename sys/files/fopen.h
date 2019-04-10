#include "../../core.h"

typedef FILE *(*orig_fopen_f_type)(const char *filename, const char *mode);
orig_fopen_f_type orig_fopen = NULL;

FILE * fopen(const char *filename, const char *mode)
{   
    SETUP(orig_fopen,orig_fopen_f_type,"fopen");

    // prologue
    
    FILE * result = orig_fopen(filename, mode);
        
    // epilogue
    
    if (result != (void*)-1 && result != (void*)0)
        LOG("fopen(\"%s\",\"%s\") -> %d\n",filename,mode,result);


    return result;
}