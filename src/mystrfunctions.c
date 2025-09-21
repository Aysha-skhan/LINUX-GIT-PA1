#include "../include/mystrfunctions.h"

// Returns the length of the string s
int mystrlen(const char* s) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

// Copies src to dest, returns number of characters copied
int mystrcpy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return i;
}

// Copies up to n characters from src to dest, returns number of characters copied
int mystrncpy(char* dest, const char* src, int n) {
    int i = 0;
    for (; i < n && src[i] != '\0'; i++)
        dest[i] = src[i];
    for (; i < n; i++)
        dest[i] = '\0'; // pad with null
    return i;
}

// Appends src to dest, returns new length of dest
int mystrcat(char* dest, const char* src) {
    int dest_len = mystrlen(dest);
    int i = 0;
    while (src[i] != '\0') {
        dest[dest_len + i] = src[i];
        i++;
    }
    dest[dest_len + i] = '\0';
    return dest_len + i;
}

