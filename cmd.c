#include "cmd.h"

void _No_return_ cmd_error(char *msg) {
    fputs(msg, stderr);
    putchar('\n');
    exit(1);
}

void help_print(void) {
    puts("CmdTool is a command line tool");
    puts("          --read-file: Print file contents to standard out");
    puts("          -noindex: Do not ensure selected file exists before attempting read");
    puts("          --bytes: Amount of bytes allocated to file buffer");
}

void filesearch(char * fpath) {
    char * command = (char*) malloc(sizeof (char*) * 100);
    char * cmdbuffer = (char*) malloc(sizeof (char*));

    sprintf(command, "ls ./%s", fpath);
    FILE * pipe = popen(command, "r");
    fscanf(pipe, "%s", cmdbuffer);
    startswith(cmdbuffer, "./") == false ? cmd_error("File not found"): 1;
    pclose(pipe);

    free(command);
    free(cmdbuffer);
}

void file_read_cmd(session_t *cmd) {
    char * foption = cmd->argv[1];
    char * fpath = substring(foption, strlen("--read-file"), strlen(foption));

    if (cmd->index == true) filesearch(fpath);

    //automatic allocation protocol
    if (cmd->fmax_bytes == -1) {
        cmd->fmax_bytes = 0;
        FILE * freadptr = fopen(fpath, "r");
        while (1) {
            if (feof(freadptr)) break;
            fgetc(freadptr);
            cmd->fmax_bytes += 1;
        };
        fclose(freadptr);
    }

    char * buffer = (char*) calloc(sizeof (char*), cmd->fmax_bytes);
    FILE * file = fopen(fpath, "r");

    int c, pos;
    pos = 0;

    while (1) {
        if (feof(file)) break;
        buffer[pos] = fgetc(file);
        pos += 1;
    }

    fclose(file);
    puts(buffer);
    free(buffer);
}

void file_remove(session_t *cmd) {
    char * fpath = substring(foption, strlen("--remove-file"), strlen(foption));
    char * command = (char*) malloc(sizeof (char*));
    sprintf(command, "rm ./%s", fpath);
    if (cmd->index == true) filesearch(fpath);
    system(command);
    free(fpath);
}


int cflags_check(session_t *cmd) {
    char **args = cmd->argv;
    int argc = cmd->argc;

    for (int i = 1; i < argc; i++) {
        if (strlen(args[i]) < 2) {
            cmd_error("Invalid option, see '-help' for options");
        } else {
            //double tick
            if (args[i][0] == '-' && args[i][1] == '-') {
                char * option = substring(args[i], 1, strlen(args[i]));
                startswith(option, "read-file") == true? cmd->intent = FILE_READ:1;
                startswith(option, "remove-file") == true? cmd->intent = FILE_DELETE:1;
                if (startswith(option, "bytes") == true) {
                    char* *restrict fvoidf = malloc(sizeof (char*));
                    char * flag = substring(cmd->argv[i], strlen("--bytes"), strlen(cmd->argv[i]));
                    cmd->fmax_bytes = (long) strtol(flag, fvoidf, FIXED_RADIX);
                    free(fvoidf);
                    free(flag);
                }
                free(option);
            //single tick
            } else if (args[i][0] == '-') {
                char * option = substring(args[i], 0, strlen(args[i]));
                strcmp(option, "noindex") == true? cmd->index = false:1; 
                strcmp(option, "help") == true || strcmp(option, "h") == true? help_print():1;
                free(option);
            } else {
                cmd_error("Invalid option, see '-help' for a list of commands");
            }
        }
    }

    switch (cmd->intent) {
        case FILE_READ:
            file_read_cmd(cmd);
            break;
        case FILE_DELETE:
            file_remove(cmd);
            break;
    }
}

int main(int argc, char **argv) {
    session_t *cmd = (session_t*) malloc(sizeof (session_t*) * 10000);

    cmd->argv = argv;
    cmd->argc = argc;

    cmd->fmax_bytes = -1;
    cmd->index = true;
    cmd->intent = -1;

    cflags_check(cmd);
}