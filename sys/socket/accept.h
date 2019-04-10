#include "../../core.h"

typedef int (*orig_accept_f_type)(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
orig_accept_f_type orig_accept = NULL;

int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen)
{   
    SETUP(orig_accept,orig_accept_f_type,"accept");

    // prologue
    
    int result = orig_accept(sockfd, addr, addrlen);
        
    // epilogue
    
    if (result != -1)
        LOG("accept(%d,%d,%d) -> %d\n",sockfd, addr, addrlen, result);


    return result;
}