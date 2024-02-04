#include <stdio.h>
#include <stdlib.h>

typedef struct Data {
	int grade[3];
	long long int num;
	char name[10];

} data;
data class[10];

void get(data class[]) {
	int i = 0, j = 0;
	for (i = 0; i < 10; i++) {
		scanf("%d", &class[i].num);
		gets(class[i].name);
		for (j = 0; j < 3; j++)
			scanf("%d", &class[i].grade[j]);
	}
}

//void put(data class[]) {
//	int i = 0, j = 0;
//	for (i = 0; i < 10; i++) {
//		printf("%d ", class[i].num);
//		puts(class[i].name);
//		for (j = 0; j < 3; j++)
//			printf(" %d ", class[i].grade[j]);
//	}
//}

int main() {

	int i = 0, m = 0;
	double aver[10];
	printf("请依次输入学生的学号、姓名、以及三门课程成绩：\n");
	get(class);
	for (i = 0; i < 10; i++) {
		aver[i] = 1.0 * (class[i].grade[0] + class[i].grade[1] + class[i].grade[2]) / 3;
		if (aver[i] > 85)
			m++;
	}
	printf("%d", m);
	system("PAUSE");
	return 0;
}