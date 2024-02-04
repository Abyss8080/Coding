#include <stdio.h>

int Counter7(int count) {
	int dig, ret = count;
	if (count % 7 == 0)
		return 1;
	while (ret != 0) {
		dig = ret % 10;
		if (dig == 7)
			return 1;
		ret = ret / 10;
	}
	return 0;
}

int main() {
	int alcho[1000] = {0};
	char name[1000][21];
	int j, count, numbers;
	int m, n, t;
	scanf("%d %d %d", &n, &m, &t);
	for (j = 0; j < n; j++)
		scanf("%s", name[j]);
	count = t - 1;
	numbers = n;
	for (j = m - 1; j < n; j = (j + 1) % n) {
		if (alcho[j] != -1) {
			count++;
			if (Counter7(count)) {
				alcho[j] = -1;
				numbers--;
				if (numbers == 1)
					break;
			}
		}
	}
	for (j = 0; j < n; j++)
		if (alcho[j] == 0)
			printf("%s", name[j]);

	return 0;
}