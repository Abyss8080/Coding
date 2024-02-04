#include <stdio.h>
#include <stdlib.h>
#define Mod 65537

int main() {
	unsigned int a, b;
	unsigned long int cfro, clat, c, cbetter;
	scanf("%u %u", &a, &b);
	printf("a=%u\nb=%u\n", a, b);
	c = a * b % Mod;
	cfro = c >> 16;
	clat = c << 16;
	clat = clat >> 16;
	printf("cfro=%lu\nclat=%lu\n", cfro, clat);
	cbetter = clat - cfro;
	printf("c=%lu\ncbetter=%lu\n", c, cbetter);
	return 0;
}