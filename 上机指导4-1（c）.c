#include <stdio.h>

int main() {
	int x;
	int y = -1;
	scanf("%d", &x);
	if (x != 0)
		if (x > 0)
			y = 1;
		else
			y = 0;
	printf("y=%d", y);
	return 0;
}