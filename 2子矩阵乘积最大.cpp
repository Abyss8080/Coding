#include <stdio.h>

int main() {
	int n, m;
	scanf("%d %d", &m, &n);
	int matrix[100][100];
	int i, j, max, maxi, maxj, multiple;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			scanf("%d", matrix[i][j]);
		}
	}
	max = 0;
	maxi = 0;
	maxj = 0;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			if (i + 1 < m && j + 1 < n) {
				multiple = matrix[i][j] * matrix[i + 1][j] * matrix[i][j + 1] * matrix[i + 1][j + 1];
				if (multiple > max) {
					max = multiple;
					maxi = i;
					maxj = j;
				}
			}
		}
	}
	printf("%d\n", max);
	printf("%d %d\n%d %d", matrix[maxi][maxj], matrix[maxi][maxj + 1],
	       matrix[maxi + 1][maxj], matrix[maxi + 1][maxj + 1]);

	return 0;
}