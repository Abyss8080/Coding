#include <stdio.h>
#define max 10

void sums(double *a, int num, double *positive, double *negetive, int *n, int *p);
int main() {
	double positive = 0, negetive = 0; /*求和*/
	int P = 0, N = 0; /*个数*/
	double b[max];
	printf("\nInput %d  needed numbers:\n\n", max);

	sums(b, max, &positive, &negetive, &N, &P);

	printf("正数和:%.3f\t正数个数:%d \n负数和:%.3f\t负数个数:%d", positive, P, negetive, N);

}

void sums(double *a, int num, double *positive, double *negetive, int *n, int *p) {
	int i, j;
	for (i = 0; i < num; i++) {
		scanf("%lf", &a[i]);

	}
	for (j = 0; j < num; j++) {
		if (a[j] > 0) {
			*positive += a[j];
			*p += 1;
		} else if (a[j] < 0) {
			*negetive += a[j];
			*n += 1;
		} else if (a[j] == 0) {
			;
		}
	}

}