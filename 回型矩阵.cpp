#include <stdio.h>

int main() {
	int n, k;
	scanf("%d", &n);
	int matrix[100][100];
	int i, j, count = 1;
	if (n % 2 == 0)
		k = n / 2;
	else
		k = (n + 1) / 2;
	while (count <= k) {
		for (i = count - 1; i < n - count + 1; i++)
			matrix[count - 1][i] = count;
		for (i = count - 1; i < n - count + 1; i++)
			matrix[n - count][i] = count;
		for (i = count - 1; i < n - count + 1; i++)
			matrix[i][count - 1] = count;
		for (i = count - 1; i < n - count + 1; i++)
			matrix[i][n - count] = count;
		count++;
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}



	return 0;
}