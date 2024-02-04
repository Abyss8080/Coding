#include <stdio.h>

int main() {
	unsigned int i, j;
	scanf("%u", &i);
	j = i;
	i = i % 65536;
	j = j / 65536;
	printf("%u", i * 65536 + j);
	return 0;
}