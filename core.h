#ifndef CORE_FILE
#define CORE_FILE

#include <dlfcn.h>

#include <stdio.h> // for printf
#include <stdlib.h> // for exit

#define SETUP(VAR, TYPE, NAME) if(VAR == NULL) VAR = (TYPE) dlsym(RTLD_NEXT,NAME) 

#define LOG(...) printf(__VA_ARGS__)

#include "helper.h"

#endif