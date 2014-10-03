/*
Write a program to print a histogram of the lengths of words in its input. 
It is easy to draw the histogram with the bars horizontal; 
a vertical orientation is more challenging.
*/

#include <stdio.h>

#define MAXWDLENGTH 10
#define WINSIDE 1 /* inside the word */
#define WOUTSIDE 0 /* outdside the word */

main(void){
	int c, i, j, x, counter, state, maxvalue, maxvalue_pos;
	int words_length[MAXWDLENGTH];



	for (i=0; i <= MAXWDLENGTH; ++i){
		words_length[i] = 0;
	}
	state = WOUTSIDE;
	maxvalue = maxvalue_pos =counter = 0;

	while((c = getchar()) != EOF){

		if(c != ' ' && c != '\n' && c != '\t'){ 
			state = WINSIDE;
			++counter;
		} else if (state == WINSIDE) {
			if(counter > 0 && counter < MAXWDLENGTH){
				++words_length[counter-1];
				if(words_length[counter-1] > maxvalue){
					maxvalue_pos = counter-1;
					maxvalue = words_length[counter-1];
				}
			} else if(counter > MAXWDLENGTH) {
				++words_length[MAXWDLENGTH];
				if(words_length[MAXWDLENGTH] > maxvalue){
					maxvalue_pos = MAXWDLENGTH;
					maxvalue = words_length[MAXWDLENGTH];
				}
			}

			counter = 0; //reset counter 
			state = WOUTSIDE;
		}
	}
	// add the last counter afte the EOF
	if(counter > 0){ 
		++words_length[counter-1]; 
		if(words_length[counter-1] > maxvalue){
			maxvalue_pos = counter-1;
			maxvalue = words_length[counter-1];
		}
	}

	/* Histogram with horizontal bars */
	printf("\n\n\n");
	printf("**********************************\n");
	printf("* Histogram with horizontal bars *\n");
	printf("**********************************\n\n");

	for (i = 0; i <= MAXWDLENGTH; ++i){

		if(i < MAXWDLENGTH){
			printf("%2d   |", i+1);
		} else {
			printf("> 10 | ");
		}

		for(j = 0; j < words_length[i]; ++j){
			printf("*");
		}

		printf("\n");
	
	}

	printf("\n\n\n");
	printf("**********************************\n");
	printf("* Histogram with vertical bars *\n");
	printf("**********************************\n\n");

	// draw verical section
	for (i = maxvalue; i >= 1; --i){
		
		printf("%4d|", i);
		
		for(j = 0; j <= MAXWDLENGTH; ++j){
			if(words_length[j] >= i){
				printf("*  ");
			} else {
				printf("   ");
			}
		}
		printf("\n");
	}

	// draw horizontal section
	printf("    +");
	for (i = 0; i <= MAXWDLENGTH; ++i){
		if(i < MAXWDLENGTH){
			printf("----");
		} else {
			printf("-----\n");
		}
	}
	printf("     ");
	for (i = 0; i <= MAXWDLENGTH; ++i){
		if(i < MAXWDLENGTH){
			printf("%d  ", i+1);
		} else {
			printf("> 10");
		}
	
	}
	printf("\n\n");
	return 0;
}