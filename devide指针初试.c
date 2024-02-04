#include <stdio.h>

int devide(int x, int y, double *result) {
	int t = 1;
	if (y == 0) {
		t = 0;
	} else {
		*result = 1.0 * x / y;
	}
	return t;
}

int main() {
	int x = 0, y = 0;
	double c;

	scanf("%d %d", &x, &y);
	if (devide(x, y, &c)) {
		printf("%d/%d=%.2f\n", x, y, c);
	} else {
		printf("Your numbers do not cater to the condition.\n ");
	}

	return 0;

}

