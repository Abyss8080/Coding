//�ж������εĴ��ں�����
#include <stdio.h>
#include <stdlib.h>

#define x(a) (a*a)

int main() {
	int a = 0, b = 0, c = 0;
	int t = 0;
	int m = 0;
	printf("\n\n������������:\n""���磺2 1 3\n");
	scanf("%d %d %d", &a, &b, &c);

	if (a < b) {
		t = a;
		a = b;
		b = t;
	}

	if (a < c) {
		t = a;
		a = c;
		c = t;
	}
	if (c > b) {
		t = c;
		c = b;
		b = t;
	}

	if ((c + b - a) <= 0) {
		printf("�����߲��ܹ��������Ρ�\n");
	} else {
		printf("�����߿��Թ��������Ρ�\n");
		if (b == c && a != b) {
			printf("���������ǵ��������Ρ�\n");
		} else if (a == c && c == b) {
			printf("���������ǵȱ������Ρ�\n");
		}
		m = x(b) + x(c) - x(a);
		if (m > 0) {
			printf("������������������Ρ�\n");
		} else if (m == 0) {
			printf("����������ֱ�������Ρ�\n");
		} else if (m < 0) {
			printf("���������Ƕ۽������Ρ�\n");
		}
	}


	system("PAUSE");
	return 0;
}