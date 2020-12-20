#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "str.h"

void mutableCaesarEncode(char* str, int shift) {
    const int size = strlen(str);

    for (int i = 0; i < size; ++i) {
        str[i] = str[i] + shift; 
    }
}

char* immutableCaesarEncode(const char* str, int shift) {
    const int size = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    strcpy(newStr, str);

    mutableCaesarEncode(newStr, shift);

    return newStr;
}


void mutableCaesarDecode(char* str, int shift) {
    mutableCaesarEncode(str, -shift);
}

char* immutableCaesarDecode(const char* str, int shift) {
    return immutableCaesarEncode(str, -shift);
}


void mutableXorEncode(char* str, const char* key) {
    const int size = strlen(str);
    const int keySize = strlen(key);
    int j = 0;

    for (int i = 0; i < size; ++i) {
        str[i] = (char)(str[i] ^ key[j]);
        j = (j + 1) % keySize;
    }   
}

char* immutableXorEncode(const char* str, const char* key) {
    const int size = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    strcpy(newStr, str);

    mutableXorEncode(newStr, key);

    return newStr;
}


void mutableXorDecode(char* str, const char* key) {
    mutableXorEncode(str, key);
}

char* immutableXorDecode(const char* str, const char* key) {
    return immutableXorEncode(str, key);
}
