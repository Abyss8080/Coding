#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
	char *s1 = "she is a pretty girl";
	char *s2 = "is";
	char *s3 = strstr(s1, s2);
	printf("%s", s3);
	return 0;
}