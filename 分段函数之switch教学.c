#include <stdio.h>

int main() {
	double x, y;
	int type;
	scanf("%lf", &x);
	type = x >= 0;

	switch (type) {
		case 1:
			y = 2 * x;
			break;
		case 0:
			y = -1;
			break;
	}
	printf("f(x) = %f", y);
	return 0;
}