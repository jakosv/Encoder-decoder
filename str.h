#ifndef STR
#define STR

#include <stdbool.h>

int stringToInt(const char* str);

void mutableToUpper(char* str);
char* immutableToUpper(const char* str);

char* immutableToLower(const char* str);
void mutableToLower(char* str);

void mutableStrip(char* str);
char* immutableStrip(const char* str);

void mutableRemoveSpaces(char* str);
char* immutableRemoveSpaces(const char* str);

void mutableRemoveSpaces(char* str);
char* immutableRemoveSpaces(const char* str);

void mutableFilter(char* str);
char* immutableFilter(const char* str);

bool isNumber(const char* str);
bool isLetters(const char* str);
bool isUpperCase(const char ch);
bool isLowerCase(const char ch);
bool isAlpha(const char ch);
bool isDigit(const char ch);

#endif
