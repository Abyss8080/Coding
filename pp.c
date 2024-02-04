/*随机生成迷宫*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mazeGenerator(char **s ) {
	int i = 1, j = 0;
	int t, g, h;
	time_t tim;

	for (j = 0; j < 14; j++) {
		s[0][j] = '#';
		s[13][j] = '#';
		s[j][0] = '#';
		s[j][13] = '#';
	}
	/*border*/

	srand((unsigned int)time(&tim));
	t = rand() % 12 + 1;
	g = rand() % 12 + 1;

	for (i = 1; i < 12; i++) {
		s[t][i] = '#';
		s[i][g] = '#';
	}
	s[t][rand() % (g - 2) + 1] = '.';
	s[rand() % (t - 2) + 1][g] = '.';
	s[t][12 - rand() % (11 - g)] = '.';
	s[12 - rand() % (11 - g)][g] = '.';
	h = rand() % 4;

	switch (h) {
		case 0:
			s[t][rand() % (g - 2) + 1] = '#';
			break;
		case 1:
			s[rand() % (t - 2) + 1][g] = '#';
			break;
		case 2:
			s[t][12 - rand() % (11 - g)] = '#';
			break;
		case 3:
			s[12 - rand() % (11 - g)][g] = '#';
			break;
	}
}




















//
//int f(char (*s)[14], int m, int n) {
//	if (s[m][n] == '.') {
//		s[m][n] = 'X';
//		return 1;
//	} else
//		return 0;
//}
//
//void mazeTraverse(char (*s)[14], int x, int y) {
//	int i, j;
//	int isprime = 0;
//	printf("\n\n");
//	for (i = 0; i < 14; i++) {
//		printf("              ");
//		for (j = 0; j < 14; j++) {
//			printf("%c ", s[i][j]);
//		}
//		printf("\n");
//
//	}
//	if (s[x][y] == '.' || s[x][y] == '@') {
//
//		if (f(s, x, y + 1)) {
//
//			isprime = 1;
//			mazeTraverse(s, x, y + 1);
//		}
//
//		if (f(s, x + 1, y)) {
//
//			isprime = 1;
//			mazeTraverse(s, x + 1, y);
//		}
//
//		if (f(s, x - 1, y)) {
//
//			isprime = 1;
//			mazeTraverse(s, x - 1, y);
//		}
//
//		if (f(s, x, y - 1)) {
//
//			isprime = 1;
//			mazeTraverse(s, x, y - 1);
//		}
//
//	}
//	if (isprime == 0) {
//		printf("No way!\n");
//	}
//	if (s[x][y] == '$') {
//		printf("wIN!");
//	}
//}
//
//


int main() {
	int i, j;
	int x = 1, y = 1;
	char **stray;
	stray = (char **)malloc(14);
	for (i = 0; i < 14; i++) {
		stray[i] = (char *)malloc(14);
	}
	mazeGenerator(stray);

	for (i = 0; i < 14; i++) {
		printf("              ");
		for (j = 0; j < 14; j++) {
			printf("%c ", stray[i][j]);
		}
		printf("\n");

	}
	/*居中打印*/
//
//	mazeTraverse(stray, x, y);
	return 0;
}
