#include <stdio.h>
#define MAXM 5000

typedef struct node {
	int p;
	int x;
} MilkMessage;

void SelectSort(MilkMessage *milk, int m) {
	int i, j, k;
	MilkMessage temp;
	for (i = 0; i < m - 1; i++) {
		k = i;
		for (j = i + 1; j < m; j++) {
			if (milk[j].p < milk[k].p)
				k = j;
		}
		if (k != i) {
			temp = milk[i];
			milk[i] = milk[k];
			milk[k] = temp;
		}
	}
}

int main() {
	int n, m;
	int i, sum = 0, addup = 0;
	MilkMessage milk[MAXM];
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &milk[i].p, &milk[i].x);
	}
	SelectSort(milk, m);
	for (i = 0; sum < n && i < m; i++) {
		sum += milk[i].x;
		addup += milk[i].p * milk[i].x;
	}
	if (sum > n)
		addup -= (sum - n) * milk[i - 1].p;
	printf("%d", addup);
	return 0;
}