#include <stdio.h>  
#include <stdlib.h>  
#include <ctype.h>  
  
int countChars(FILE *file) {  
    int charCount = 0;  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        charCount++;  
    }  
    return charCount;  
}  
  
int countWords(FILE *file) {  
    int wordCount = 0;  
    int inWord = 0;  
    char ch;  
    while ((ch = fgetc(file)) != EOF) {  
        if (isspace(ch) || ch == ',') {  
            if (inWord) {  
                wordCount++;  
                inWord = 0;  
            }  
        } else {  
            inWord = 1;  
        }  
    }  
    if (inWord) {  
        wordCount++;  
    }  
    return wordCount;  
}  
  
int main(int argc, char *argv[]) {  
    if (argc != 3) {  
        printf("Usage: %s [-c|-w] <filename>\n", argv[0]);  
        return 1;  
    }  
  
    FILE *file = fopen(argv[2], "r");  
    if (!file) {  
        perror("Error opening file");  
        return 1;  
    }  
  
    if (argv[1][1] == 'c') { // Count characters  
        int charCount = countChars(file);  
        printf("%d\n", charCount);  
    } else if (argv[1][1] == 'w') { // Count words  
        int wordCount = countWords(file);  
        printf("%d\n", wordCount);  
    } else {  
        printf("Invalid parameter: %s\n", argv[1]);  
        fclose(file);  
        return 1;  
    }  
  
    fclose(file);  
    return 0;  
}