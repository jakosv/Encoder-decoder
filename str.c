#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include "str.h"

static const int Difference = ('a' - 'A');

int stringToInt(const char* str) {
    int result = 0;
    const int size = strlen(str);
    
    assert(isNumber(str));

    int i = 0;
    char sign = 0;
    if (size > 0 && str[0] == '-') {
        sign = 1;
        i = 1;
    }
    for (; i < size; ++i) {
        result = result * 10 + (str[i] - '0');
    }
    if (sign == 1) {
        result = (-1) * result;
    }

    return result;
}


void mutableToUpper(char* str) {
    const int size = strlen(str);

    for (int i = 0; i < size; ++i) {
        if (isLowerCase(str[i])) {
            str[i] -= Difference;
        }
    }
}

void mutableToLower(char* str) {
    const int size = strlen(str);

    for (int i = 0; i < size; ++i) {
        if (isUpperCase(str[i])) {
            str[i] += Difference;
        }
    }
}

char* immutableToUpper(const char* str) {
    const int size = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    strcpy(newStr, str);

    mutableToUpper(newStr);

    return newStr;
}

char* immutableToLower(const char* str) {
    const int size = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    strcpy(newStr, str);
    
    mutableToLower(newStr);

    return newStr;
}

void mutableStrip(char* str) {
    const int size = strlen(str);
    int startSpaces = 0;
    int endSpaces = 0;

    for (int i = 0; i < size; ++i) {
        if (str[i] == ' ') {
            ++startSpaces;
        }
        else {
            break;
        }
    }
    for (int i = size - 1; i >= 0; --i) {
        if (str[i] == ' ') {
            ++endSpaces;
        }
        else {
            break;
        }
    }

    int strNormalSize = size - startSpaces - endSpaces;
    if (strNormalSize < 0) {
        // String consists only spaces
        strNormalSize = 0;
    }

    for (int i = 0; i < strNormalSize; ++i) {
        str[i] = str[startSpaces + i];
    }
    
    str[strNormalSize] = '\0';
}

char* immutableStrip(const char* str) {
    const int size = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    strcpy(newStr, str);

    mutableStrip(newStr);

    return newStr;
}


void mutableRemoveSpaces(char* str) {
    const int size = strlen(str); 
    int k = 0;

    for (int i = 0; i < size; ++i) {
        if (str[i] != ' ') {
            str[k] = str[i];    
            ++k;
        }
    }
    
    str[k] = '\0';
}

char* immutableRemoveSpaces(const char* str) {
    const int size = strlen(str); 
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    strcpy(newStr, str);

    mutableRemoveSpaces(newStr);
    
    return newStr;
}

void mutableFilter(char* str) {
    const int size = strlen(str);
    int k = 0;

    for (int i = 0; i < size; ++i) {
        if (isLowerCase(str[i]) 
            || isUpperCase(str[i]) 
            || isDigit(str[i])
            || (str[i] == ' '))
        {
            str[k] = str[i];    
            ++k;
        }
    }
    
    str[k] = '\0';
}

char* immutableFilter(const char* str) {
    const int size = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    strcpy(newStr, str);

    mutableFilter(newStr);

    return newStr;
}


bool isNumber(const char* str) {
    const int size = strlen(str);
    
    for (int i = 0; i < size; ++i) {
        if (!(isDigit(str[i]) || str[i] == '-')) {
            return false;
        }
    }

    return true;
}
        
bool isLetters(const char* str) {
    const int size = strlen(str);

    for (int i = 0; i < size; ++i) {
        if (!(isAlpha(str[i]))) {
            return false;
        }
    }
    
    return true;
}

bool isUpperCase(const char ch) {
    return (ch >= 'A' && ch <= 'Z');
}

bool isLowerCase(const char ch) {
    return (ch >= 'a' && ch <= 'z');
}

bool isAlpha(const char ch) {
    return (isUpperCase(ch) || isLowerCase(ch));
}

bool isDigit(const char ch) {
    return (ch >= '0' && ch <= '9');
}

char* inputString() {
    int dim = 1;
    int size = 0;
    char* str = (char*) malloc(sizeof(char) * (dim + 1));
    char ch = 0;
    
    ch = fgetc(stdin);
    while (ch != '\n') {
        str[size] = ch;
        size++;
        if (size >= dim) {
            dim *= 2;
            str = (char*) realloc(str, sizeof(char) * (dim + 1));
        }
        ch = fgetc(stdin);
    } 
    str = (char*) realloc(str, sizeof(char) * (size + 1));
    str[size] = '\0';

    return str;
}
