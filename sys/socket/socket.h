#include "../../core.h"

typedef int (*orig_socket_f_type)(int domain, int type, int protocol);
orig_socket_f_type orig_socket = NULL;

int socket(int domain, int type, int protocol)
{   
    SETUP(orig_socket,orig_socket_f_type,"socket");

    // prologue
    
    int result = orig_socket(domain, type, protocol);
        
    // epilogue
    
    if (result != -1)
        LOG("socket(%d,%d,%d) -> %d\n",domain, type, protocol, result);


    return result;
}