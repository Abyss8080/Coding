#include <stdio.h>
#include <stdlib.h>

int main() {
	char *p;
//	*p=(char*)malloc(100);//*pȡֵ�����ٿռ�Ӧ����ָ��p

	p = (char *)malloc(100);
	gets(p);
	printf("%s", p);
	system("PAUSE");
	return 0;
}