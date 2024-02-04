#include <stdio.h>
#include <string.h>
#define MAXN 10

int rowb[MAXN], b1[2 * MAXN], b2[2 * MAXN];
int roww[MAXN], w1[2 * MAXN], w2[2 * MAXN];
int chess[MAXN][MAXN];
int n, count;

int cango(int x, int y, int p) {
	if (p == 2)
		return !rowb[y] && !b1[x + y] && !b2[x - y + n];
	else if (p == 3)
		return !roww[y] && !w1[x + y] && !w2[x - y + n];
}

void change(int x, int y, int p, int num) {
	if (p == 2) {
		rowb[y] = num;
		b1[x + y] = num;
		b2[x - y + n] = num;
	} else if (p == 3) {
		roww[y] = num;
		w1[y + x] = num;
		w2[x - y + n] = num;
	}
}

void DFS(int x, int m, int p) {
	if (m == 2 * n) {
		count++;
		return;
	}
	if (m >= n)
		p = 3;
	for (int i = 0; i < n; i++) {
		if (chess[x][i] == 1 && cango(x, i, p)) {
			chess[x][i] = p;
			change(x, i, p, 1);
			if (x == n - 1)
				DFS(0, m + 1, p);
			else if (x < n - 1)
				DFS(x + 1, m + 1, p);
			change(x, i, p, 0);
			chess[x][i] = 1;
		}
	}
}

int main() {
	int i, j;
	char temp[MAXN * 2][MAXN * 2];
	memset(rowb, 0, sizeof(rowb));
	memset(roww, 0, sizeof(roww));
	memset(b1, 0, sizeof(b1));
	memset(b2, 0, sizeof(b2));
	memset(w1, 0, sizeof(w1));
	memset(w2, 0, sizeof(w2));
	scanf("%d\n", &n);
	for (i = 0; i < n; i++)
		gets(temp[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			chess[i][j] = temp[i][j * 2] - '0';
	DFS(0, 0, 2);
	printf("%d", count);
	return 0;
}