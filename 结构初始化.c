#include <stdio.h>

int main(int argc, char *argv) {
	struct {
		int k;
		char c[30];
	} a[4] = {1, "abs", 44, "yys"}, *p = a;

	int b[25] = {1, 2, 3, 4, 5, 6};
	int *new = b;
//	printf("%s", *(p++)->c);
	printf("%d", *new++);
	printf("%d", *new);
	printf("%d", ++*new);
	return 0;
}