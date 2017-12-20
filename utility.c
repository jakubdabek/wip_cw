#include "utility.h"

#include <stdio.h>
#include <string.h>

void flush(void)
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}

const char* read(char *buffer, size_t size)
{
    if(!fgets(buffer, 50, stdin))
        return NULL;
    if(buffer[strlen(buffer) - 1] == '\n')
        buffer[strlen(buffer) - 1] = '\0';
    else
        flush();
    printf("got: %s\n", buffer);

    return buffer;
}

int read_int(int *value)
{
    char buffer[100];
    printf("reading int: %s", read(buffer, 100));
    int success = sscanf(buffer, "%d", value);

    return success;
}
