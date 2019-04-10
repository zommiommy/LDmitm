#include "../../core.h"

typedef  ssize_t (*orig_write_f_type)(int fd, const void *buf, size_t nbytes);
orig_write_f_type orig_write = NULL;


ssize_t write(int fd, const void *buf, size_t nbytes)
{   
    SETUP(orig_write,orig_write_f_type,"write");

    // prologue
    
    ssize_t result = orig_write(fd,buf,nbytes);

    // epilogue
    
    LOG("write(%d,",fd);
    display_buffer(buf,nbytes);
    LOG(",%u) -> %u\n",nbytes, result);

    return result;
}