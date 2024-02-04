#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[]) {
	struct date {
		int day;
		int month;
		int year;

	};
	struct date today;
	today.day = 11;
	today.month = 11;
	today.year = 2021;
	printf("Today's date is %i-%i-%i.\n", today.year, today.month, today.day);
	printf("%d\n", &today);
	printf("%d\n", &today.day);
	printf("%d\n", &today.month);
	printf("%d\n", &today.year);
	system("PAUSE");
	return 0;
}