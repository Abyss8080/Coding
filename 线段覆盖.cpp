#include <stdio.h>
#define MAX 1000000

typedef struct {
	int left;
	int right;
} Line;

void sift(Line *lines, int low, int high) {
	int i = low, j = 2 * i;
	Line temp = lines[i];
	while (j <= high) {
		if (j < high && lines[j].right < lines[j + 1].right)
			j++;
		if (temp.right < lines[j].right) {
			lines[i] = lines[j];
			i = j;
			j = i * 2;
		} else
			break;
	}
	lines[i] = temp;
}

void HeapSort(Line *lines, int n) {
	int i;
	Line temp;
	for (i = n / 2; i >= 1; i--)
		sift(lines, i, n);
	for (i = n; i >= 2; i--) {
		temp = lines[1];
		lines[1] = lines[i];
		lines[i] = temp;
		sift(lines, 1, i - 1);
	}
}

int main() {
	int n, num, i;
	scanf("%d", &n);
	Line lines[MAX], temp;
	for (i = 1; i <= n; i++)
		scanf("%d %d", &lines[i].left, &lines[i].right);
	HeapSort(lines, n);
	num = 0;
	for (i = 1; i <= n; i++) {
		if (i == 1) {
			num++;
			temp = lines[i];
		} else {
			if (lines[i].left >= temp.right) {
				num++;
				temp = lines[i];
			}
		}
	}
	printf("%d", num);

	return 0;
}