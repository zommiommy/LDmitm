#include "../../core.h"

typedef int (*orig_close_f_type)(int fd);
orig_close_f_type orig_close = NULL;

int close(int fd)
{   
    SETUP(orig_close,orig_close_f_type,"close");

    // prologue

    int result = orig_close(fd);

    // epilogue
    
    if (result != -1)
        LOG("close(%d) -> %d\n",fd,result);

    return result;
}