#include "../../core.h"

typedef int (*orig_setgid_f_type)(gid_t gid);
orig_setgid_f_type orig_setgid = NULL;

int setgid(gid_t gid)
{   
    SETUP(orig_setgid,orig_setgid_f_type,"setgid");
     
    // prologue

    int result = orig_setgid(gid);

    // epilogue

    if (result != -1)
        LOG("setgid(%d) -> %d\n",gid,result);

    return result;
}