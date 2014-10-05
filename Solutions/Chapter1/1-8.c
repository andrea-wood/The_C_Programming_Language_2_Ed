#include <stdio.h>
/* Tab, Space and New Line counter */
main(){
	int c, nl, tabs, blanks;

	nl = 0;
	tabs = 0;
	blanks = 0;

	while((c = getchar()) != EOF){
		if(c == '\n'){ ++nl; }
		if(c == '\t'){ ++tabs; }
		if(c == ' '){ ++blanks;}
	}
	printf("New Lines: %d, Blanks: %d, Tab: %d\n", nl, blanks, tabs);	
}