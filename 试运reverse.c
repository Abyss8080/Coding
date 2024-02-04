#include <stdio.h>

int reverse(int x) {
	int a = 0, b = 0;
	int t = x;
	while (t > 0) {
		a = t % 10;
		b = b * 10 + a;
		t /= 10;
	}
	if (x % 10 != 0) {
		;
	} else {
		printf("输入的整数个位为0.\n");

	}
//	printf("%d", b);
	return b;
}

int main() {

	int y;
	y = reverse(1450);
	printf("%d", y);
	return 0;
}