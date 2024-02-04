#include <stdio.h>

int main() {
	int x;
	scanf("%d", &x);
	int y = 0;
	if (x >= 0) {
		if (x > 0)
			y = 1;
	} else
		y = -1;
	printf("y=%d", y);
	return 0;
}