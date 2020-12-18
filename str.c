#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "str.h"

static const int Difference = ('a' - 'A');

int stringToInt(const char* str) {
    int result = 0;
    size_t size = strlen(str);
    
    assert(isNumber(str));

    size_t i = 0;
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
    for (size_t i = 0; i < strlen(str); ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] -= Difference;
        }
    }
}

void mutableToLower(char* str) {
    for (size_t i = 0; i < strlen(str); ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] += Difference;
        }
    }
}

char* immutableToUpper(const char* str) {
    const size_t size = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));

    for (size_t i = 0; i < size; ++i) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            newStr[i] = str[i] - Difference;
        }
        else {
            newStr[i] = str[i];
        }
    }
    newStr[size] = '\0';

    return newStr;
}

char* immutableToLower(const char* str) {
    const size_t size = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));

    for (size_t i = 0; i < size; ++i) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            newStr[i] = str[i] + Difference;
        }
        else {
            newStr[i] = str[i];
        }
    }
    newStr[size] = '\0';

    return newStr;
}

void mutableStrip(char* str) {
    const size_t size = strlen(str);
    int startSpaces = 0;
    int endSpaces = 0;

    for (size_t i = 0; i < size; ++i) {
        if (str[i] == ' ') {
            ++startSpaces;
        }
        else {
            break;
        }
    }
    for (size_t i = size - 1; i >= 0; --i) {
        if (str[i] == ' ') {
            ++endSpaces;
        }
        else {
            break;
        }
    }

    size_t strNormalSize = size - startSpaces - endSpaces;
    if (strNormalSize <= 0) {
        // String consists only spaces
        strNormalSize = 0;
    }

    for (int i = 0; i < strNormalSize; ++i) {
        str[i] = str[startSpaces + i];
    }
    
    str[strNormalSize] = '\0';
}

char* immutableStrip(const char* str) {
    const size_t size = strlen(str);
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

    size_t strNormalSize = size - startSpaces - endSpaces;
    
    if (strNormalSize <= 0) {
        // String consists only spaces
        strNormalSize = 0;
    }
    char* newStr = (char*) malloc(sizeof(char) * (strNormalSize + 1));
    for (int i = 0; i < strNormalSize; ++i) {
        newStr[i] = str[startSpaces + i];
    }
    newStr[strNormalSize] = '\0';

    return newStr;
}


void mutableRemoveSpaces(char* str) {
    size_t size = strlen(str); 
    size_t k = 0;
    for (size_t i = 0; i < size; ++i) {
        if (str[i] != ' ') {
            str[k] = str[i];    
            ++k;
        }
    }
    
    str[k] = '\0';
}

char* immutableRemoveSpaces(const char* str) {
    size_t size = strlen(str); 
    size_t k = 0;
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    strcpy(newStr, str);
    for (size_t i = 0; i < size; ++i) {
        if (str[i] != ' ') {
            newStr[k] = newStr[i];    
            ++k;
        }
    }
    newStr[k] = '\0';
    
    return newStr;
}

void mutableFilter(char* str) {
    const size_t size = strlen(str);
    size_t k = 0;
    for (size_t i = 0; i < size; ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9')
            || (str[i] == ' '))
        {
            str[k] = str[i];    
            ++k;
        }
    }
    
    str[k] = '\0';
}

char* immutableFilter(const char* str) {
    const size_t size = strlen(str);
    char* newStr = (char*) malloc(sizeof(char) * (size + 1));
    size_t k = 0;

    for (size_t i = 0; i < size; ++i) {
        if ((str[i] >= 'a' && str[i] <= 'z')
            || (str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= '0' && str[i] <= '9')
            || (str[i] == ' '))
        {
            newStr[k] = str[i];    
            ++k;
        }
    }
    newStr[k] = '\0';

    return newStr;
}


bool isNumber(const char* str) {
    const size_t size = strlen(str);
    
    for (size_t i = 0; i < size; ++i) {
        if (!((str[i] >= '0' && str[i] <= '9') || str[i] == '-')) {
            return false;
        }
    }

    return true;
}
        
bool isLetters(const char* str) {
    const size_t size = strlen(str);

    for (size_t i = 0; i < size; ++i) {
        if (!((str[i] >= 'A' && str[i] <= 'Z')
            || (str[i] >= 'a' && str[i] <= 'z')))
        {
            return false;
        }
    }
    
    return true;
}


