#include <stdio.h>

int fat(int n) {
//	static int f = 1;
	int f = 1;
	f = f * n - 1;
	return f;
}

int main() {
	int i;
	for (i = 1; i <= 5; i++)
		printf("%d\t", fat(i));


	return 0;
}