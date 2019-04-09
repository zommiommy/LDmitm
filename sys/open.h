#include "../core.h"

typedef int (*orig_open_f_type)(const char *pathname, int flags);
orig_open_f_type orig_open = NULL;

int open(const char *pathname, int flags, ...)
{   
    SETUP(orig_open,orig_open_f_type,"open");

    // prologue

    int result = orig_open(pathname,flags);

    // epilogue

    if (result != -1)
        LOG("open(\"%s\",%d) -> %d\n",pathname,flags,result);

    return result;
}