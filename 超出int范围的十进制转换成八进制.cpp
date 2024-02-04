#include <stdio.h>
int g, c[1000];
long long int x;

int main() {
	scanf("%lld", &x);
	g = 0;
	if (x == 0) {
		printf("0");
		return 0;
	} else if (x < 0) {
		x = 0 - x;
		printf("-");
	}

	while (x > 0) {
		c[g++] = x % 8;
		x /= 8;
	}
	g--;
	for (int i = g; i >= 0; i--) {
		printf("%d", c[i]);
	}
	return 0;
}
