#include <stdio.h>




//void reverse(long n) {
//	if (n >= 1000)
//		reverse(n / 1000);
//	printf("%d", n % 1000);
//	putchar(',');
//
//}
//
//int main() {
//	long a;
//	scanf("%ld", &a);
//	reverse(a);
//
//	return 0;
//}
/*递归*/




/*迭代*/
int main() {
	long a;
	int i;

	int t[10];/*long定义下，a最多十位*/

	scanf("%ld", &a);
	for (i = 0; i < 10; i++) {
		t[i] = -1;
	}
	for (i = 0; a > 0; i++) {
		t[i] = a % 10;
		a /= 10;
	}
	for (i = 0; i < 10; i++) {
		if (t[9 - i] != -1) {
			printf("%d", t[9 - i]);
			if ((9 - i ) % 3 == 0) {
				putchar(',');
			}
		}
	}

	return 0;
}