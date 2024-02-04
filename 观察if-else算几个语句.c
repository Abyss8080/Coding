#include <stdio.h>

int main() {
	int x = 1, y = 11;
	while (x < y)
		if (x == 1) {
			printf("%d\n", x);
		} else {
			printf("%d\n", y);
		}
	return 0;

}