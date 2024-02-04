#include <stdio.h>
#define MAX 501

int main() {
	char reverse[MAX];
	gets(reverse);
	int count, i, j;
	i = count = 0;
	while (reverse[i] != '\0') {
		if (reverse[i] == ' ') {
			if (count != 0) {
				for (j = i - 1; j >= i - count; j--)
					printf("%c", reverse[j]);
				count = 0;
			}
			printf(" ");
		} else {
			count++;
		}
		i++;
	}
	if (count != 0) {
		for (j = i - 1; j >= i - count; j--)
			printf("%c", reverse[j]);
	}

	return 0;
}