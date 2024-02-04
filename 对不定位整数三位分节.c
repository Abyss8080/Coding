#include <stdio.h>
#include <stdlib.h>

int main () {
	int x;
	int i = 0, j = 0;
	int *p = (int *)malloc(10 * sizeof(int));
	/*x<4,294,967,296*/
	if (!p) {
		printf("Out of memory.\n");
		exit(1);
	}
	printf("Input a number:");
	scanf("%d", &x);
	for (i = 0; i < 10; i++) {
		p[i] = -1;
	}

	for (i = 0; x > 0; i++) {
		p[i] = x % 10;
		x /= 10;
	}

	for (j = 0; j <= i; j++) {
		if (p[i - j] != -1) {
			printf("%d", p[i - j]);
			if ((i - j) % 3 == 0 && (i - j) != 0)
				printf(",");
		}
	}


	return 0;

}