#include <stdio.h>

double p(int x) {
	double t = 1.0;
	for (; x >= 1; x--) {
		t = t * x;
	}
	return t;
}

int main() {
	double s;
	s = 1 / p(2) + 1 / p(4) + 1 / p(6) + 1 / p(8) + 1 / p(10);
	printf("%lf", s);
	return 0 ;
}