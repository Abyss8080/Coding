#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//int main() {
//	char *p;
//	char s[80];
//	p = s;
//	do {
//		gets(s);
//		while (*p)
//			printf("%d", *p++); //p不随s的变化改变
//	} while (strcmp(s, "done"));
//
//	system("PAUSE");
//	return 0;
//}



int main() {
	char *p;
	char s[80];

	do {
		gets(s);
		p = s;
		while (*p)
			printf("%d", *p++);
	} while (strcmp(s, "done"));

	system("PAUSE");
	return 0;
}