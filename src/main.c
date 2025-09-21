#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");

    char s1[50] = "Hello";
    char s2[] = "World";

    printf("mystrlen(s1) = %d\n", mystrlen(s1));
    printf("mystrcpy(s1, s2) = %d, s1 = %s\n", mystrcpy(s1, s2), s1);

    char s3[50];
    printf("mystrncpy(s3, s1, 3) = %d, s3 = %s\n", mystrncpy(s3, s1, 3), s3);

    printf("mystrcat(s1, s2) = %d, s1 = %s\n", mystrcat(s1, s2), s1);

    printf("\n--- Testing File Functions ---\n");

    FILE* fp = fopen("testfile.txt", "r");
    if (!fp) {
        printf("Error: Could not open testfile.txt\n");
        return 1;
    }

    int lines, words, chars;
    if (wordCount(fp, &lines, &words, &chars) == 0) {
        printf("Lines: %d, Words: %d, Characters: %d\n", lines, words, chars);
    }
    rewind(fp);

    char** matches;
    int count = mygrep(fp, "search", &matches);
    printf("Found %d matching lines:\n", count);
    for (int i = 0; i < count; i++) {
        printf("%s", matches[i]);
        free(matches[i]);
    }
    free(matches);

    fclose(fp);
    return 0;
}

