#include <stdio.h>
#include <string.h>
#define MAX 2001

typedef struct qu {
	int x, y;
	int key;
	int steps;
} Qu;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
Qu qu[MAX * MAX];
int m, n;
char mg[MAX][MAX];

int visited[MAX][MAX][2] = {0};

int in(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int DFS(int xi, int yi) {
	int r, l, x1, y1, x2, y2, key, steps;
	Qu now, next;
	l = r = 0;
	now.x = xi;
	now.y = yi;
	now.key = 0;
	now.steps = 0;
	qu[r++] = now;
	visited[xi][yi][0] = 1;
	while (l < r) {
		now = qu[l++];
		x1 = now.x;
		y1 = now.y;
		key = now.key;
		steps = now.steps;
		int di = 0;
		while (di < 4) {
			x2 = x1 + dir[di][0];
			y2 = y1 + dir[di][1];
			di++;
			if (in(x2, y2)) {
				if (key == 1 && mg[x2][y2] == 'T') {
					return steps + 1;
				}
				if (key == 1 && mg[x2][y2] != '#' && visited[x2][y2][1] == 0) {
					visited[x2][y2][1] = 1;
					next.x = x2;
					next.y = y2;
					next.steps = steps + 1;
					next.key = 1;
					qu[r++] = next;
				}
				if (key == 0 && mg[x2][y2] != '#' && visited[x2][y2][0] == 0) {
					visited[x2][y2][0] = 1;
					next.x = x2;
					next.y = y2;
					next.steps = steps + 1;
					if (mg[x2][y2] == 'P')
						next.key = 1;
					else
						next.key = 0;
					qu[r++] = next;
				}
			}
		}
	}
}

int main() {
	int xi, yi, flag = 0;
	scanf("%d %d", &m, &n);
	for (int i = 0; i < m; i++)
		scanf("%s", mg[i]);
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (mg[i][j] == 'S') {
				xi = i;
				yi = j;
				flag = 1;
				break;
			}
		}
		if (flag)
			break;
	}
	printf("%d", DFS(xi, yi));
	return 0;
}