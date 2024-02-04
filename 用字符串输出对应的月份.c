/*用字符串输出对应的月份*/
#include <stdio.h>

int main() {
	int n = 0;
	char *a[] = {"january",
	             "february",
	             "march",
	             "april",
	             "may",
	             "june",
	             "july",
	             "august",
	             "september",
	             "october",
	             "november",
	             "december",
	            };
	printf("Input the month number:");
	scanf("%d", &n);
	printf("%s", a[n - 1]);
	return 0;
}