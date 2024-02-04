#include <stdio.h>

int main() {
	int x = 0;
	int i;
	i = (int)&x;
	printf("0x%x\n", i);
	printf("%p\n", &x);
	printf("%lu\n", sizeof(int));
	printf("%lu\n", sizeof(&x));
	int y = 23;
	printf("%x", y);
	return 0;

}