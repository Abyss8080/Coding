#include <stdio.h>
#include <stdlib.h>

int main() {
	char *p;
//	*p=(char*)malloc(100);//*p取值，开辟空间应交给指针p

	p = (char *)malloc(100);
	gets(p);
	printf("%s", p);
	system("PAUSE");
	return 0;
}