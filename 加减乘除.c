/*���һ���Ӽ��˳���+|-|*|/���ĳ����������е�����Ϊ��
mycalc +   3 3
������Ľ����6*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int judge(char i, char mycalc[]) {
	int j, k;
	for (k = 0; k < 4; k++) {
		if (i == mycalc[k]) {
			j = k + 1;
		}
	}
	return j;
}

int main() {
	char mycalc[4] = {'+', '-', '*', '/'};
	double a, b, c;
	char t[7];
	char T[7] = "mycalc\0";
	char i;
	int j;

	scanf("%6s %c %lf %lf", t, &i, &a, &b);
	if (strcmp(t, T) == 0) {
		j = judge(i, mycalc);
		switch (j) {
			case 1:
				c = a + b;
				break;
			case 2:
				c = a - b;
				break;
			case 3:
				c = a * b;
				break;
			case 4:
				c = a / b;
				break;
		}
	}
	printf("%f\n", c);

	system("PAUSE");
	return 0;
}