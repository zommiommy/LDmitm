#include "../../core.h"

typedef int (*orig_bind_f_type)(int sockfd, const struct sockaddr *addr,socklen_t addrlen);
orig_bind_f_type orig_bind = NULL;

int bind(int sockfd, const struct sockaddr *addr,socklen_t addrlen)
{   
    SETUP(orig_bind,orig_bind_f_type,"bind");

    // prologue
    
    int result = orig_bind(sockfd, addr, addrlen);
        
    // epilogue
    
    if (result != -1)
        LOG("bind(%d,%d,%d) -> %d\n",sockfd, addr, addrlen, result);


    return result;
}