#include <stdio.h>
#define max 10

void sums(double *a, int num, double *positive, double *negetive, int *n, int *p);
int main() {
	double positive = 0, negetive = 0; /*���*/
	int P = 0, N = 0; /*����*/
	double b[max];
	printf("\nInput %d  needed numbers:\n\n", max);

	sums(b, max, &positive, &negetive, &N, &P);

	printf("������:%.3f\t��������:%d \n������:%.3f\t��������:%d", positive, P, negetive, N);

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