#include <stdio.h>
#include <string.h>
#define MAX 20

typedef struct {
	int x;
	int y;
	int num;
} Qu;
char maze[MAX][MAX];
int vis[MAX][MAX];
int isqu[MAX][MAX];
int M, N;

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

int in(int x, int y) {
	return x >= 0 && y >= 0 && x < M && y < N;
}

int BFS(int xs, int ys, int xe, int ye) {
	Qu queue[M * N], now, t;
	int l, r;
	l = r = 0;
	memset(vis, 0, sizeof(vis));
	memset(isqu, 0, sizeof(isqu));
	now.x = xs;
	now.y = ys;
	now.num = 1;
	queue[r++] = now;
	isqu[xs][ys] = 1;
	while (l < r) {
		now = queue[l++];
		int x, y;
		x = now.x;
		y = now.y;
		vis[x][y] = 1;
		if (x == xe && y == ye)
			return now.num - 1;
		for (int i = 0; i < 4; i++) {
			int nx = x + dir[i][0];
			int ny = y + dir[i][1];
			if (in(nx, ny) && maze[nx][ny] == '.' && vis[nx][ny] == 0 && isqu[nx][ny] == 0) {
				t.x = nx;
				t.y = ny;
				t.num = now.num + 1;
				queue[r++] = t;
				isqu[nx][ny] = 1;
			}
		}
	}
	return -1;
}

int main() {
	int xs, ys, xe, ye;
	scanf("%d %d", &M, &N);
	for (int i = 0; i < M; i++)
		scanf("%s", maze[i]);
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			if (maze[i][j] == '@') {
				xs = i;
				ys = j;
			}
			if (maze[i][j] == '*') {
				xe = i;
				ye = j;
				maze[i][j] = '.';
			}
		}
	printf("%d", BFS(xs, ys, xe, ye));

	return 0;
}

/*题目
少年李逍遥的婶婶病了，王小虎介绍他去一趟仙灵岛，向仙女姐姐要仙丹救婶婶。
叛逆但孝顺的李逍遥闯进了仙灵岛，克服了千险万难来到岛的中心，发现仙药摆在了迷阵的深处。
迷阵由M×N 个方格组成，有的方格内有可以瞬秒李逍遥的怪物，而有的方格内则是安全。
现在李逍遥想尽快找到仙药，显然他应避开有怪物的方格，并经过最少的方格，而且那里会有神秘人物等待着他。
现在要求你来帮助他实现这个目标。

输入格式
第一行输入两个非零整数 M 和 N，两者均不大于 20。M 表示迷阵行数, N 表示迷阵列数。
接下来有 M 行, 每行包含 N 个字符,不同字符分别代表不同含义:
1) '@'：少年李逍遥所在的位置；2) '.'：可以安全通行的方格；
3) '#'：有怪物的方格；4) '*'：仙药所在位置。

输出格式
输出一行，该行包含李逍遥找到仙药需要穿过的最少的方格数目(计数包括初始位置的方块)。
如果他不可能找到仙药, 则输出 -1。
*/