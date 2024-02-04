#include <stdio.h>
#include <string.h>
#define MAX 10000

int steps[MAX] = {0};

int combine(int *dig) {
	return dig[3] + dig[2] * 10 + dig[1] * 100 + dig[0] * 1000;
}

int swap(int x, int i) {
	int digx[4];
	for (int j = 0; j < 4; j++) {
		digx[3 - j] = x % 10;
		x /= 10;
	}
	int t = digx[i];
	digx[i] = digx[i + 1];
	digx[i + 1] = t;
	return combine(digx);
}

int BFS(int x, int y) {
	memset(steps, -1, sizeof(steps));
	int queue[MAX];
	int l, r;
	l = r = 0;
	queue[r++] = x;
	steps[x] = 0;
	while (l < r) {
		int now = queue[l++];
		int pt = now;
		int dignow[4];
		if (now == y)
			return steps[now];
		for (int j = 0; j < 4; j++) {
			dignow[3 - j] = pt % 10;
			pt /= 10;
		}
		for (int i = 0; i < 11; i++) {
			int dignext[4];
			int next;
			for (int j = 0; j < 4; j++)
				dignext[j] = dignow[j];
			switch (i) {
				case 0:
					dignext[0] = (dignow[0] - 1 + 1 + 9) % 9 + 1;
					next = combine(dignext);
					break;
				case 1:
					dignext[1] = (dignow[1] - 1 + 1 + 9) % 9 + 1;
					next = combine(dignext);
					break;
				case 2:
					dignext[2] = (dignow[2] - 1 + 1 + 9) % 9 + 1;
					next = combine(dignext);
					break;
				case 3:
					dignext[3] = (dignow[3] - 1 + 1 + 9) % 9 + 1;
					next = combine(dignext);
					break;
				case 4:
					dignext[0] = (dignow[0] - 1 - 1 + 9) % 9 + 1;
					next = combine(dignext);
					break;
				case 5:
					dignext[1] = (dignow[1] - 1 - 1 + 9) % 9 + 1;
					next = combine(dignext);
					break;
				case 6:
					dignext[2] = (dignow[2] - 1 - 1 + 9) % 9 + 1;
					next = combine(dignext);
					break;
				case 7:
					dignext[3] = (dignow[3] - 1 - 1 + 9) % 9 + 1;
					next = combine(dignext);
					break;
				case 8:
					next = swap(now, 0);
					break;
				case 9:
					next = swap(now, 1);
					break;
				case 10:
					next = swap(now, 2);
					break;
			}
			if (steps[next] == -1) {
				queue[r++] = next;
				steps[next] = steps[now] + 1;
			}
		}
	}
}

int main() {
	int x, y;
	scanf("%d%d", &x, &y);
	printf("%d", BFS(x, y));
	return 0;
}