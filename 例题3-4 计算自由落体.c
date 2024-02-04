#include <stdio.h>

#define GRAVITY 9.81
int main()

{
	double t, y, v;
	printf("\n\nWelcome.\n"
	       "Calculate the height from which a grapefruit fell\n"
	       "given the number of seconds that is was falling.\n\n");


	printf("Input seconds:");

	scanf("%lg", &t);

	y = .5 * GRAVITY * t * t;
	v = GRAVITY * t;

	printf("Time of fall=%g seconds\n", t);
	printf("Distance of fall=%g meters\n", y);
	printf("Velocity of fall=%g m/s\n", v);
	return 0;
}