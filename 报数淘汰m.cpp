#include <stdio.h>

int main() {
	int kids[1000] = {0};
	int j, count, numbers;
	int m, n;
	scanf("%d %d", &n, &m);
	count = 0;
	numbers = n;
	for (j = 0; j < n; j = (j + 1) % n) {
		if (kids[j] != -1) {
			count++;
			if (count == m) {
				kids[j] = -1;
				numbers--;
				count = 0;
				if (numbers == 1)
					break;
			}
		}
	}
	for (j = 0; j < n; j++)
		if (kids[j] == 0)
			printf("%d", j + 1);

	return 0;
}