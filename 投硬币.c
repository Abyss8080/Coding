#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip() {
	int x;
	x = rand() % 2;
	return x;
}

int main() {
	int x = 1;
	int y = 0;
	int ret = 0;
	time_t t;
//	<time.h>
//#ifndef __TIME_T
//#define __TIME_T      /* 避免重复定义 time_t */
//typedef long      time_t;    /* 时间值time_t 为长整型的别名*/
//#endif
	srand((unsigned int)time(&t));
	//rand()函数每次调用前都会查询是否调用过srand(seed)，是否给seed设定了一个值
	//如果有那么它会自动调用srand(seed)一次来初始化它的起始值
	//seed相同，产生的随机数也会相同
	for (x = 1; x <= 100; x++) {
		y = flip();
		if (y == 1) {
			ret++;
			printf("正面\n");
		} else {
			printf("反面\n");
		}
	}
	printf("在100次投硬币的结果中，有%d次正面，%d次反面。", ret, 100 - ret);
	return 0;
}