#ifndef CORE_FILE
#define CORE_FILE

#include <dlfcn.h>      // dlsym

#include <stdio.h>      // printf
#include <stdlib.h>     // exit
#include <sys/types.h>  // Sockets
#include <sys/socket.h> // Sockets

#define SETUP(VAR, TYPE, NAME) if(VAR == NULL) VAR = (TYPE) dlsym(RTLD_NEXT,NAME) 

#define LOG(...) printf(__VA_ARGS__)

#include "helper.h"

#endif