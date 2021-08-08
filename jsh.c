#include "js.h"

#include "alpha_macro.h"

//Check for bad lengths
static void __error_length_mismatch__(char *subj, char *q) {
    if (strlen(q) > strlen(subj)) {
        fprintf(stderr, "Query string is larger than base string");
        exit(1);
    }
}

//JavaScript stdout function without formatting
void console_log(char *out) {
    for (int i = 0; i < strlen(out); i++) {
        fputc(out[i], stdout);
    }; fputc('\n', stdout);
}

//JavaScript warn console
void console_warn(char *out) {
    printf("%s\n", out);
}

//Essentially prints to stderr
void console_error(char *out) {
    fprintf(stderr, "%s\n", out);
}

int startswith(char *subj, char *q) {
    for (int i = 0; i < strlen(q); i++) {
        if (q[i] != subj[i]) return 1;
    } return 0;
}

int endswith(char *subj, char *q) {
    __error_length_mismatch__(subj, q);
    int inc_counter = strlen(q);
    for (int i = strlen(subj); inc_counter > 0; i--) {
        if (q[inc_counter] != subj[i]) return 1;
        inc_counter -= 1;
    } return 0;
}

//Converts the string to lowercase and copies result
void tolowercase(char *string) {
    char *retval = (char*)malloc(sizeof(retval));
    int pos = 0;
    for (int i = 0; i < strlen(string); i++) {
        lower_macro;
        pos += 1;
    } strcpy(string, retval);
    free(retval);
}

//Converts the string to uppercase and copies result
void touppercase(char *string) {
    char *retval = (char*)malloc(sizeof(retval));
    int pos = 0;
    for (int i = 0; i < strlen(string); i++) {
        upper_macro;
        pos += 1;
    } strcpy(string, retval);
    free(retval);
}

//Create substring
char *substring(char *base, int start, int end) {
    int pos = 0;
    char *res = (char*)malloc(sizeof(res));
    for (int i = 0; i < strlen(base); i++) {
        if (i > start && i < end) {
            res[pos] = base[i];
            pos += 1;
        }
    } return res;
}

//Search string for first index of q
int indexof_s(char *str, char q) {
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == q) {
            return i;
        }
    }
    return -1;
}

//Search string for last index of q
int lastindexof_s(char *str, char q) {
    int *instances = (int*)malloc(sizeof(instances));
    int pos = 0;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == q) {
            instances[pos] = i;
            pos += 1;
        }
    }
    int ret = instances[pos-1];
    free(instances);
    if (pos == 0) return -1;
    else return ret;
}