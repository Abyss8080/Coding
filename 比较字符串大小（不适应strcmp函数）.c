#include <stdio.h>
#include <stdlib.h>
#define SIZE 20
int stringCompare(char *str1Ptr, char *str2Ptr);

int main() {
	char str1[SIZE], str2[SIZE];
	int n;
	printf("\n比较字符串大小！\n\n");
	printf("请输入两行字符串：\n");
	gets(str1);
	gets(str2);
	n = stringCompare(str1, str2);
	if (n > 0)
		printf("\n%s>%s\n", str1, str2);
	else if (n < 0)
		printf("\n%s<%s\n", str1, str2);
	else
		printf("\n%s=%s\n", str1, str2);
	system("PAUSE");
	return 0;
}

int stringCompare(char *str1Ptr, char *str2Ptr) {
	int n;
	while ((*str1Ptr == *str2Ptr) && (*str1Ptr != 0)) {
		str1Ptr++;
		str2Ptr++;

	}
	n = *str1Ptr - *str2Ptr;
	return n;
}
//担心输入溢出问题，可以采用fgets（char*str，int size，file*stream）；
//例如fgets（str1，20，stdin）即标准输入20个（包括\0）字符传给str1；
//同理fputs（char*str，file*stream），例如fputs（str1，stdout）。