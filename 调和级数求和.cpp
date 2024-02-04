#include <stdio.h>

int main() {
	int K, n;
	double s = 0.0;
	long long int u = 1, v = 1;
	scanf("%d", &K);
	n = 1;
	do {
		s += 1.00 / n;
		n++;
	} while (s <= K);
	n--;
	printf("%d", n);
	return 0;
}