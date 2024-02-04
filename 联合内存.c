#include <stdio.h>
#include <stdlib.h>

int main() {
	union {
		unsigned int x;
		unsigned char y[4];
	} u;
	u.x = 37778122;
	printf("%d %d %d %d\n", u.y[0], u.y[1], u.y[2], u.y[3]);
	printf("%p %p %p %p\n", &u.y[0], &u.y[1], &u.y[2], &u.y[3]);

	system("PAUSE");
	return 0;
}