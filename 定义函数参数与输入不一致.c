#include <stdio.h>

void cheer(int a) {
	if (a == 1)
		printf("cheers!");
	else
		printf("no!");
}

int main() {
	cheer(1.9567);
	return 0;
}