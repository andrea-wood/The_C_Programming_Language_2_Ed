/*
Ex. 1-14: Write a program to print a histogram of the frequencies 
of different characters in its input.
*/

#include <stdio.h>

#define MAX_CHARS 255
#define ASCII_MINVAL 33
#define ASCII_MAXVAL 126


main(void){
	int c, i, j, x, counter, state, maxvalue;
	long chars_freq[MAX_CHARS+1];

	maxvalue = 0;
	for (i=0; i < MAX_CHARS; ++i){
		chars_freq[i] = 0;
	}

	while((c = getchar()) != EOF){
		if(c != ' ' && c != '\n' && c != '\t'){ 
			if(c >= ASCII_MINVAL && c <= ASCII_MAXVAL){
				++chars_freq[c];
				if(chars_freq[c] > maxvalue){
					maxvalue = chars_freq[c];
				}
			}
		} 
	}

	printf("\n\n\n");
	printf("**********************************\n");
	printf("* Histogram with vertical bars *\n");
	printf("**********************************\n\n");

	// draw verical section
	for (i = maxvalue; i >= 1; --i){
		
		printf("%4d|", i);
		
		for(j = ASCII_MINVAL; j <= ASCII_MAXVAL; ++j){
			if(chars_freq[j] >= i){
				printf("*");
			} else {
				printf(" ");
			}
		}
		printf("\n");
	}

	// draw horizontal section
	printf("    +");
	for (i = ASCII_MINVAL; i <= ASCII_MAXVAL; ++i){
		printf("-");
	}
	printf("\n");
	printf("     ");

	for (i = ASCII_MINVAL; i <= ASCII_MAXVAL; ++i){
		printf("%c", i);
	}
	printf("\n\n");
	return 0;
}