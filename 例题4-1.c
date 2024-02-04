#include <stdio.h>

int main() {
	int n;
	int m;
	printf("\n欢迎使用13的倍数判断程序\n");
	printf("请输入一个整数：");
	scanf("%d", &n);
	m = n % 13;
	if (m == 0)
//	if (m = 0)
		printf("%d是13的倍数。\n", n);

	else
		printf("%d不是13的倍数。\n", n);
	return 0;
}