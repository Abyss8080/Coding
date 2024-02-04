#include <stdio.h>
#define MAX 100000

int main() {
	int shop[MAX], n, m;
	int i, a, b;
	long long int c;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		shop[i] = 0;
	for (i = 0; i < m; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		shop[a - 1] += c;
		shop[b - 1] += c;
	}
	c = 0;
	a = 0;
	for (i = 0; i < n; i++) {
		if (shop[i] > c) {
			a = i + 1;
			c = shop[i];
		}
	}
	printf("%d", a);
	return 0;
}