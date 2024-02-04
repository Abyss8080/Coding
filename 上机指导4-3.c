#include <stdio.h>

int main() {
	int n = 0;
	int x;
	int a, b, c, d;
	printf("请输入一个不大于四位的正整数：");
	scanf("%d", &x);
	if (x > 9999 || x <= 0)
		printf("您输入的数不符合要求。谢谢！");
	else if (x > 999)
		n = 4;
	else if (x > 99)
		n = 3;
	else if (x > 9)
		n = 2;
	else if (x >= 1)
		n = 1;



	a = x / 1000;
	b = x % 1000 / 100;
	c = x % 100 / 10;
	d = x % 10;

	if (n >= 1) {
		switch (n)

		{
			case 4:
				printf("%d*%d*%d*%d=%d\n", a, b, c, d, a * b * c * d);
				break;
			case 3:
				printf("%d*%d*%d=%d\n",  b, c, d,  b * c * d);
				break;
			case 2:
				printf("%d*%d=%d\n", c, d,  c * d);
				break;
			default:
				printf("%d=%d\n", d, d);
		}
	}
	return 0;
}