#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int type;
	scanf("%d", &type);
	switch (type) {
		case 1:
			printf("早上好，11！");
			break;
		case 2 :
			printf("早上好，主人！");
			break;
		case 3:
			printf("早上好，小狐狸！");
			break;
		case 4:
			printf("早上好，未婚夫！");
			break;
		case 5:
			printf("早上好，汤圆！");
			break;
		default:
			printf("早上好，小设计师！");
	}

	return 0;
}