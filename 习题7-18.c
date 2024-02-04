#include <stdio.h>

int search(int p[], int x, int y) {
	int m = -1, n = 0;
	int key = 8;
	for (n = 0; (n + x) <= y; n++) {
		if (p[n + x] == key) {
			m = n + x;
			printf("%d\n", m);
		} else {
			;
		}

	}
	return m;
}

int main() {
	int p[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 9, 8, 0,};
	search(p, 3, 12);
	return 0;

}