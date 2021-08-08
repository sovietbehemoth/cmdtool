#include <stdlib.h>
#include <stdio.h>

int main() {
    popen("dir << example.c","w");
}