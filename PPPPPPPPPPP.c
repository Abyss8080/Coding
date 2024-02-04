#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define MAX 14

void print(char s[MAX][MAX]) {
	int i, j;
	for (i = 0; i < MAX; i++) {
		for (j = 0; j < MAX; j++) {
			printf("%c ", s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}



void mazeGenerator(char s[MAX][MAX], int *x0, int *y0, int *x1, int *y1) {
	int i, j;
	int a;
	for (j = 0; j < MAX; j++) {
		s[0][j] = '#';
		s[13][j] = '#';
		s[j][0] = '#';
		s[j][13] = '#';
	}
	/*border*/
	srand((unsigned int)time(NULL));
	for (i = 1; i < 13; i++) {
		for (j = 1; j < 13; j++) {
			a = rand() % 2;
			if (a == 0)
				s[i][j] = '.';
			else
				s[i][j] = '#';
		}
	}

	*x0 = rand() % 12 + 1;
	*y0 = rand() % 12 + 1;
	s[*x0][*y0] = '@';
	*x1 = rand() % 12 + 1;
	*y1 = rand() % 12 + 1;
	s[*x1][*y1] = '$';
	printf("start:(%d,%d)\nend:(%d,%d)\n", *x0, *y0, *x1, *y1);
	print(s);
}
//标记是否找到出口
int flag = 0;

/*上右下左*/
void mazeTraverse(char s[MAX][MAX], int x0, int y0, int x1, int y1) {
	//这里的(dir[i][0],dir[i][1])实际上是右，下，左，上（不是你函数前面注释的上右下左哈）
	//下面是dir这个二维数组对应的坐标轴（应该很好理解的
	//------------->y
	//|
	//|
	//|
	//|
	//∨x
	int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},};
	int i = 1, j = 0;
	int xx0, yy0;
	//int isprime = -1;
	for (i = 0; i < 4; i++) {
		xx0 = x0 + dir[i][0];
		yy0 = y0 + dir[i][1];
		if (xx0 <= 12 && xx0 >= 1 && yy0 <= 12 && yy0 >= 1 ) {
			//后面那个判断没有用途hhh，终点是'$'，已经是'.'了就不会是终点了
			if (s[xx0][yy0] == '.' /*&& xx0 != x1 && yy0 != y1*/) {
				s[xx0][yy0] = 'X';
				//isprime = 1;
				print(s);
				mazeTraverse(s, xx0, yy0, x1, y1);
				//通过什么的mazeTraverse已经找到出口了，没必要再循环下去了，及时返回退出
				if (flag == 1)
					return;
				//下面可以实现把错误试探的'X'清除，只留下正确的'X'
				//s[xx0][yy0]='.';
			} else if (xx0 == x1 && yy0 == y1) {
				printf("Game over!\n");
				//找到出口了，标记后并及时返回
				flag = 1;
				return;
			}
		}

	}

	//if (isprime == -1) {
	//	printf("No way!\n");
	//}
}

int  main() {
	int x0, y0;
	int x1, y1;
	char stray[MAX][MAX];
	/*虽然题目没要求入口到出口必须有路径，
	我尝试跑了几十次，生成的迷宫存在入口到出口路径的次数太少了*/
	mazeGenerator(stray, &x0, &y0, &x1, &y1);
	mazeTraverse(stray, x0, y0, x1, y1);
	//判断是否没有找到终点
	if (flag == 0)
		printf("No way!\n");
	//print(stray);
	return 0;
}