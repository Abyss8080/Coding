#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int a = 4, b = 7;
	int n;
	n = sizeof(a++);

	printf("%d%d\n", n, a);

	return 0;
}