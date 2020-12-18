#ifndef CODER
#define CODER

void mutableCaesarEncode(char* str, int shift);
char* immutableCaesarEncode(const char* str, int shift);

void mutableCaesarDecode(char* str, int shift);
char* immutableCaesarDecode(const char* str, int shift);


void mutableXorEncode(char* str, const char* key);
char* immutableXorEncode(const char* str, const char* key);

void mutableXorDecode(char* str, const char* key);
char* immutableXorDecode(const char* str, const char* key);

#endif
