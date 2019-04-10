#define _GNU_SOURCE

#include "config.h"

// FILES

#ifdef FCLOSE
#include "sys/files/fclose.h"
#endif

#ifdef FOPEN
#include "sys/files/fopen.h"

#ifdef FREAD
#include "sys/files/fread.h"
#endif
#endif

#ifdef FWRITE
#include "sys/files/fwrite.h"
#endif


//  IO

#ifdef CLOSE
#include "sys/io/close.h"
#endif

#ifdef OPEN
#include "sys/io/open.h"
#endif

#ifdef READ
#include "sys/io/read.h"
#endif

#ifdef WRITE
#include "sys/io/write.h"
#endif

// SYSTEM

#ifdef EXECVE
#include "sys/system/execve.h"
#endif

#ifdef SETGID
#include "sys/system/setgid.h"
#endif

#ifdef SETUID
#include "sys/system/setuid.h"
#endif

// SOCKET

#ifdef SOCKET
#include "sys/socket/socket.h"
#endif

#ifdef ACCEPT
#include "sys/socket/accept.h"
#endif

#ifdef CONNECT
#include "sys/socket/connect.h"
#endif

#ifdef BIND
#include "sys/socket/bind.h"
#endif

#ifdef LISTEN
#include "sys/socket/listen.h"
#endif

// HEAP

#ifdef MALLOC
#include "sys/heap/malloc.h"
#endif

#ifdef CALLOC
#include "sys/heap/calloc.h"
#endif

#ifdef RELLOC
#include "sys/heap/relloc.h"
#endif

#ifdef FREE
#include "sys/heap/free.h"
#endif



