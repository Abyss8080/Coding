#include <stdio.h>
#include <stdlib.h>

int main() {
	int i, j;
	printf("\n欢迎使用九九乘法表程序\n");

	for (i = 1; i < 10; ++i) {
		for (j = 1; j <= i; ++j) {
			printf("%ld*%ld=%-4d", j, i, i * j);
		}
		printf("\n");
	}

	system("PAUSE");
	return 0;
}