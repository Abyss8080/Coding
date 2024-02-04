#include <stdio.h>

int main() {
	char cmax = '@', c = '@';
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%c ", &c);
		if (c > cmax)
			cmax = c;
	}
	if (cmax == 'Z') {
		printf("Z is not admitted to conjure up.");
		return 0;
	} else {
		cmax++;
		printf("%c", cmax);
		return 0;
	}
}