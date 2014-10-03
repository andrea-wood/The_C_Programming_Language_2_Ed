#include <stdio.h>

main(){
	float fahr, celsius;
	int mini, maxi, intervalle;

	mini = 0;
	maxi = 300;
	intervalle = 20;

	fahr = mini;
	printf("F\t C\n");
	while(fahr<=maxi){
		celsius = (5.0/0.9) * (fahr-32.0);
		printf("%3.0f %6.1f\n", fahr, celsius);
		fahr = fahr + intervalle;
	}
}