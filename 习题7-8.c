#include <stdio.h>

int main() {
	int i = 0, j = 0, k = 0;
	int a;
	int m = 0, n = 0;
	int is1 = 0, is2 = 1;
	printf("�����������С��");
	scanf("%d", &a);
	char C[a];
	printf("����������Ԫ��(�ÿո����)��\n");
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
		printf("�ַ�����������������");

	} else if (is1 == 0 && is2 == 1) {
		printf("�ַ����������һ������������ڶ���������");
	} else if (is1 == 1 && is2 == 0) {
		printf("�ַ��������һ��������������ڶ���������");

	} else if (is1 == 0 && is2 == 0) {
		printf("�ַ������������������㡣");
	}
	return 0;

}