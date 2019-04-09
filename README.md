# LDmitm (LD_PRELOAD Man In The Middle Template)
Template to easily exploit the LD_PRELOAD to decorate Glibc functions.


## Compilation
```bash
gcc -shared -fPIC  main.c -o LDmitm.so -ldl
```
or use the ```compile.sh``` script.

## Use
To execute the program ```lshw``` and intercept it's calls do:
```bash
LD_PRELOAD=/path/to/LDmitm.so lshw
```

## Config
The file ```config.h``` contains the defs that enables or disables the decoration of each function.

e.g.:
```C
#ifndef CONFIG_FILE
#define CONFIG_FILE

#define FOPEN
//#define FWRITE
#define FCLOSE

#define OPEN
//#define WRITE
#define CLOSE

//#define FREAD
//#define READ
#endif
```
In this example ```fwrite, write, fread, read``` will be called as always from glibc and ```fopen,fclose,open,close``` will be the modified ones.

## Modify

As an example we might want change the ```.Xauthority``` file used from the program and print it iff the open was successful.

```C
#include "../core.h"

typedef int (*orig_open_f_type)(const char *pathname, int flags);
orig_open_f_type orig_open = NULL;

int open(const char *pathname, int flags, ...)
{   
    SETUP(orig_open,orig_open_f_type,"open");

    // prologue

    if(strcmp (pathname,"/home/user1/.Xauthority") == 0)
        pathname = "/home/user2/.Xauthority";

    int result = orig_open(pathname,flags);

    // epilogue

    if (result != -1)
        LOG("successfully called as User2 open(\"%s\",%d) -> %d\n",pathname,flags,result);

    return result;
}
```