#include <stdio.h>

main(){
	float fahr, celsius;
	int mini, maxi, intervalle;

	mini = 0;
	maxi = 300;
	intervalle = 20;

	celsius = mini;
	printf("Celsius\b Fahr\n");
	while(fahr<=maxi){
		fahr = (celsius * 1.8) + 32;
		printf("%3.0f %6.1f\n", celsius, fahr);
		celsius = celsius + intervalle;
	}
}