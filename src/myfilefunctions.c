#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"

// Counts lines, words, and characters in a file
int wordCount(FILE* file, int* lines, int* words, int* chars) {
    if (!file) return -1;

    int l = 0, w = 0, c = 0;
    char ch;
    int in_word = 0;

    while ((ch = fgetc(file)) != EOF) {
        c++;
        if (ch == '\n') l++;
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (in_word) {
                w++;
                in_word = 0;
            }
        } else {
            in_word = 1;
        }
    }
    if (in_word) w++; // last word
    *lines = l;
    *words = w;
    *chars = c;
    return 0;
}

// Searches lines containing search_str in a file
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    if (!fp || !search_str) return -1;

    char** result = NULL;
    char buffer[1024];
    int count = 0;

    while (fgets(buffer, sizeof(buffer), fp)) {
        if (strstr(buffer, search_str)) {
            result = realloc(result, (count + 1) * sizeof(char*));
            result[count] = malloc(strlen(buffer) + 1);
            strcpy(result[count], buffer);
            count++;
        }
    }

    *matches = result;
    return count;
}

