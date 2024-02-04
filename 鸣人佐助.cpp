#include <stdio.h>
#include <string.h>
#define MAX 200
#define MAXN 10000

typedef struct {
	int x;
	int y;
	int time;
	int ob;
} Qu;

int dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
char map[MAX][MAX];
int vis[MAX][MAX][10];
int M, N, T;

int in(int x, int y) {
	return x >= 0 && y >= 0 && x < M && y < N;
}

int BFS(int xs, int ys, int xe, int ye) {
	Qu queue[MAXN], now;
	int r = 0, l = 0, di = 0;
	now.x = xs;
	now.y = ys;
	now.time = 0;
	now.ob = 0;
	queue[r] = now;
	r = (r + 1) % MAXN;
	vis[xs][ys][now.ob] = 1;
	while (l < r) {
		now = queue[l];
		l = (l + 1) % MAXN;
		di = 0;
		while (di < 4) {
			int nx = now.x + dir[di][0];
			int ny = now.y + dir[di][1];
			int nob = now.ob;
			if (map[nx][ny] == '#')
				nob += 1;
			if (( nx >= 0 && ny >= 0 && nx < M && ny < N)
			        && vis[nx][ny][nob] == 0
			        && nob <= T) {
				if (nx == xe && ny == ye)
					return now.time + 1;
				Qu next;
				next.x = nx;
				next.y = ny;
				next.time = now.time + 1;
				next.ob = nob;
				vis[nx][ny][next.ob] = 1;
				queue[r] = next;
				r = (r + 1) % MAXN;
//				printf("\n%d  %d\n", r, l);
			}
			di++;
		}
	}
	return -1;
}

int main() {
	int i, j;
	int xs, ys, xe, ye;
	scanf("%d %d %d", &M, &N, &T);
	memset(map, 0, sizeof(map));
	memset(vis, 0, sizeof(vis));
	for (i = 0; i < M; i++)
		scanf("%s", map[i]);
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++) {
			if (map[i][j] == '@') {
				xs = i;
				ys = j;
			}
			if (map[i][j] == '+') {
				xe = i;
				ye = j;
				map[i][j] = '*';
			}
		}
	printf("%d", BFS(xs, ys, xe, ye));
	return 0;
}
/*题目
已知一张地图（以二维矩阵的形式表示）以及佐助和鸣人的位置。
地图上的每个位置都可以走到，只不过有些位置上有大蛇丸的手下，需要先打败大蛇丸的手下才能到这些位置。
鸣人有一定数量的查克拉，每一个单位的查克拉可以打败一个大蛇丸的手下。
假设鸣人可以往上下左右四个方向移动，每移动一个距离需要花费 1 个单位时间，打败大蛇丸的手下不需要时间。
如果鸣人查克拉消耗完了，则只可以走到没有大蛇丸手下的位置，不可以再移动到有大蛇丸手下的位置。
佐助在此期间不移动，大蛇丸的手下也不移动。请问，鸣人要追上佐助最少需要花费多少时间？

输入格式
输入的第一行包含三个整数：M，N，T。代表 M 行 N 列的地图和鸣人初始的查克拉数量 T。
0 < M,N < 200，0 <= T < 100
后面是 M行 N 列的地图，其中 @ 代表鸣人，+ 代表佐助。* 代表通路，# 代表大蛇丸的手下。

输出格式
输出包含一个整数 R，代表鸣人追上佐助最少需要花费的时间。如果鸣人无法追上佐助，则输出?1。
*/