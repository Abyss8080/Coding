//#include <stdio.h>









//#define MAX
//
//int Max(int x, int y) {
//	return (x > y) ? x : y;
//}
//#else
//
//int Max(int x, int y, int z) {
//	int k;
//	k = x > y ? x : y;
//	return (z > k) ? z : k;
//}
//#endif
//
//
//int main() {
//	int a, b, c;
//	scanf("%d%d%d", &a, &b, &c);
//	printf("max=%d\n", Max(a, b, c));
//	return 0;
//}
/*oringinal*/




#include <stdio.h>
#define MAX

#ifdef MAX
int Max(int x, int y, int z) {
	int k;
	k = x > y ? x : y;
	return (z > k) ? z : k;
}

#else

int Max(int x, int y) {
	return (x > y) ? x : y;
}
#endif

int main() {
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("max=%d\n", Max(a, b, c));



	return 0;
}


