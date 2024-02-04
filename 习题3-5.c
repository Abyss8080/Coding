//#include <stdio.h>

//
//int main() {
//	int a, b, c, x, y;
//	scanf("%d,%d,%d", a, b, c);
//	x = a * b;
//	y = x * c;
//	printf("x=%f\n", x, "y=%f\n", y);
//
//}
//




#include <stdio.h>
int main() {

	int a, b, c, x, y;
	scanf("%d %d %d", &a, &b, &c);
	x = a * b;
	y = x * c;
	printf("x=%d\ny=%d\n", x, y);
	return 0;

}