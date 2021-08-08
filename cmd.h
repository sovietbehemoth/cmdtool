#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#include "js.h"

#pragma once
#pragma mark Guards
#pragma GCC poison gets

#if defined(WIN_32) && !defined(ALLOW_WINDOWS)
#error Windows is not supported with this program, using it may cause undefined behavior or not work altogether, please either use a Unix OS or use WSL
#endif

#define _No_return_ __attribute__((noreturn))

#define FIXED_RADIX 10

#pragma mark Flags

#define FILE_READ 0
#define FILE_WRITE 1
#define FILE_DELETE 2
#define FILE_CREATE 3

#pragma mark Function declarations

typedef struct _session {
    char **argv;
    int argc;

    int intent;

    long fmax_bytes;
    int index;
} session_t;

//Errors
void _No_return_ cmd_error(char *msg);
void help_print(void);

void filesearch(char * fpath);
void file_read_cmd(session_t *cmd);
void file_remove(session_t *cmd);

//Check command line arguments
int cflags_check(session_t *cmd);