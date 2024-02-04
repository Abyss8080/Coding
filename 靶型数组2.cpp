#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int row[9][10], rank[9][10];
int cube[9][10], score, has, gra;
char temp[20][20];
int grid[9][9];
int zmf[10];

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

void fillGrid(int t, int y) {
	int x = zmf[t];
	if (t == 9) {
		score = score >= gra ? score : gra;
		has = 1;
		return;
	}
	while (grid[x][y] != 0) {
		if (y < 8)
			y++;
		else {
			y = 0;
			t++;
			x = zmf[t];
		}
		if (t == 9) {
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
				fillGrid(t, y + 1);
			else
				fillGrid(t + 1, 0);
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
	int zero[10][10], p = 0;
	memset(row, 0, sizeof(row));
	memset(rank, 0, sizeof(rank));
	memset(cube, 0, sizeof(cube));
	memset(zmf, 0, sizeof(zmf));
	memset(zero, 0, sizeof(zero));
	for (i = 0; i < 9; i++)
		gets(temp[i]);
	for (i = 0; i < 9; i++) {
		p = 0;
		for (j = 0; j < 9; j++) {
			grid[i][j] = (int)(temp[i][j * 2] - '0');
			int q = grid[i][j];
			if (q != 0) {
				row[i][q] = rank[j][q] = 1;
				cube[i / 3 * 3 + j / 3][q] = 1;
				gra = gra + grade[i][j] * q;
			}
			if (q == 0)
				p++;
		}
		zero[p][i] = 1;
	}
	p = 0;
	for (i = 0; i <= 9; i++)
		for (j = 0; j < 9; j++)
			if (zero[i][j] != 0)
				zmf[p++] = j;
	fillGrid(0, 0);
	if (has)
		printf("score=%d\n", score);
	else
		printf("-1\n");
	return 0;
}