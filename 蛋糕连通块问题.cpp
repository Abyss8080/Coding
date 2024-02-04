#include <stdio.h>
#include <string.h>
#define MAX 1000
int R, C, temp;

int visit[MAX][MAX] = {0}, visitnum = 0;

int in(int x, int y) {
	return x >= 0 && x < R && y >= 0 && y < C;
}

void DFS(char cake[][MAX], int x, int y) {
	int dir = 0;
	int xi, yi;
	visit[x][y] = visitnum;
	temp++;

	while (dir < 4) {
		switch (dir) {
			case 0:
				xi = x - 1;
				yi = y;
				break;
			case 1:
				yi = y + 1;
				xi = x;
				break;
			case 2:
				xi = x + 1;
				yi = y;
				break;
			case 3:
				yi = y - 1;
				xi = x;
				break;
		}
		if (in(xi, yi) && cake[xi][yi] == '#' && visit[xi][yi] == 0)
			DFS(cake, xi, yi);
		dir++;
	}
}

int main() {
	scanf("%d %d", &R, &C);
	int i, j, max = 0;
	char cake[MAX][MAX];
	memset(cake, 0, sizeof(cake));
	for (i = 0; i < R; i++)
		scanf("%s", cake[i]);
	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (cake[i][j] == '.' || visit[i][j] != 0)
				continue;
			temp = 0;
			visitnum++;
			DFS(cake, i, j);
			if (temp > max)
				max = temp;
		}
	}
	printf("%d", max);
	return 0;
}