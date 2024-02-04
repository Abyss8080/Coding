#include <stdio.h>
#include <string.h>
#define MAX 1000
int map[MAX][MAX];
int d[MAX][MAX];
int n, m, r, a, b;

int main() {
	int i, j, k;
	int  x, y;
	int len;
	scanf("%d", &n);
	scanf("%d", &m);
	memset(d, 0x3f3f3f3f, sizeof(d));
	for (i = 1; i <= m; i++) {
		scanf("%d %d %d", &x, &y, &k);
		map[x][y] = map[y][x] = k;
		d[x][y] = d[y][x] = 0;
	}
	scanf("%d", &r);
	for (k = 1; k <= r; k++) {
		scanf("%d %d", &i, &j);
		d[i][j] = d[j][i] = map[i][j];
	}
	for (k = 1; k <= n; k++) {
		for (i = 1; i <= n; i++) {
			for (j = 1; j <= n; j++) {
				if (d[i][j] > d[i][k] + d[k][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}
	scanf("%d %d", &a, &b);
	printf("%d", d[a][b]);

	return 0;
}
