#include <stdio.h>
#include <string.h>
#define Max(a,b) ((a)>(b)?(a):(b))
#define MAXN 20
int a[MAXN][MAXN], has[MAXN], n, ans = 0;

int h(int x) {
	int i, j;
	int sum = 0, max;
	for (i = x + 1; i <= n; i++) {
		max = 0;
		for (j = 1; j <= n; j++) {
			if (a[i][j] > max && has[j] == 0) {
				max = a[i][j];
			}
		}
		sum += max;
	}
	return sum;
}

void DFS(int x, int nowall) {
	ans = Max(ans, nowall);
	if (x == n + 1)
		return;
	if (h(x - 1) + nowall <= ans)
		return;
	for (int i = 1; i <= n; i++) {
		if (has[i] == 0) {
			has[i] = 1;
			DFS(x + 1, nowall + a[x][i]);
			has[i] = 0;
		}
	}
}

int main() {
	int i, j;
	memset(a, 0, sizeof(a));
	memset(has, 0, sizeof(has));
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	DFS(1, 0);
	printf("%d", ans == 0 ? -1 : ans);
	return 0;
}