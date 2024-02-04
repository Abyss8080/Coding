#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void best(const int g[], int *ai, int *a) {
	int n = 0;
	for (n = 0; n < 10; n++) {
		if (*ai < g[n]) {
			*ai = g[n];
			* a = n;
		}
	}
}

void worst(const int g[], int *bi, int *b) {
	int j = 0;
	for (j = 0; j < 10; j++) {
		if (*bi > g[j]) {
			*bi = g[j];
			* b = j;
		}
	}
}


void aver(const int g[], int *ci, int *c) {
	double ave = 0.0;
	int k = 0;
	double a[10];
	double clo;
	for (k = 0; k < 10; k++) {
		ave = (ave + g[k]) / 2;
	}
	printf("\naverage=%f\n", ave);
	for (k = 0; k < 10; k++) {
		a[k] = fabs(g[k] - ave);
	}
	clo = a[0];
	for (k = 0; k < 10; k++) {
		if (clo > a[k]) {
			clo = a[k];
			*ci = g[k];
			*c = k;
		}
	}
}

int main() {
	long long int ID[10] = {7894, 23923, 543, 57923, 78432, 49, 8782, 6384, 3782, 29852};
	int grade[10] = {38, 45, 65, 76, 78, 45, 90, 100, 28, 10};
	int i = 0;
	int a = 0, b = 0, c = 0;
	int ai = grade[0], bi = grade[0], ci = grade[0];


//	printf("Input the ID numbers and respective grades:\n");

//	for (i = 0; i < 10; i++) {
//		printf("\nStudent %d:", i + 1);
//		scanf("%lld%d", &ID[i], &grade[i]);
//	}
	best(grade, &ai, &a);
	worst(grade, &bi, &b);
	aver(grade, &ci, &c);

	printf("最佳学生:%lld\n分数:%d\n\n", ID[a], ai);
	printf("最差学生:%lld\n分数:%d\n\n", ID[b], bi);
	printf("最接近平均分的学生:%lld\n分数:%d\n\n", ID[c], ci);
	system("PAUSE");
	return 0;
}