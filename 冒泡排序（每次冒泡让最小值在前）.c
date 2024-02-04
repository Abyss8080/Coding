/*每次冒泡让最小的数据在前*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 10


void swap(int *a) {
	int i, j, t;
	int isprime = 0;
	for (j = 0; j < MAX - 1; j++) {
		for (i = MAX - 1; i > 0; i--) {
			if (a[i] < a[i - 1]) {
				t = a[i - 1];
				a[i - 1] = a[ i ];
				a[i ] = t;
				isprime = 1;
			}
		}
		if (isprime = 0)
			break;
	}
}


int main() {
	int a[MAX];
	int i;
	printf("\n冒泡排序法示例\n\n");
	printf("Input %d numbers:\n", MAX);
	for (i = 0; i < MAX; i++) {
		printf("\t%i>", i + 1);
		scanf("%d", &a[i]);
	}
	swap(a);

	printf("\n");
	printf("The sortedd numbers:\n");
	for (i = 0; i < MAX; i++)
		printf("%d\t", a[i]);
	system("PAUSE");
	return 0;
}