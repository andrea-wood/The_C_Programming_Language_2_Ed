/*
Write a program entab that replaces strings of blanks with the minimum number of tabs and blanks to achieve the same spacing. 
Use the same stops as for detab . 
When either a tab or a single blank would suffice to reach a tab stop, which should be given preference?
*/
#include <stdio.h>
#define NCOL 8
#define TB '\t'
#define MAXLEN 1000

int getLine(char line[], int lim);
void entab(char s[], char ns[]);

int main(){
    int len;               
    char line[MAXLEN];
    char newLine[MAXLEN];  

    while((len = getLine(line, MAXLEN)) != 0){
    	entab(line, newLine);
        printf("%s", newLine);
    }
	return 0;
}

void entab(char s[], char ns[]){
	int i, x;
	x = 0;

	for(i = 0; s[i] != '\0'; ++i){
        if(s[i] == ' ' && ((i + 1) % NCOL == 0)){
            ns[x] = TB;
            ++x;
            i = i + ((NCOL - i % NCOL) - 1);
        } else{
        	ns[x] = s[i];
        	++x;
        }
    }
 	ns[x] = '\0';
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