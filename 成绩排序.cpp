#include <stdio.h>
#include <string.h>

typedef struct {
	char name[21];
	int grade;
} stu;

int main() {
	int n, i, j;
	stu student[20], temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %d", student[i].name, &student[i].grade);
	}

	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (student[j].name[0] < student[j - 1].name[0]) {
				temp = student[j];
				student[j] = student[j - 1];
				student[j - 1] = temp;
			}
		}
	}

	for (i = 0; i < n; i++) {
		for (j = 1; j < n; j++) {
			if (student[j].grade > student[j - 1].grade) {
				temp = student[j];
				student[j] = student[j - 1];
				student[j - 1] = temp;;
			}
		}
	}
	for (i = 0; i < n; i++) {
		printf("%s %d\n", student[i].name, student[i].grade);
	}
	return 0;
}