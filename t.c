#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 12, b = 99, c = 23;
	printf("%d\b0 %d0 %d0\n", a, b, c);

	printf("a->%p\nb->%p\nc->%p\n", &a, &b, &c);
	system("PAUSE");
	return 0;
}