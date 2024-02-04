#include <stdio.h>
int main()

{
	int a = 10;
	int t1 = a++;
	int t2 = ++a;
	printf("%d %d", t1, t2);

}