#include <stdio.h>
#include <stdlib.h>


//void swap(int *pa, int *pb) {
//	int *p;
//	*p = *pa;
//	*pa = *pb;
//	*pb = *p;
//}
////����pָ��û���ڴ�ռ�
//
//void swap(int *pa, int *pb) {
//	int *p;
//	p = pa;
//	pa = pb;
//	pb = p;
//}
////ָ���ں������õ�ʱ�򽻻����ڲ��ռ䣬��û�н���ֵ
//

void swap(int *pa, int *pb) {
	int *p;
	p = (int *)malloc(sizeof(int));
	*p = *pa;
	*pa = *pb;
	*pb = *p;
	free(p);
}

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	swap(&a, &b);
	printf("a=%d,b=%d\n", a, b);

	system("PAUSE");
	return 0;
}