#include <stdio.h>

int main() {
	int matrix[100][100];
	int m;
	int n;
	int i, j;
	int k, t;
	while ((scanf("%d %d", &m, &n)) != EOF) {
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		i = 0;
		j = 0;
		printf("%d", matrix[i][j]);
		while (i != m - 1 || j != n - 1) {
			if ((i == 0 || i == m - 1) && j + 1 != n) {
				j = j + 1;
			} else if (j == 0 || j == n - 1) {
				i = i + 1;
			}
			if (i == m - 1 && j == n - 1)
				break;
			if (i == 0 || j == n - 1) {
				for (k = i, t = j; k < m && t >= 0; k++, t--) {
					printf(" %d", matrix[k][t]);
					i = k;
					j = t;
				}
			} else {
				for (k = i, t = j; k >= 0 && t < n; k--, t++) {
					printf(" %d", matrix[k][t]);
					i = k;
					j = t;
				}
			}
		}
		if (m != 1 && n != 1)
			printf(" %d", matrix[m - 1][n - 1]);
	}
	return 0;
}