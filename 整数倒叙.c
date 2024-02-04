#include <stdio.h>

int main () {
	int a = 0;
	int b = 0;
	printf("请输入一个五位正整数：");
	scanf("%d", &a);
	do {
		b = a % 10;
		a /= 10;
		printf("%3d", b);
	} while (a > 10);
	printf("%3d", a);
	return 0;
}