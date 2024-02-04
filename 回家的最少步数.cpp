#include <stdio.h>
#include <string.h>
#define MAX 2001

typedef struct {
	int x;
	int y;
} St;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char map[MAX][MAX];
int vis[MAX][MAX];
St path[MAX * MAX];
int top = -1, min = MAX * MAX;
int n, m;
St p[MAX];
int pnow = -1;

int cango(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m && (map[x][y] != '#');
}

void BFS(int xs, int ys, int xe, int ye) {
	St now;
	int d = 0, nx, ny;
	now.x = xs;
	now.y = ys;
	vis[xs][ys] = 1;
	top++;
	path[top] = now;
	if (xs == xe && ys == ye) {
		if (min > top)
			min = top;
		vis[path[top].x][path[top].y] = 0;
		top--;
		return;
	}
	while (d < 4) {
		nx = now.x + dir[d][0];
		ny = now.y + dir[d][1];
		if (cango(nx, ny) && vis[nx][ny] == 0) {
			BFS(nx, ny, xe, ye);
		}
		d++;
	}
	vis[xs][ys] = 0;
	top--;
}

int main() {
	int i, j, minpath = MAX * MAX, temp = 0;
	int xs, ys, xe, ye;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", map[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m ; j++) {
			if (map[i][j] == 'S') {
				xs = i;
				ys = j;
			}
			if (map[i][j] == 'T') {
				xe = i;
				ye = j;
			}
			if (map[i][j] == 'P') {
				pnow++;
				p[pnow].x = i;
				p[pnow].y = j;
			}
		}
	while (pnow >= 0) {
		temp = MAX * MAX;
		top = -1;
		min = MAX * MAX;
		memset(vis, 0, sizeof(vis));
		BFS(xs, ys, p[pnow].x, p[pnow].y);
		if (min != MAX * MAX) {
			temp = min;
			top = -1;
			min = MAX * MAX;
			memset(vis, 0, sizeof(vis));
			BFS(p[pnow].x, p[pnow].y, xe, ye);
			if (min != MAX * MAX && minpath > temp + min) {
				minpath = temp + min;
			}
		}
		pnow--;
	}
	printf("%d", minpath);
	return 0;
}