#include <stdio.h>
#define R 10
#define C 9
int visit[R][C], flag = 0;

const int direction[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}, {1, -2}, {2, -1}};

int in(int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}

void DFS(char chess[][C], int x, int y, int xe, int ye) {
	int dir = 0;
	int xi, yi;
	if (flag == 1)
		return;
	if (x == xe && y == ye) {
		printf("Yes");
		flag = 1;
		return;
	}
	visit[x][y] = 1;
	while (dir < 8) {
		xi = x + direction[dir][0];
		yi = y + direction[dir][1];
		if (in(xi, yi) && chess[xi][yi] == '.' && visit[xi][yi] == 0)
			DFS(chess, xi, yi, xe, ye);
		dir++;
	}
//	visit[x][y] = 0;不需要回退，走过的路走不通再次走到它的时候没必要再走
}

int main() {
	int i, j;
	int xs, ys, xe, ye;
	char chess[R][C];
	for (i = 0; i < R; i++)
		scanf("%s", chess[i]);
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			visit[i][j] = 0;
			if (chess[i][j] == 'S') {
				xs = i;
				ys = j;
			} else if (chess[i][j] == 'T') {
				xe = i;
				ye = j;
				chess[i][j] = '.'; //让最后一点也可走
			}
		}
	}

	DFS(chess, xs, ys, xe, ye);
	if (flag == 0)
		printf("No");
	return 0;
}