#include <stdio.h>

int main() {
	int matrix[100][100];
	int m;
	int n;
	while (scanf("%d %d", &m, &n) != EOF) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}
		int i, j, count, numbers;
		i = j = count = 0;
		numbers = 0;
		int x = 0, y = 0;
		while (numbers < m * n) {
			for (i = 0; i < n - count * 2; i++) {
				printf("%d", matrix[x][y + i]);
				numbers++;
				if (numbers < m * n)
					printf(" ");
			}
			if (numbers == m * n)
				break;
			y = y + i - 1;
			x = x + 1;
			for (i = 0; i < m - (count * 2 + 1); i++) {
				printf("%d", matrix[x + i][y]);
				numbers++;
				if (numbers < m * n)
					printf(" ");
			}
			if (numbers == m * n)
				break;
			x = x + i - 1;
			y = y - 1;
			for (i = 0; i < n - count * 2 - 1; i++) {
				printf("%d", matrix[x][y - i]);
				numbers++;
				if (numbers < m * n)
					printf(" ");
			}
			if (numbers == m * n)
				break;
			x = x - 1;
			y = y - i + 1;
			for (i = 0; i < m - count * 2 - 2; i++) {
				printf("%d", matrix[x - i][y]);
				numbers++;
				if (numbers < m * n)
					printf(" ");
			}
			if (numbers == m * n)
				break;
			y = y + 1;
			x = x - i + 1;
			count++;
		}
	}
	return 0;
}