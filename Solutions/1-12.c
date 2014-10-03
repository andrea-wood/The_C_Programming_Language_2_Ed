/* 
Write a program that prints its input one word per line
*/

#include <stdio.h>

#define WINSIDE 1 /* inside the word */
#define WOUTSIDE 0 /* outdside the word */

main(void){
	int c, state;

	state = WOUTSIDE;

	while((c = getchar()) != EOF){

		if(c != ' ' && c != '\n' && c != '\t'){ 
			state = WINSIDE;
			putchar(c);
		} else if (state == WINSIDE) {
			state = WOUTSIDE;
			putchar('\n');
		}


	}
	return 0;
}