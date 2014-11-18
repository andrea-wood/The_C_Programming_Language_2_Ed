/*
Write a program to "fold" long input lines into two or more shorter lines 
after the last non-blank character that occurs before the n-th column of input. 
Make sure your program does something intelligent with very long lines, 
and if there are no blanks or tabs before the specified column.
*/

#include <stdio.h>
#define NCOL 8
#define TB '\t'
#define MAXLEN 1000


int getLine(char line[], int lim);
void fold(char s[], char ns[]);

int main(){
    int len;               
    char line[MAXLEN];
    char foldedLine[MAXLEN];

    while((len = getLine(line, MAXLEN)) != 0){
        fold(line, foldedLine);
        printf("%s", foldedLine);
    }
    return 0;
}

void fold(char s[], char ns[]){
    int i;

    for(i = 0; s[i] != '\0'; ++i){
        ns[i] = s[i];
        if((i % NCOL == 0) && i > 0){
            ns[i] = '\n';
        }
    }
    
}

int getLine(char s[], int lim){
    int c, i;
    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i){
        s[i] =  c;
    }

    if(c == '\n'){
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}