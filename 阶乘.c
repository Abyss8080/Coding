#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 1, x = 1;
	while (n++ < 10) {
		x = x * n;
		printf("%0d %0d\n", n, x);

	}


	system("PAUSE");
	return 0;
}
