#include <stdio.h>

void minmax(int *a, int len, int *min, int *max) {
	int i;
	*min = *max = a[0];
	printf("minmax sizeof(a)=%lu\n.", sizeof(a));
	for (i = 0; i < len; i++) {
		if (a[i] < *min) {
			*min = a[i];
		}
		if (a[i] > *max) {
			*max = a[i];
		}
	}

}

int main () {
	int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 12, 13, 14, 15, 23, 25, 55, 87};
	int min, max ;
	int len;
	len = sizeof(a) / sizeof(a[0]);
	printf("main sizeof(a)=%lu\n.", sizeof(a));
	void minmax(a, len, &min, &max);
	printf("min=%d,max=%d", min, max);
	return 0;

}

