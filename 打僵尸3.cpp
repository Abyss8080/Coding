#include <stdio.h>
#define MAX 5000

typedef struct {
	int x;
	int y;
} Zombie;

void sift(Zombie *zombie, int low, int high) {
	int i = low, j = 2 * i;
	Zombie temp = zombie[i];
	while (j <= high) {
		if (j < high && zombie[j].y > zombie[j + 1].y)
			j++;
		if (temp.y > zombie[j].y) {
			zombie[i] = zombie[j];
			i = j;
			j = i * 2;
		} else
			break;
	}
	zombie[i] = temp;
}

void HeapSort(Zombie *zombie, int n, int base) {
	int i;
	Zombie temp;
	for (i = n / 2; i >= 1; i--)
		sift(zombie, i, n);
	for (i = n; i >= 2; i--) {
		temp = zombie[i];
		zombie[i] = zombie[1];
		zombie[1] = temp;
		sift(zombie, 1, i - 1);
	}
}

int main() {
	int n, m, h, b;
	scanf("%d %d %d %d", &n, &m, &h, &b);
	int i, j, left, num;
	int x, y;
	Zombie zombie[MAX];
	i = j = 1;
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		if (x <= h + b) {
			zombie[j].x = x;
			zombie[j].y = y;
			j++;
		}
	}
	j--;
	HeapSort(zombie, j, h + b);
	left = m;
	num = 0;
	for (i = j; i >= 1; i--) {
		if (left < zombie[i].y)
			break;
		else if (left >= zombie[i].y) {
			num++;
			left -= zombie[i].y;
		}
	}
	printf("%d", num);
	return 0;
}