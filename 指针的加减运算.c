#include <stdio.h>
#include <stdlib.h>

int main() {
	short int *p1, score[10] = {84, 65, 77, 60, 88, 86, 92, 93, 70, 66,};
	long int *p2;
	p1 = &score[0];
	p2 = (long int *)&score[0];
	printf("sizeof(short int)=%d\n", sizeof(short int));
	printf("p1=%p\n", p1);
	printf("p1+1=%p\n%p", p1++, p1--);
	printf("p1-1=%p\n", p1 - 1);
//	printf("%d", *p1);
	printf("sizeof(long int)=%d\n", sizeof(long int));
	printf("p2=%p\n", p2);
	printf("p2+1=%p\n", p2 + 1);
	printf("p2-1=%p\n", p2 - 1);
	system("PAUSE");
	return 0;

}