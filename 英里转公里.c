#include <stdio.h>

int main () {
	double mile, kilo;
	const int t1 = 5280, t2 = 12;
	double t3 = 2.54;
	printf("��������Ҫת����Ӣ������");
	scanf("%f", &mile);
	kilo = ( mile * t1 * t2 * t3 ) / 100000.0;
	printf("%.5f", &kilo);
	return 0;

}