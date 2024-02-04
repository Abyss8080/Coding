#include <stdio.h>

int main() {
	int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9,};
	int *p = &a[3];
	int n;
	for (n = -3; n < 10; n++) {
		printf("p[%d]=%d\n", n, p[n]);
	}

	return 0;
}