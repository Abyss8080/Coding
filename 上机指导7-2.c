#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int substitude(char a, char b, char *c);

int main() {
	char a, b;
	char c[] = "hello world!";
	int t;
	printf("ÇëÊäÈëËÑË÷×Ö·ûºÍÌæ»»×Ö·û£º");
	scanf("%c %c", &a, &b);
	t = substitude(a, b, c);
	printf("%d\n ", t);
	puts(c);
	system("PAUSE");
	return 0;
}

int substitude(char a, char b, char *c) {
	int i = 0;
	int t = 0;
	do {
		if (c[i] == a) {
			c[i] = b;
			t++;
		}
		i++;
	} while (c[i] != '\0');
	return t;
}