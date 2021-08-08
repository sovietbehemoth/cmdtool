#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define true 0
#define false 1

void console_log(char *out);
void console_warn(char *out);
void console_error(char *out);

int startswith(char *subj, char *q);
int endswith(char *subj, char *q);

void touppercase(char *string);
void tolowercase(char *string);

char *substring(char *base, int start, int end);

int indexof_s(char* str, char q);
int lastindexof_s(char* str, char q);
