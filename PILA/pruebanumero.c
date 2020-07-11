#include<stdio.h>


int main(void){

	float i =0.0;
	int j =0;
	for(j=1; j<=1000;j++)
		i = i + 0.125;
	printf("%f\n",i);

	return 0;

}