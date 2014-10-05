/*
Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>

#define MAXLEN 1000
#define MINLENGTH 81

int getLine(char line[], int lim);

int main(void){
	int len, c, i;               
	char line[MAXLEN];    

	while((len = getLine(line, MAXLEN)) > 0){
		if(len >= MINLENGTH){
			printf("This is line is > 80 characters: %s\n", line);
		}
	}
	return 0;
}

int getLine(char s[], int lim){
	int c, i;
	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c!='\n'; ++i){
		s[i] =  c;
	}
	if(c == '\n'){
		s[i++] = c;
	}
	s[i] = '\0';
	return i;
}
