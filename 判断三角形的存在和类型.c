//判断三角形的存在和类型
#include <stdio.h>
#include <stdlib.h>

#define x(a) (a*a)

int main() {
	int a = 0, b = 0, c = 0;
	int t = 0;
	int m = 0;
	printf("\n\n输入三个整数:\n""比如：2 1 3\n");
	scanf("%d %d %d", &a, &b, &c);

	if (a < b) {
		t = a;
		a = b;
		b = t;
	}

	if (a < c) {
		t = a;
		a = c;
		c = t;
	}
	if (c > b) {
		t = c;
		c = b;
		b = t;
	}

	if ((c + b - a) <= 0) {
		printf("这三边不能构成三角形。\n");
	} else {
		printf("这三边可以构成三角形。\n");
		if (b == c && a != b) {
			printf("该三角形是等腰三角形。\n");
		} else if (a == c && c == b) {
			printf("该三角形是等边三角形。\n");
		}
		m = x(b) + x(c) - x(a);
		if (m > 0) {
			printf("该三角形是锐角三角形。\n");
		} else if (m == 0) {
			printf("该三角形是直角三角形。\n");
		} else if (m < 0) {
			printf("该三角形是钝角三角形。\n");
		}
	}


	system("PAUSE");
	return 0;
}