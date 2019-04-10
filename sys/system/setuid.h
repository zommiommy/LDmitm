#include "../../core.h"

typedef int (*orig_setuid_f_type)(uid_t uid);
orig_setuid_f_type orig_setuid = NULL;

int setuid(uid_t uid)
{   
    SETUP(orig_setuid,orig_setuid_f_type,"setuid");
     
    // prologue

    int result = orig_setuid(uid);

    // epilogue

    if (result != -1)
        LOG("setuid(%d) -> %d\n",uid,result);

    return result;
}