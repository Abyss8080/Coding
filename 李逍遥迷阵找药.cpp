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

/*��Ŀ
��������ң���������ˣ���С��������ȥһ�����鵺������Ů���Ҫ�ɵ���������
���浫Т˳������ң���������鵺���˷���ǧ�����������������ģ�������ҩ��������������
������M��N ��������ɣ��еķ������п���˲������ң�Ĺ�����еķ��������ǰ�ȫ��
��������ң�뾡���ҵ���ҩ����Ȼ��Ӧ�ܿ��й���ķ��񣬲��������ٵķ��񣬶������������������ȴ�������
����Ҫ������������ʵ�����Ŀ�ꡣ

�����ʽ
��һ������������������ M �� N�����߾������� 20��M ��ʾ��������, N ��ʾ����������
�������� M ��, ÿ�а��� N ���ַ�,��ͬ�ַ��ֱ����ͬ����:
1) '@'����������ң���ڵ�λ�ã�2) '.'�����԰�ȫͨ�еķ���
3) '#'���й���ķ���4) '*'����ҩ����λ�á�

�����ʽ
���һ�У����а�������ң�ҵ���ҩ��Ҫ���������ٵķ�����Ŀ(����������ʼλ�õķ���)��
������������ҵ���ҩ, ����� -1��
*/