#include <stdio.h>

int main() {
	int daylimit[12];
	int year, month, day;
	int run = 0;
	scanf("%d %d %d", &year, &month, &day);
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		run = 1;
	for (int i = 0; i < 12; i++) {
		switch (i) {
			case 1:
			case 3:
			case 5:
			case 7:
			case 8:
			case 10:
			case 12:
				daylimit[i - 1] = 31;
				break;
			case 2:
				if (run)
					daylimit[i - 1] = 29;
				else
					daylimit[i - 1] = 28;
				break;
			default:
				daylimit[i - 1] = 30;
		}
	}

	if (month == 1 && day == 1)
		printf("%d %d %d\n%d %d %d", year - 1, 12, 31, year, month, day + 1);
	else if (month == 12 && day == 31)
		printf("%d %d %d\n%d %d %d", year, month, day - 1, year + 1, 1, 1);
	else if (month == 2 && day == daylimit[month - 1])
		printf("%d %d %d\n%d %d %d", year, month, day - 1, year, month + 1, 1);
	else {
		if (day == 1)
			printf("%d %d %d\n%d %d %d", year, month - 1, daylimit[month - 2], year, month, day + 1);
		else if (day == daylimit[month - 1])
			printf("%d %d %d\n%d %d %d", year, month, day - 1, year, month + 1, 1);
		else
			printf("%d %d %d\n%d %d %d", year, month, day - 1, year, month, day + 1);
	}

	return 0;
}