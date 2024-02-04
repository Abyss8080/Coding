#include <stdio.h>

int main() {
	int K, n;
	double s = 0.0;
	scanf("%d", &K);
	n = 1;
	while (s <= K) {
		s += 1.0 / n;
		n++;
	}
	n--;
	printf("%d", n);
	return 0;
}