/* 
Write a program to copy its input to its output, 
replacing each tab by \t , each backspace by \b , and each backslash by \\ . 
This makes tabs and backspaces visible in an unambiguous way.
*/

#include <stdio.h>

main(void){
	int c, counter;

	while((c = getchar()) != EOF){
		counter = 0;

		if(c == '\t'){ 
			putchar('\\');
			putchar('t');
			counter = 1;
		}

		if(c == '\\'){ 
			putchar('\\');
			putchar('\\');
			counter = 1;
		}

		if(c == '\b'){ 
			putchar('\\');
			putchar('b');
			counter = 1;
		}

		if(counter == 0){
			putchar(c);
		}
	}
	return 0;
}