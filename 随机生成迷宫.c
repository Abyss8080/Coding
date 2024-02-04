/*随机生成迷宫*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mazeGenerator(char **s ) {

	int i = 1, j = 0;
	int t, g, h, r;
	time_t tim;
	int r1, r2, r3, r4;
	for (i = 1; i < 13; i++) {
		for (j = 1; j < 13; j++) {
			s[i][j] = '.';
		}
	}

	for (j = 0; j < 14; j++) {
		s[0][j] = '#';
		s[13][j] = '#';
		s[j][0] = '#';
		s[j][13] = '#';
	}
	/*border*/

	srand((unsigned int)time(&tim));
	t = rand() % 10  + 2;
	g = rand() % 10  + 2;
	/*2---11*/
	for (i = 1; i < 13; i++) {
		s[t][i] = '#';
		s[i][g] = '#';
	}


	do {
		r = rand() % 12 + 1;
		if (r < g) {
			r1 = r;
			s[t][r1] = '.';

		}
	} while (s[t][r1] != '.');





	do {
		r = rand() % 12 + 1;
		if (r > g) {
			r2 = r;
			s[t][r2] = '.';

		}
	} while (s[t][r2] != '.');


	do {
		r = rand() % 12 + 1;
		if (r < t) {
			r3 = r;
			s[r3][g] = '.';


		}
	} while (s[r3][g] != '.');

	do {
		r = rand() % 12 + 1;
		if (r > t) {
			r4 = r;
			s[r4][g] = '.';

		}
	} while (s[r4][g] != '.');


	h = rand() % 4;

	switch (h) {
		case 0:
			s[t][r1] = '#';
			break;
		case 1:
			s[r3][g] = '#';
			break;
		case 2:
			s[t][r2] = '#';
			break;
		case 3:
			s[r4][g] = '#';
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
	stray = (char **)malloc(sizeof(char **) * 14);
	for (i = 0; i < 14; i++) {
		stray[i] = (char *)malloc(sizeof(char *) * 14);
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

	for (i = 0; i < 14; i++) {
		free(stray[i]);
	}
	free(stray);
	return 0;
}