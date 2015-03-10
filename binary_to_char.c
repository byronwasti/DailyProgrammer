#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    int rc = 0;
    size_t length, i;
    char *binary = NULL, *byte = NULL;

    if (argc < 2) {
        printf("Usage: bender <binary>\n");

        rc = 1;
        goto cleanup;
    }

    binary = argv[1];
    length = strlen(binary);
    byte = malloc(sizeof(char) * 8);

    for (i = 0; i < length; i += 8) {
        strncpy(byte, binary + i, 8);
        printf("%c", (char)strtol(byte, NULL, 2));
    }

    printf("\n");

cleanup:
    if (byte) {
        free(byte);
    }

    return rc;
}
