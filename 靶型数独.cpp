#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int row[9][10], rank[9][10];
int cube[9][10], score, has, gra;
char temp[20][20];
int grid[9][9];

int grade[9][9] = {
	{6, 6, 6, 6, 6, 6, 6, 6, 6},
	{6, 7, 7, 7, 7, 7, 7, 7, 6},
	{6, 7, 8, 8, 8, 8, 8, 7, 6},
	{6, 7, 8, 9, 9, 9, 8, 7, 6},
	{6, 7, 8, 9, 10, 9, 8, 7, 6},
	{6, 7, 8, 9, 9, 9, 8, 7, 6},
	{6, 7, 8, 8, 8, 8, 8, 7, 6},
	{6, 7, 7, 7, 7, 7, 7, 7, 6},
	{6, 6, 6, 6, 6, 6, 6, 6, 6},
};

int check(int x, int y, int num) {
	int i = x / 3 * 3 + y / 3;
	if (row[x][num] == 0 && rank[y][num] == 0 && cube[i][num] == 0) {
		return 1;
	}
	return 0;
}

void fillGrid(int x, int y) {
	if (x == 9) {
		score = score >= gra ? score : gra;
		has = 1;
		return;
	}
	while (grid[x][y] != 0) {
		if (y < 8)
			y++;
		else {
			y = 0;
			x++;
		}
		if (x == 9) {
			score = score >= gra ? score : gra;
			has = 1;
			return;
		}
	}
	for (int i = 1; i <= 9; i++) {
		if (check(x, y, i)) {
			grid[x][y] = i;
			row[x][i] = 1;
			rank[y][i] = 1;
			cube[x / 3 * 3 + y / 3][i] = 1;
			gra = gra + i * grade[x][y];
			if (y < 8)
				fillGrid(x, y + 1);
			else
				fillGrid(x + 1, 0);
			grid[x][y] = 0;
			row[x][i] = 0;
			rank[y][i] = 0;
			cube[x / 3 * 3 + y / 3][i] = 0;
			gra = gra - i * grade[x][y];
		}
	}
}


int main() {
	int i, j;
	int x, y;
	memset(row, 0, sizeof(row));
	memset(rank, 0, sizeof(rank));
	memset(cube, 0, sizeof(cube));
	for (i = 0; i < 9; i++)
		gets(temp[i]);
	for (i = 0; i < 9; i++)
		for (j = 0; j < 9; j++) {
			grid[i][j] = (int)(temp[i][j * 2] - '0');
			int t = grid[i][j];
			if (t != 0) {
				row[i][t] = rank[j][t] = 1;
				cube[i / 3 * 3 + j / 3][t] = 1;
				gra = gra + grade[i][j] * t;
			}
		}
	fillGrid(0, 0);
	if (has)
		printf("score=%d\n", score);
	else
		printf("-1\n");
	return 0;
}