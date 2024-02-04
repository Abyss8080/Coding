#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 12//��ͼ��С
//��ӡ�Թ���ͼ
void print_maze(char maze[MAX][MAX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

//����(x1,y1)��(x2,y2)��ֵ
void swap(int *x1, int *y1, int *x2, int *y2) {
	int temp;
	temp = *x1;
	*x1 = *x2;
	*x2 = temp;
	temp = *y1;
	*y1 = *y2;
	*y2 = temp;
}

//�ж�ָ���������Ƿ񳬳���ͼ���ڵ�ͼ�߽�
int Judge(int x, int y) {
	if (x <= 0 || y <= 0 || x >= MAX - 1 || y >= MAX - 1)
		return 0;
	return 1;
}

//�ж�ָ�����Ƿ�����һ��·������
int GetNear(int x, int y, char maze[MAX][MAX]) {
	//��¼ָ���������������� '.' �ĸ���(=1,�õ����; >1�õ�����һ��·��������������)
	//����һ��·������������ߣ��ͻ�ʹ����·����������ȡ
	int count = 0;
	int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = x + dir[i][0];
		yy = y + dir[i][1];
		if (Judge(xx, yy) == 1 && maze[xx][yy] == '.')
			count++;
	}
	return count;
}

void random_create_maze(char maze[MAX][MAX], int x, int y) {
	//���������ĸ�����
	int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	//��������������Թ���ͼ�����Խ�dir�������
	for (int i = 0; i < 4; i++) {
		int no = rand() % 4;
		swap(&dir[i][0], &dir[i][1], &dir[no][0], &dir[no][1]);
	}

	int xx, yy;
	for (int i = 0; i < 4; i++) { //���α���������е��ĸ�����
		xx = x + dir[i][0];
		yy = y + dir[i][1];
		if (Judge(xx, yy) == 1 && maze[xx][yy] == '#' && GetNear(xx, yy, maze) == 1) {
			maze[xx][yy] = '.';
			random_create_maze(maze, xx, yy);
		}
	}
}
int flag = 0;

void DFS(char maze[MAX][MAX], int xb, int yb, int xe, int ye) {
	printf("----------------------\n");
	maze[xb][yb] = 'X';
	print_maze(maze);
	if (xb == xe && yb == ye) {
		flag = 1;
		return;
	}
	int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	int xx, yy;
	for (int i = 0; i < 4; i++) {
		xx = xb + dir[i][0];
		yy = yb + dir[i][1];
		if (Judge(xx, yy) == 1 && maze[xx][yy] == '.' && flag == 0) {
			DFS(maze, xx, yy, xe, ye);
			//if(flag==1) return;
		}
	}
	maze[xb][yb] = '.'; //��ԭ(xb,yb),��ʱ�����ʹ��ĵ㻹ԭ(��ֹ����
	// print_maze(maze);
}

int main() {
	srand((unsigned)(time(NULL)));
	char maze[MAX][MAX];

	//(����ͼ�����е���Ϊǽ)
	memset(maze, '#', sizeof(maze));

	//��ӡ��ʼ�Թ���ͼ
	//print_maze(maze);

	//���õ�һ�����ߵ�(1,1)
	maze[1][1] = '.';

	//����DFS�����Թ���ͼ
	random_create_maze(maze, 1, 1);

	//��ӡ���ɵ��Թ���ͼ
	print_maze(maze);

	//��������������(xb,yb)���յ�����(xe,ye)
	//�ɰ�����ĿҪ����ں��ʵ�λ��
	int xb, yb, xe, ye;
	do {
		xb = rand() % (MAX - 2) + 1;
		yb = rand() % (MAX - 2) + 1;
		xe = rand() % (MAX - 2) + 1;
		ye = rand() % (MAX - 2) + 1;
	} while (maze[xb][yb] == '#' || maze[xe][ye] == '#' || (xb == xe && yb == ye));
	printf("������꣺(%d,%d)\n�յ����꣺(%d,%d)\n", xb, yb, xe, ye);
	DFS(maze, xb, yb, xe, ye);
	printf("������꣺(%d,%d)\n�յ����꣺(%d,%d)\n", xb, yb, xe, ye);
	return 0;
}