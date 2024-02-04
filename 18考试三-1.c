#include <stdio.h>

int main() {
	int x[3][3] = { {1, 2}, {3, 4}, {5, 6} };
	int *p1 = x;
	int (*p2)[3] = x;
	printf("%p %p\n", p1, p2);
	printf("%d\n", p1 == p2);
	p1 += 2;
	printf("%p\n", p1);
	printf("%d\n", *p1);
	p2++;
	printf("%p\n", p2);
	printf("%d\n%d\n", *p2, **p2);
	p2++;
	printf("%d\n", p1 == p2);
	printf("%p %p", p1, p2);
	return 0;
}
