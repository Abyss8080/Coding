#include <stdio.h>
#include <stdlib.h>

int main() {
	void *i = NULL, *j = NULL;
	i =  malloc(0);
	j =  malloc(0);

	printf("%p  \n%p\n%d", i, j, (int)(j - i));
	free(i);
	free(j);
	return 0;
}