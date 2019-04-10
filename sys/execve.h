#include "../core.h"

typedef int (*orig_execve_f_type)(const char *filename, char *const argv[],char *const envp[]);
orig_execve_f_type orig_execve = NULL;

int execve(const char *filename, char *const argv[],char *const envp[])
{   
    SETUP(orig_execve,orig_execve_f_type,"execve");

    // prologue

    int result = orig_execve(filename,argv,envp);

    // epilogue

    if (result != -1)
        LOG("execve(\"%s\",\"%s\",\"%s\") -> %d\n",filename,argv,envp,result);

    return result;
}