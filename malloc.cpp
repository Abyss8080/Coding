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
/*����ѭ�����ڴ�ռ䲻�㣬����nullָ�룬������ͼ��nullָ�븳ֵ�����Դ����˳�*/