#include <stdio.h>
#include <stdlib.h>

int main() {
	struct date {
		int year;
		int month;
		int day;
	} date1 = {0, 0, 0};
	int a[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

	int day1 = 0, day2 = 0;
	int i;
	printf("请输入年号和该年是该年的第几天的天数：");
	scanf("%d %d", &date1.year, &day1);
	if (date1.year % 4 == 0 && date1.year % 100 != 0 || date1.year % 400 == 0) { /*reap year*/
		a[1] = 29;
		for (i = 0; i < 12; i++) {
			day2 += a[i];
			if (day1 <= day2) {
				date1.month = i + 1;
				date1.day = day1 - day2 + a[i];
				break;
			}
		}
	} else {
		for (i = 0; i < 12; i++) {
			day2 += a[i];
			if (day1 <= day2) {
				date1.month = i + 1;
				date1.day = day1 - day2 + a[i];
				break;
			}
		}

	}
	printf("Today is %d-%d-%d", date1.year, date1.month, date1.day);
	system("PAUSE");
	return 0;

}