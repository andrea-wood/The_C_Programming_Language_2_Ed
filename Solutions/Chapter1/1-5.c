#include <stdio.h>

main(){
	int fahr;

	printf("Fahr\b Celsius\n");
	for(fahr=300; fahr>=0; fahr = fahr-20){
		printf("%3d %6.1f\n", fahr, (fahr-32)/1.8);
	}
}	