#include <stdio.h>
#include <stdlib.h>

union {
	char ch;
	short int s;
	int i;
	long int b;
} x;

int main(void) {

	printf("������һ���ַ�\n");
	scanf("%c", &x.ch);

	printf("ch=%c\ns=%d\ni=%d\nb=%ld\n", x.ch, x.s, x.i, x.b);

	system("PAUSE");
	return 0;
}