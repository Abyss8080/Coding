#include <stdio.h>
#include <string.h>
#define MAX 20
#define MAXQ 10000000//题目开到千万级才没有提示段错误

typedef struct {
	int x;
	int y;
	int step;
	int sta;
} St;

typedef struct {
	int x;
	int y;
} Num;

typedef struct {
	Num num[MAX / 2];
	int k;
} Body;

int n, m;
int vis[MAX][MAX];
char chess[MAX][MAX];
int dir[5][2] = {{0, 0}, {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Body body;

int is_inner_and_nocrash(int x, int y, int nx, int ny, int p)
//判断是否在界内且不会撞到蛇身
{
	int xb = x, yb = y;
	if (nx < 0 || nx >= n || ny < 0 || ny >= m)
		return 0;
	int status = vis[x][y];
	for (int i = 0; i < body.k - p; i++) {
		xb = xb + dir[status % 10][0];
		yb = yb + dir[status % 10][1];
//		printf("%d\n", status % 10);
//		printf("%d的坐标是(%d,%d)\n", i + 2, xb, yb);
		status /= 10;
		if (xb == nx && yb == ny)
			return 0;
	}
	return 1;
}

int BFS(int x, int y, int status) {
	//k>2的BFS
	int i, j;
	St qu[MAXQ];
	int l, r, cut = 1;
	int p;
	if (body.k > 2)
		p = 2;
	else
		p = 1; //p=1表示k为2，p=2表示k>2
	for (i = 0; i < body.k - 2; i++)
		cut *= 10;
	l = r = 0;
	St t = {x, y, 0, status};
	qu[r++] = t;
	while (l < r) {
		printf("%d\n", r);
		St now = qu[l++];
		x = now.x;
		y = now.y;
		vis[x][y] = now.sta;
		if (chess[x][y] == '@')
			return now.step;
		for (i = 1; i < 5; i++) {
			int nx = x - dir[i][0];
			int ny = y - dir[i][1];
			if (chess[nx][ny] != '#'
			        && is_inner_and_nocrash(x, y, nx, ny, p)) {
				int nextsta = vis[x][y] % cut * 10 + i;//如果要走，下一步更新的status
				if (vis[nx][ny] == 0 || vis[nx][ny] != nextsta) {//没有访问过或者没有以status的状态访问过
					St next = {nx, ny, now.step + 1, nextsta};
					qu[r++] = next;
				}
			}
		}
	}
	return -1;
}

int BFS1(int x, int y) {
	//k=1的BFS
	int i, j;
	St qu[MAXQ];
	int l, r;
	l = r = 0;
	St t = {x, y, 0, 0};
	qu[r++] = t;
	while (l < r) {
		St now = qu[l++];
		x = now.x;
		y = now.y;
		vis[x][y] = 1;
		if (chess[x ][y] == '@')
			return now.step;
		for (i = 1; i < 5; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (chess[nx][ny] != '#'
			        && vis[nx][ny] == 0
			        && nx >= 0 && nx < n
			        && ny >= 0 && ny < m) {
				St next = {nx, ny, now.step + 1, 0};
				qu[r++] = next;
			}
		}
	}
	return -1;
}

int main() {
	int i, j, t;
	int x1, y1, x2 = -1, y2 = -1, status = 0;
	body.k = 0;
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%s", chess[i]);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			if (chess[i][j] >= '0' && chess[i][j] <= '9') {
				int count = chess[i][j] - '0';
				body.num[count].x = i;
				body.num[count].y = j;
				body.k++;
				if (count == 1) {
					x1 = i;
					y1 = j;
				}
				if (count == 2) {
					x2 = i;
					y2 = j;
				}
			}

	if (body.k == 1) {
		printf("%d", BFS1(x1, y1));
		return 0;
	}
	for (i = body.k; i >= 2 ; i--) {
		for (j = 1; j < 5; j++) {
			int x = body.num[i - 1].x + dir[j][0];
			int y = body.num[i - 1].y + dir[j][1];
			if (x == body.num[i].x && y == body.num[i].y ) {
				status = status * 10 + j;
			}
		}
	}
	printf("%d", BFS(x1, y1, status));
	return 0;
}