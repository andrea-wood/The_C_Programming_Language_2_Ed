/* 
Write a program to remove all comments to a C program
*/ 

#include <stdio.h>
#define MAXLEN 1000


int getLine(char line[], int lim);

int main(){
    int len, i, flag;               
    char s[MAXLEN];

    while((len = getLine(s, MAXLEN)) != 0){
        i = 0;
        flag = 0;

        while(s[i] != '\0') {
            if(flag){
                if(s[i] == '*' && s[i+1] == '/'){
                    flag = 0;
                    i++;
                }
            } else {
                if(s[i] == '/' && s[i+1] == '/'){
                    flag = 1;
                } else if(s[i] == '/' && s[i+1] == '*'){
                    i++;
                    flag = 1;
                } else {
                    printf("%c", s[i]);
                }
            }
            i++;

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