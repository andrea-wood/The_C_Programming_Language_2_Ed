/* 
Write a program to copy its input to its output, 
replacing each string of one or more blanks 
by a single blank. 
*/

#include <stdio.h>

main(void){
	int c, cblanks;

	cblanks = 0;

	while((c = getchar()) != EOF){
		if(c == ' '){ 
			if(cblanks == 0){
				cblanks = 1;
				putchar(c);
			}
		}
		if(c != ' '){ 
			cblanks = 0;
			putchar(c);
		}
	}
	return 0;
}