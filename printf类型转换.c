#include <stdio.h>

struct node {
	int array[10];
	char y;
};

int main(int argc, char *argv[]) {
	struct node new[3];
	struct  node *p = new;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 10; j++)
			new[i].array[j] = i * 100 + j;

	printf("%d\n", ++p->array[5]);
	printf("%d\n", p->array[5]);
	printf("%d\n", p++->array[5]);
	printf("%d\n", p->array[5]);
	return 0;
}