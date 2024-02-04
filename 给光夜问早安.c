#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int type;
	scanf("%d", &type);
	if (type == 1) {
		printf("早上好，11！");
	} else if (type == 2) {
		printf("早上好，主人！");
	} else if (type == 3) {
		printf("早上好，小狐狸！");
	} else if (type == 4) {
		printf("早上好，未婚夫！");
	} else if (type == 5)
		printf("早上好，汤圆！");
	else {
		printf("早上好，小设计师！");
	}
	return 0;
}