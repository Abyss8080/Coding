#include <stdio.h>

int peach(int x, int y) {
	int t;
	if (x == 1)
		t = y;
	else {
		y = (y + 1) * 2;
		peach(x - 1, y);
	}
	return y;
}

int main() {
	int t, x, y;
	printf("请输入日期和相应的桃子剩余数："
	       "如若第10天剩余1个，则输入10 1\n");
	scanf("%d %d", &x, &y);
	t = peach(x, y);
	printf("第一天共摘%d个桃。", t);
	return 0;
}