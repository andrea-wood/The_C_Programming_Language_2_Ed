/*
Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>
#define MAXLEN 1000

int getLine(char line[], int lim);
void reverse(char s[], int max);

int main(void){
    int len, i, endl_pos;               
    char line[MAXLEN];    

    while((len = getLine(line, MAXLEN)) > 0){
        reverse(line, len);
        printf("%s", line);
    }
    return 0;
}

void reverse(char s[], int max){
    int i, j;
    char rs;
    j = max - 2;

    for(i = 0; i < j; ++i){
            rs = s[i];
            s[i] = s[j]; 
            s[j] = rs;
            --j;
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

