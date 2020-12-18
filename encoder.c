#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "coder.h"
#include "str.h"

int main(int argc, char** argv) {
    char type[10];
    char text[100];
    char* result;
    bool ok = false;

    if (argc == 4) {
        strcpy(type, argv[1]);
        strcpy(text, argv[2]);
        mutableStrip(text);
        mutableToLower(text);

        if (strcmp(type, "--caesar") == 0 && isNumber(argv[3])) {
            int offset = stringToInt(argv[3]);
            result = immutableCaesarEncode(text, offset);
            ok = true;
        }
        if (strcmp(argv[1], "--xor") == 0) {
            char password[100];
            strcpy(password, argv[3]);
            result = immutableXorEncode(text, password);
            ok = true;
        }
    }
    else if (argc == 1) {   
        printf("Type (caesar/xor): ");
        scanf("%s", type);
        printf("Text: ");
        scanf("%s", text);
        mutableStrip(text);
        mutableToLower(text);
        if (strcmp(type, "caesar") == 0) {
            int offset;
            printf("Offset: ");
            scanf("%d", &offset);
            result = immutableCaesarEncode(text, offset);
            ok = true;
        }
        else if (strcmp(type, "xor") == 0) {
            char password[100];
            printf("Password: ");
            scanf("%s", password);
            result = immutableXorEncode(text, password);
            ok = true;
        }
    }

    if (ok) {
        printf("%s\n", result);
        free(result);
    }
    else {
        printf("Input format must be: \n");
        printf("1. ./encoder --caesar text offset\n");
        printf("2. ./encoder --xor text password\n");
        printf("3. ./encoder\n");
    }
    
    return 0;
}
