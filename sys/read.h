#include "../core.h"

typedef  ssize_t (*orig_read_f_type)(int fd, void *buf, size_t count);
orig_read_f_type orig_read = NULL;


ssize_t read(int fd, void *buf, size_t count)
{   
    SETUP(orig_read,orig_read_f_type,"read");

    // prologue
    
    ssize_t result = orig_read(fd,buf,count);

    // epilogue
    
    LOG("read(%d,%x,%u) ->",fd,buf,count);
    display_buffer(buf,count);
    LOG("\n");

    return result;
}