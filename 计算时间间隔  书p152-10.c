#include <stdio.h>
#include <math.h>

int second(int i, int j, int k) {
	return (i * 60 + j) * 60 + k;
}

int main() {
	int x, y, z;
	int h1, m1, s1, h2, m2, s2;
	printf("请输入需计算的两个时间：\n（如若输入7时8分6秒和9时12分17秒，则输入7 8 6，9 12 17）\n");
	scanf("%d %d %d,%d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
	x = second(h1, m1, s1);
	y = second(h2, m2, s2);
	z = fabs(x - y);
	printf("两个时间间隔%d秒。", z);
	return 0;
}