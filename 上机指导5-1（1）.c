#include <stdio.h>
int add(int a);

int main() {
	int i, sum;
	for (i = 0; i <= 5; i++)
		sum = add(i);
	printf("sum=%d\n", sum);
	return 0;
}

int add(int a) {
	static int s = 0;
	s += a;
	return s;
}