#include <stdio.h>

int main(void) {
	int count = 0;
	printf("请输入倒计时总时间：\n");
	scanf("%d", &count);

	while (count > 0) {
		count--;
		printf("%d\n", count);
	}
	printf("发射！\n");
	return 0;
}