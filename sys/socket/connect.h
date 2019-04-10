#include "../../core.h"

typedef int (*orig_connect_f_type)(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
orig_connect_f_type orig_connect = NULL;

int connect(int sockfd, const struct sockaddr *addr, socklen_t addrlen)
{   
    SETUP(orig_connect,orig_connect_f_type,"connect");

    // prologue
    
    int result = orig_connect(sockfd, addr, addrlen);
        
    // epilogue
    
    if (result != -1)
        LOG("connect(%d,%d,%d) -> %d\n",sockfd, addr, addrlen, result);


    return result;
}