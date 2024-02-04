#include <stdio.h>
#include <stdlib.h>


//void swap(int *pa, int *pb) {
//	int *p;
//	*p = *pa;
//	*pa = *pb;
//	*pb = *p;
//}
////错在p指针没有内存空间
//
//void swap(int *pa, int *pb) {
//	int *p;
//	p = pa;
//	pa = pb;
//	pb = p;
//}
////指针在函数调用的时候交换了内部空间，但没有交换值
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