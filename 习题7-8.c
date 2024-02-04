#include <stdio.h>

int main() {
	int i = 0, j = 0, k = 0;
	int a;
	int m = 0, n = 0;
	int is1 = 0, is2 = 1;
	printf("请输入数组大小：");
	scanf("%d", &a);
	char C[a];
	printf("请输入数组元素(用空格隔开)：\n");
	for (i = 0; (i + 1) <= a; i++) {
		scanf("%c ", &C[i]);
	}
	for (j = 0; (j + 1) <= a; j++) {
		if (C[j] == '(') {
			m++;
		} else if (C[j] == ')') {
			n++;
		}
		if (m >= n) {
			;
		} else {
			is2 = 0;
		}
	}
	if (m == n) {
		is1 = 1;
	} else {
		;
	}

	if (is1 == 1 && is2 == 1) {
		printf("字符串满足两个条件。");

	} else if (is1 == 0 && is2 == 1) {
		printf("字符串不满足第一个条件，满足第二个条件。");
	} else if (is1 == 1 && is2 == 0) {
		printf("字符串满足第一个条件，不满足第二个条件。");

	} else if (is1 == 0 && is2 == 0) {
		printf("字符串两个条件都不满足。");
	}
	return 0;

}