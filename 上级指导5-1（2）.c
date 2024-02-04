#include <stdio.h>
#include <math.h>
void printstar();
void printmessage();

int main() {
	double x;
	printf("Pleasee input a number:");
	scanf("%lf", &x);


	printstar();
	printmessage();
	printf("%.4f\n", sqrt(fabs(x)));
	printstar;
	return 0;

}

void printstar() {
	printf("**********\n");

}


void printmessage() {
	printf("The result is ");
}