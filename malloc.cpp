#include <stdio.h>
#include <stdlib.h>

int main() {
	char *p;

	while (1) {
		p = (char *) malloc(1);
		*p = 0;
	}
	printf("%d", *p);
	return 0;
}
/*不断循环后内存空间不足，返回null指针，接着试图对null指针赋值，所以错误退出*/