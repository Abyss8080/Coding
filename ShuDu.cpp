#include <stdio.h>
#include <string.h>
int row[9][10], rank[9][10];
int cube[9][10];
char temp[20][20];
int grid[9][9];
int finish = 0;

int check(int x, int y, int num) {
	int i = x / 3 * 3 + y / 3;
	if (row[x][num] == 0 && rank[y][num] == 0 && cube[i][num] == 0) {
		return 1;
	}
	return 0;
}

void fillGrid(int x, int y) {
	if (finish)
		return;
	if (x == 9) {
		finish = 1;
		return;
	}
	while (grid[x][y] != 0) {
		if (y < 8)
			y++;
		else {
			y = 0;
			x++;
		}
		if (x == 9)
			return;
	}
	for (int i = 1; i <= 9 && finish == 0; i++) {
		if (check(x, y, i)) {
			grid[x][y] = i;
			row[x][i] = 1;
			rank[y][i] = 1;
			cube[x / 3 * 3 + y / 3][i] = 1;
//			printf("\n");
//			for (int k = 0; k < 9; k++) {
//				for (int j = 0; j < 9; j++) {
//					printf("%d ", grid[k][j]);
//				}
//				printf("\n");
//			}
			if (y < 8)
				fillGrid(x, y + 1);
			else
				fillGrid(x + 1, 0);
			if (!finish) {
				grid[x][y] = 0;
				row[x][i] = 0;
				rank[y][i] = 0;
				cube[x / 3 * 3 + y / 3][i] = 0;
			} else
				return;
		}
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
				continue;
			}
			int t = grid[i][j];
			row[i][t] = rank[j][t] = 1;
			cube[i / 3 * 3 + j / 3][t] = 1;
		}
	fillGrid(0, 0);
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	return 0;
}