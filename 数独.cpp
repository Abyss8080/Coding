#include <stdio.h>
#include <string.h>
int row[9][10], rank[9][10];
int cube[9][9];
char temp[20][20];
int grid[9][9];
int ans = 0;

int check(int x, int y, int num) {
	int i = x / 3 * 3 + y / 3;
	if (row[x][num] == 0 && rank[y][num] == 0 && cube[i][num] == 0) {
		return 1;
	}
	return 0;
}

void next(int x, int y, int *nx, int *ny) {
	for (; x < 9; x++)
		for (; y < 9; y++)
			if (grid[x][y] == 0) {
				*nx = x;
				*ny = y;
				return;
			}
}

void fillGrid(int x, int y) {
	if (ans == 0)
		return;
	int num = 1;
	for (num = 1; num <= 9; num++) {
		if (check(x, y, num)) {
			//£®x£¨y£©ÃÓ»Înum;
			grid[x][y] = num ;
			row[x][num] = rank[y][num] = 1;
			cube[x / 3 * 3 + y / 3][num] = 1;
			ans--;
			if (ans > 0) {
				int nx, ny;
				next(x, y, &nx, &ny);
				fillGrid(nx, ny);
			} else if (ans == 0)
				return;
		}
		//num≤ª∫œ  £¨(x,y)ª÷∏¥0;
		grid[x][y] = 0;
		row[x][num] = rank[y][num] = 0;
		cube[x / 3 * 3 + y / 3][num] = 0;
		ans++;
	}
}

int main() {
	int i, j;
	int x, y, flag = 0;
	memset(row, 0, sizeof(row));
	memset(rank, 0, sizeof(rank));
	memset(cube, 0, sizeof(cube));
	for (i = 0; i < 9; i++)
		gets(temp[i]);
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++)
			if (temp[i][j * 2] - '0' >= 0 && temp[i][j * 2] - '0' <= 9) {
				grid[i][j] = (int)(temp[i][j * 2] - '0');
			}
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++) {
			if (temp[i][j * 2] == '*') {
				grid[i][j] = 0;
				ans++;
				continue;
			}
			int t = grid[i][j];
			row[i][t] = rank[j][t] = 1;
			cube[x / 3 * 3 + y / 3][t] = 1;
		}
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)
			if (grid[i][j] == 0) {
				x = i;
				y = j;
				flag = 1;
				break;
			}
		if (flag)
			break;
	}
	fillGrid(x, y);
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}