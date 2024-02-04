#include <stdio.h>
#include <string.h>
#define MAXN 5


int dir[8][2] = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, -1}, {2, 1}, {-2, 1}, {-2, -1}};
char chess[MAXN][MAXN];
int T, minstep, prex, prey;

char ans[MAXN][MAXN]
= {
	'1', '1', '1', '1', '1',
	'0', '1', '1', '1', '1',
	'0', '0', '*', '1', '1',
	'0', '0', '0', '0', '1',
	'0', '0', '0', '0', '0',
};

int Min(int a, int b) {
	return a > b ? b : a;
}

int check(int x, int y) {
	return x >= 0 && x < MAXN && y >= 0 && y < MAXN;
}

int  h(void) {
	int count = 0;
	int i, j;
	for (i = 0; i < MAXN; i++)
		for (j = 0; j < MAXN; j++)
			if (ans[i][j] != chess[i][j])
				count++;
	return count - 1;
}

int mission(int depth) {
	int i, j;
	for (i = 0; i < MAXN; i++)
		for (j = 0; j < MAXN; j++)
			if (ans[i][j] != chess[i][j])
				return 0;
	minstep = Min(minstep, depth);
	return 1;
}

void swap(int x1, int y1, int x2, int y2) {
	char temp = chess[x1][y1];
	chess[x1][y1] = chess[x2][y2];
	chess[x2][y2] = temp;
}

void DFS(int x, int y, int depth, int prex, int prey) {
	if (mission(depth))
		return;
	if (depth == 15)
		return;
	for (int i = 0; i < 8; i++) {
		int tx = x + dir[i][0];
		int ty = y + dir[i][1];
		if (check(tx, ty)) {
			if (tx == prex && ty == prey) {
				continue;
			} else {
				swap(x, y, tx, ty);
			}
			if (h() + depth <= 15)
				DFS(tx, ty, depth + 1, x, y);
			swap(x, y, tx, ty);
		}
	}
}

int main() {
	int i, j;
	int x, y;
	scanf("%d", &T);
	while (T != 0) {
		minstep = 16;
		for (i = 0; i < MAXN; i++)
			scanf("%s", chess[i]);
		for (i = 0; i < MAXN; i++)
			for (j = 0; j < MAXN; j++)
				if (chess[i][j] == '*') {
					x = prex = i;
					y = prey = j;
					break;
				}
		DFS(x, y, 0, -1, -1);
		if (minstep == 16)
			printf("-1");
		else
			printf("%d\n", minstep);
		T--;
	}
	return 0;
}