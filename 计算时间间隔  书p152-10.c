#include <stdio.h>
#include <math.h>

int second(int i, int j, int k) {
	return (i * 60 + j) * 60 + k;
}

int main() {
	int x, y, z;
	int h1, m1, s1, h2, m2, s2;
	printf("����������������ʱ�䣺\n����������7ʱ8��6���9ʱ12��17�룬������7 8 6��9 12 17��\n");
	scanf("%d %d %d,%d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
	x = second(h1, m1, s1);
	y = second(h2, m2, s2);
	z = fabs(x - y);
	printf("����ʱ����%d�롣", z);
	return 0;
}