#include <stdio.h>
#include <math.h>
#define step 50

double f(int x) {

	return (sqrt(6 * x + 2));
}

int main() {
	int x = 0;
	double t = 0;
	for (x = 0; x <= 1000; x += step) {
		t += f(x);
		printf("%d\t%8.5f\t%8.5f\t\n", x, f(x), t);
	}
	return 0;
}