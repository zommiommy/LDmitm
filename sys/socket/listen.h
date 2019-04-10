#include "../../core.h"

typedef int (*orig_listen_f_type)(int sockfd, int backlog);
orig_listen_f_type orig_listen = NULL;

int listen(int sockfd, int backlog)
{   
    SETUP(orig_listen,orig_listen_f_type,"listen");

    // prologue
    
    int result = orig_listen(sockfd, backlog);
        
    // epilogue
    
    if (result != -1)
        LOG("listen(%d,%d) -> %d\n",sockfd, backlog, result);


    return result;
}