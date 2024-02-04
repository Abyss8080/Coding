#include <stdio.h>

int main () {
	double mile, kilo;
	const int t1 = 5280, t2 = 12;
	double t3 = 2.54;
	printf("请输入需要转换的英里数：");
	scanf("%f", &mile);
	kilo = ( mile * t1 * t2 * t3 ) / 100000.0;
	printf("%.5f", &kilo);
	return 0;

}