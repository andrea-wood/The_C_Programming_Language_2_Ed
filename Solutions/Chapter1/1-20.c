/*
Write a program detab that replaces tabs in the input with the proper number of blanks to space to the next tab stop. 
Assume a fixed set of tab stops, say every n columns. Should n be a variable or a symbolic parameter?
*/

#include <stdio.h>
#define NCOL 4
#define SP ' '
#define MAXLEN 1000

int getLine(char line[], int lim);
void detab(char s[], char ns[], int len);

int main(){
    int len;               
    char line[MAXLEN];
    char newLine[MAXLEN];  

    while((len = getLine(line, MAXLEN)) != 0){
    	detab(line, newLine, len);
        printf("%s", newLine);
    }
	return 0;
}

void detab(char s[], char ns[], int len){
	int i, j, x;
	x = 0;

	for(i = 0; i < len; ++i){
        if(s[i] == '\t'){
        	for(j = 0; j < NCOL; ++j){
        		ns[x] = SP;
        		++x;
        	}     	
        } else{
        	ns[x] = s[i];
        	++x;
        }
    }
    ns[++x] = '\0';
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