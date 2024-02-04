#include <stdio.h>
int main()

{
	int a, b, c;
	printf("请输入三个整数：");
	scanf("%d %d %d", &a, &b, &c);
	printf("%d+%d+%d=%d\n", a, b, c, a + b + c);


	return 0;
}