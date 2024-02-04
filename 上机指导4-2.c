#include <stdio.h>

int main() {
	float k = 1.0;
	int sum = 0;
	do {
		sum += k;
		k++;

	} while (k <= 100.0);
	printf("%d", sum);
	return 0 ;
}