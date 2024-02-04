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
/*��Ŀ
��֪һ�ŵ�ͼ���Զ�ά�������ʽ��ʾ���Լ����������˵�λ�á�
��ͼ�ϵ�ÿ��λ�ö������ߵ���ֻ������Щλ�����д���������£���Ҫ�ȴ�ܴ���������²��ܵ���Щλ�á�
������һ�������Ĳ������ÿһ����λ�Ĳ�������Դ��һ������������¡�
�������˿��������������ĸ������ƶ���ÿ�ƶ�һ��������Ҫ���� 1 ����λʱ�䣬��ܴ���������²���Ҫʱ�䡣
������˲�����������ˣ���ֻ�����ߵ�û�д��������µ�λ�ã����������ƶ����д��������µ�λ�á�
�����ڴ��ڼ䲻�ƶ��������������Ҳ���ƶ������ʣ�����Ҫ׷������������Ҫ���Ѷ���ʱ�䣿

�����ʽ
����ĵ�һ�а�������������M��N��T������ M �� N �еĵ�ͼ�����˳�ʼ�Ĳ�������� T��
0 < M,N < 200��0 <= T < 100
������ M�� N �еĵ�ͼ������ @ �������ˣ�+ ����������* ����ͨ·��# �������������¡�

�����ʽ
�������һ������ R����������׷������������Ҫ���ѵ�ʱ�䡣��������޷�׷�������������?1��
*/