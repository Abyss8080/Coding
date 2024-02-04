/*ÆË¿ËÅÆÏ´ÅÆºÍ·¢ÅÆ*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	char *q[] = {"Heart", "Diamond", "Club", "Spade",};
	int p[4][13];
	int i = 0, j = 0;
	int a = 0, b = 0;
	int t = 1;
	int m = 0;
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 13; j++) {
			p[i][j] = -1;
		}
	}
	srand((unsigned int)time(NULL));
	for (t = 1; t <= 4; t++) {
		printf("  Player%d:\n", t);
		do {
			a = rand() % 4;
			b = rand() % 13;
			if (p[a][b] == -1) {
				p[a][b] = t;
				m++;
				printf("%s %d\n", q[a], b + 1);
			}
		} while (m < 13);
		printf("\n\n");
		m = 0;

	}




	return 0;
}
