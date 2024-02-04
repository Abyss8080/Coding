#include <stdio.h>
#define max 20
int substitute(char *a, char *b, char *c);

int main() {
	int num = 0;
	int i;
	char a = 'l', b = 'e';
	char c[max] = "I love C language!";
	num = substitute(&a, &b, c);
	printf("%d\n", num);
	for (i = 0; i < max; i++) {
		printf("%c", c[i]);
	}
	return 0;
}

int substitute(char *a, char *b, char *c) {
	int i = 0, n = 0;
	for (i = 0; i < max; i++) {
		if (c[i] == *a) {
			c[i] = *b;
			n++;
		}
	}
	return n;
}
