/* 
Write a program to remove all trailing blanks and tabs from each line of input, 
and to delete entirely blank lines. 
*/


#include <stdio.h>
#define MAXLEN 1000

int getLine(char line[], int lim);

int main(void){
    int len, i, endl_pos;               
    char line[MAXLEN];    

    while((len = getLine(line, MAXLEN)) > 0){
        endl_pos = 0;
        // find the end of the line
        for(i = len - 1; (line[i] == ' ' || line[i] == '\t' || line[i] == '\n'); --i){
            endl_pos = i;
        }

        for(i = 0; i < endl_pos; ++i){
            printf("%c", line[i]);
        }
    }
    return 0;
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

