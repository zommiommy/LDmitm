#ifndef CORE_FILE
#define CORE_FILE

#include <dlfcn.h>      // dlsym

#include <stdio.h>      // printf
#include <stdlib.h>     // exit
#include <sys/types.h>  // Sockets
#include <sys/socket.h> // Sockets

#define SETUP(VAR, TYPE, NAME)\
    if(VAR == NULL){\
        LOG("[INFO] Searching \"%s\"\n",NAME);\
        VAR = (TYPE) dlsym(RTLD_NEXT,NAME); \
        if(VAR == NULL){\
            LOG("[ERROR] can't find the original \"%s\"\n",NAME);\
            fflush(stderr);\
            exit(EXIT_FAILURE);\
        }\
    }


#define LOG(...) fprintf(stderr, __VA_ARGS__)

#include "helper.h"

#endif