#include <stdio.h>
#include <stdlib.h>

//int main(){
//	int x,*p;
//	x=10;
//	*p=x;//pδ��ʼ��
//	return 0;
//}

int main() {
	int x, *p;
	x = 10;
	p = &x;
	printf("x=%d\n*p=%d", x, *p);

	system("PAUSE");
	return 0;
}