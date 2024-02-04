#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX 12//地图大小
//打印迷宫地图
void print_maze(char maze[MAX][MAX]) {
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			printf("%c ", maze[i][j]);
		}
		printf("\n");
	}
}

//交换(x1,y1)与(x2,y2)的值
void swap(int *x1, int *y1, int *x2, int *y2) {
	int temp;
	temp = *x1;
	*x1 = *x2;
	*x2 = temp;
	temp = *y1;
	*y1 = *y2;
	*y2 = temp;
}

//判断指定点坐标是否超出地图或在地图边界
int Judge(int x, int y) {
	if (x <= 0 || y <= 0 || x >= MAX - 1 || y >= MAX - 1)
		return 0;
	return 1;
}

//判断指定点是否与另一条路径相连
int GetNear(int x, int y, char maze[MAX][MAX]) {
	//记录指定点坐标上下左右 '.' 的个数(=1,该点可走; >1该点与另一条路径相连，不可走)
	//与另一条路径相连，如果走，就会使两条路径相连，不取
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
	//上右下左四个方向
	int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
	//由于是随机生成迷宫地图，所以将dir随机排列
	for (int i = 0; i < 4; i++) {
		int no = rand() % 4;
		swap(&dir[i][0], &dir[i][1], &dir[no][0], &dir[no][1]);
	}

	int xx, yy;
	for (int i = 0; i < 4; i++) { //依次遍历随机排列的四个方向
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
	maze[xb][yb] = '.'; //还原(xb,yb),及时将访问过的点还原(防止干扰
	// print_maze(maze);
}

int main() {
	srand((unsigned)(time(NULL)));
	char maze[MAX][MAX];

	//(将地图中所有点置为墙)
	memset(maze, '#', sizeof(maze));

	//打印初始迷宫地图
	//print_maze(maze);

	//设置第一个可走点(1,1)
	maze[1][1] = '.';

	//利用DFS生成迷宫地图
	random_create_maze(maze, 1, 1);

	//打印生成的迷宫地图
	print_maze(maze);

	//随机生成起点坐标(xb,yb)和终点坐标(xe,ye)
	//可按照题目要求放在合适的位置
	int xb, yb, xe, ye;
	do {
		xb = rand() % (MAX - 2) + 1;
		yb = rand() % (MAX - 2) + 1;
		xe = rand() % (MAX - 2) + 1;
		ye = rand() % (MAX - 2) + 1;
	} while (maze[xb][yb] == '#' || maze[xe][ye] == '#' || (xb == xe && yb == ye));
	printf("起点坐标：(%d,%d)\n终点坐标：(%d,%d)\n", xb, yb, xe, ye);
	DFS(maze, xb, yb, xe, ye);
	printf("起点坐标：(%d,%d)\n终点坐标：(%d,%d)\n", xb, yb, xe, ye);
	return 0;
}