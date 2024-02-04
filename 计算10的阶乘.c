#include <stdio.h>
#include <stdlib.h>

long f(short int n) {
	int tmp, i;
	tmp = 1;
	if (n >= 2) {
		for (i = 1; i <= n; i++) {
			tmp *= i;
		}
	}
	return (long)tmp;
}

int main() {
	int a;
	long b;
	a = 10;
	b = f(a);
	printf("%d!=%ld\n", a, b);
	system("PAUSE");
	return 0;
}