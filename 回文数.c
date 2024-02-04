#include <stdio.h>

int main() {
	int n;
	int i = 0, j = 0;
	int k ;
	int x, y;
	k = 1;
	printf("请输入n：");
	scanf("%d", &n);
	int h[n][n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			h[i][j] = -1;
		}
	}/*初始化*/
	for (x = n, y = 0; k <= n * n; x--, y++	) {

		for (j = 0; j < x; j++) {
			if (h[y][j] == -1) {
				h[y][j] = k++;

			}
		}
		for (i = 0; i < x; i++) {
			if (h[i][x - 1] == -1) {
				h[i][x - 1] = k++;

			}
		}
		for (j = 0; j < x; j++) {
			if (h[x - 1][x - 2 - j] == -1) {
				h[x - 1][x - 2 - j] = k ++;

			}
		}
		for (i = 0; i < x ; i++) {
			if (h[x - 1 - i][y] == -1) {
				h[x - 1 - i][y] = k ++;

			}
		}
	}
	printf("n*n的回文数是：\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d\t", h[i][j]);
		}
		printf("\n");
	}
	return 0;
}
