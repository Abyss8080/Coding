#include <stdio.h>

int main() {
	int n, count = 1;
	int grade[101] = {0};
	int base, gra;
	int i=0;
	for (i = 0; i < 101; i++)
		grade[i] = 0;
	scanf("%d", &n);
	scanf("%d", &base);
	grade[base] = 1;
	for (i = 2; i <= n; i++) {
		scanf("%d", &gra);
		if (grade[gra] == 0)
			grade[gra] = 1;
	}
	for (i = 100; i >= 0; i--) {
		if (i != base) {
			if (grade[i] != 0)
				count++;
		} else {
			printf("%d", count);
			break;
		}
	}
	return 0;
}