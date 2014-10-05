/* 
Rewrite the temperature conversion program of Section 1.2 
to use a function for conversion. 
*/
#include <stdio.h>

float celsiusToFahr(float celsius);

main(){
	float fahr, celsius;
	int mini, maxi, intervalle;

	mini = 0;
	maxi = 300;
	intervalle = 20;

	celsius = mini;
	printf("Celsius\b Fahr\n");
	while(fahr<=maxi){
		fahr = celsiusToFahr(celsius);
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + intervalle;
	}
}

float celsiusToFahr(float celsius){
	float fahr;
	fahr = (celsius * 1.8) + 32;
	return fahr;
}	