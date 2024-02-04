#include <stdio.h>

int main() {
	int i;
//	int sum = 0;
	int sum;
	printf("\nWelcom.\n"
	       "Calculate the result of 1+2......+100\n\n");
	for (i = 1; i <= 100; i++)
		sum += i;

	printf("1+2......+100=%d\n", sum);
	return 0;
}