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
//����Ƿ��ҵ�����
int flag = 0;

/*��������*/
void mazeTraverse(char s[MAX][MAX], int x0, int y0, int x1, int y1) {
	//�����(dir[i][0],dir[i][1])ʵ�������ң��£����ϣ������㺯��ǰ��ע�͵������������
	//������dir�����ά�����Ӧ�������ᣨӦ�úܺ�����
	//------------->y
	//|
	//|
	//|
	//|
	//��x
	int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0},};
	int i = 1, j = 0;
	int xx0, yy0;
	//int isprime = -1;
	for (i = 0; i < 4; i++) {
		xx0 = x0 + dir[i][0];
		yy0 = y0 + dir[i][1];
		if (xx0 <= 12 && xx0 >= 1 && yy0 <= 12 && yy0 >= 1 ) {
			//�����Ǹ��ж�û����;hhh���յ���'$'���Ѿ���'.'�˾Ͳ������յ���
			if (s[xx0][yy0] == '.' /*&& xx0 != x1 && yy0 != y1*/) {
				s[xx0][yy0] = 'X';
				//isprime = 1;
				print(s);
				mazeTraverse(s, xx0, yy0, x1, y1);
				//ͨ��ʲô��mazeTraverse�Ѿ��ҵ������ˣ�û��Ҫ��ѭ����ȥ�ˣ���ʱ�����˳�
				if (flag == 1)
					return;
				//�������ʵ�ְѴ�����̽��'X'�����ֻ������ȷ��'X'
				//s[xx0][yy0]='.';
			} else if (xx0 == x1 && yy0 == y1) {
				printf("Game over!\n");
				//�ҵ������ˣ���Ǻ󲢼�ʱ����
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
	/*��Ȼ��ĿûҪ����ڵ����ڱ�����·����
	�ҳ������˼�ʮ�Σ����ɵ��Թ�������ڵ�����·���Ĵ���̫����*/
	mazeGenerator(stray, &x0, &y0, &x1, &y1);
	mazeTraverse(stray, x0, y0, x1, y1);
	//�ж��Ƿ�û���ҵ��յ�
	if (flag == 0)
		printf("No way!\n");
	//print(stray);
	return 0;
}