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

/*上右下左*/
void mazeTraverse(char s[MAX][MAX], int  x0, int  y0) {
	int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},};
	int i = 1, j = 0;
	int xx0, yy0;
	int isprime = -1;
	for (i = 0; i < 4; i++) {
		xx0 =  x0 + dir[i][0];
		yy0 =  y0 + dir[i][1];
		if (xx0 <= 12 && xx0 >= 1 && yy0 <= 12 && yy0 >= 1 ) {
			if (s[xx0][yy0] == '.' ) {
				s[xx0][yy0] = 'X';
				isprime = 1;
				print(s);
				mazeTraverse(s,  xx0,  yy0 );

			} else if (s[xx0][yy0] == '$') {
				printf("Game over!\n");
				break;
			}
		}

	}
	if (isprime == -1) {
		printf("No way!\n");
	}
}

int  main() {
	int x0, y0;
	int x1, y1;
	char stray[MAX][MAX];
	mazeGenerator(stray, &x0, &y0, &x1, &y1);
	mazeTraverse(stray, x0, y0);
	return 0;
}


/*你可以不要它在那个函数里输出noway，你引入一个全局变量初始化为0，
找到结果了就置为1，等这个函数结束后判断这个全局变量的值，为0表示没有找到路*/