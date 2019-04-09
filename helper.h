#ifndef HELPER_FILE
#define HELPER_FILE

void display_buffer(const void *buf, size_t nbytes){
    char *ptr = (char*) buf;
    printf("\"");
    for(int i = 0; i < nbytes; i++, ptr++){
        printf("\\x%02X",*ptr);
    }
    printf("\"");
}

#endif