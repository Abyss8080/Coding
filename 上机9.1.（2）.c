#include <stdio.h>
#include <stdlib.h>
#define SIZE 5

struct stu {
	int num;
	char name[15];
	char sex;
	float score;
} boy[SIZE];

//= {
//        {101, "Li Ping", 'M', 45},
//		{102, "Zhang Ping", 'M', 62.5},
//		{103, "He Fang", 'F', 92.5},
//		{104, "Cheng Ling", 'F', 87},
//	    {105, "Wang Ming", 'M', 58},
//};

void readstud(struct stu *stud, int max) {
	int j = 0;
	for (j = 0; j < max; j++) {
		printf("请输入请%d个学生的学号、姓名、性别、分数：\n""形如：\n101，Ling Ping\n M,45\n", j + 1);
		scanf("%d,%s", &stud[j].num, stud[j].name);
		scanf(" %c,%f", &stud[j].sex, &stud[j].score);
	}

}

void average(struct stu *stud, int max, float *all, float *a) {
	int i;
	for (i = 0; i < max; i++) {
		*all += stud[i].score;
	}
	*a = *all / max;
}

int count(struct stu *stud, int max) {
	int count = 0;
	int i = 0;
	for (i = 0; i < max; i++) {
		if (stud[i].score < 60)
			count += 1;
	}
	return count;
}

int main() {
	int c = 0;
	float ave = 0, s = 0;


	readstud(boy, SIZE);
	average(boy, SIZE, &s, &ave);
	c = count(boy, SIZE);


	printf("\n\ns=%f\n", s);
	printf("average=%f\ncount=%d\n", ave, c);
	
	system("PAUSE");
	return 0;

}






//int main() {
//	int i, c = 0;
//	float ave = 0, s = 0;
//
//	for (i = 0; i < SIZE; i++) {
//		s += boy[i].score;
//		if (boy[i].score < 60)
//			c += 1;
//
//	}
//	printf("s=%f\n", s);
//
//	ave = s / SIZE;
//	printf("average=%f\ncount=%d\n", ave, c);
//
//	system("PAUSE");
//	return 0;
//}
//
//


