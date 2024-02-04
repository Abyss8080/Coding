#include <stdio.h>

int gcd(int a, int b) {

	int n = 0, k = 0, t = 0;
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}
	if (a == 0)
		n = b;
	else {
		k = b % a;
		n = gcd(a, k);
	}


	return n;
}

int main() {
	int a = 1314, b = 1212;
	int res = 0;
	res = gcd(a, b);
	printf("%d和%d的最大公约数是%d。", a, b, res);

	return 0;
}