#include <stdio.h>

int main() {
	int A = 0, ret = 0;
	while ( scanf("%d", &A) != EOF) {
		ret = 0;
		if (A == 0)
			break;
		while (A % 2 == 0) {
			ret++;
			A = A / 2;
		}
		A = 1 << ret;
		printf("%d\n", A);
	}
	return 0;
}