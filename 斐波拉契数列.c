#include <stdio.h>

long long Fibo(int n) {
	int i = 2;
	long long fib[n + 1];
	/*4*8bit¡ª¡ª¡ª¡ª45Ïî
	8*8bit¡ª¡ª¡ª¡ª91Ïî*/
	fib[0] = 1;
	fib[1] = 1;
	for (i = 2; i <= n; i++) {
		fib[i] = 10 * fib[i - 1] + 10 * fib[i - 2];
	}
	return fib[n];
}

int main() {
	int x;
	long long y;
	int number = 98  ;
	for (x = 0; x <= number; x++) {
		y = Fibo(x);
		printf(" fib[%d]=%lld\n", x, y);
	}
	return 0;
}
