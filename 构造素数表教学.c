#include <stdio.h>
#define NUMBER 1000

int main() {
	int isPrime[NUMBER];
	for (int i = 0; i < NUMBER; i++) {
		isPrime[i] = 1;
	}
	int x = 2;
	while (x < NUMBER) {
		if (isPrime[x]) {
			for (int i = 2; x * i < NUMBER; i++) {
				isPrime[x * i] = 0;
			}
		}
		x++;
	}
	int y = 0;
	for (int i = 2 ; i < NUMBER; i++) {
		if (isPrime[i]) {
			printf("%d\t", i);
			y++;
			if (y == 5) {
				printf("\n");
				y = 0;
			}
		}

	}
	return 0;
}