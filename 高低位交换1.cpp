#include <stdio.h>

int main() {
	unsigned int i, j;
	scanf("%u", &i);
	j = i;
	i = i >> 16;
	j = j << 16;
	printf("%u", i + j);
	return 0;
}