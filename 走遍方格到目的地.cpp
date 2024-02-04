#include <stdio.h>
#include <string.h>
#define MAX 8

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int map[MAX][MAX], vis[MAX][MAX];
int N, count = 0;

int allhas(void) {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			if (vis[i][j] == 0)
				return 0;
	return 1;
}

int in(int x, int y) {
	return x >= 1 && y >= 1 && x <= N && y <= N;
}

void DFS(int x, int y) {
	if (x == N && y == 1) {
		if (allhas())
			count++;
		vis[x][y] = 0;
		return;
	}
	if (N > 1
	        && vis[N][2]
	        && vis[N - 1][1]
	        && ((x != N && y != 2) && (x != N - 1 && y != 1))) {
		vis[x][y] = 0;
		return;
	}
	if ((!in(x + 1, y) || vis[x + 1][y]) //上不可走
	        && (!in(x - 1, y) || vis[x - 1][y]) //下不可走
	        && (in(x, y - 1) && !vis[x][y - 1]) //左可走
	        && (in(x, y + 1) && !vis[x][y + 1]) //右可走
	   ) {
		vis[x]
		[y] = 0;
		return;
	}
	if ((!in(x, y - 1) || vis[x][y - 1])
	        && (!in(x, y + 1) || vis[x][y + 1])
	        && (in(x - 1, y) && !vis[x - 1][y])
	        && (in(x + 1, y) && !vis[x + 1][y])
	   ) {
		vis[x]
		[y] = 0;
		return;
	}
	int d = 0;
	while (d < 4) {
		int nx = x + dir[d][0];
		int ny = y + dir[d][1];
		if (in(nx, ny) && vis[nx][ny] == 0) {
			vis[nx][ny] = 1;
			DFS(nx, ny);
		}
		d++;
	}
	vis[x][y] = 0;
}

int main() {
	scanf("%d", &N);
	memset(vis, 0, sizeof(vis));
	vis[1][1] = 1;
	DFS(1, 1);
	printf("%d", count);
	return 0;
}
