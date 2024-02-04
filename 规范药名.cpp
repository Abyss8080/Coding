#include <stdio.h>

void Standard(char *s) {
	int i = 0;
	int ishead = 1;
	while (s[i] != '\0') {
		if (ishead == 1) {
			if (s[i] >= 'a' && s[i] <= 'z')
				s[i] = s[i] - 32;
			ishead = 0;
		} else {
			if (s[i] >= 'A' && s[i] <= 'Z')
				s[i] = s[i] + 32;
		}
		i++;
	}
	printf("%s\n", s);
}

int main() {
	char medicine[100][21];
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", medicine[i]);
	for (i = 0; i < n; i++)
		Standard(medicine[i]);
	return 0;
}