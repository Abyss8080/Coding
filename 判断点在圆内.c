#include <stdio.h>
#include <stdlib.h>

typedef struct data1 {
	double x;
	double y;
} POINT;

typedef struct data2 {
	double x;
	double y;
	double r;
} CIRCLE;

int inCircle(POINT p, CIRCLE q) {
	double i, j;
	i = (p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y);
	if (i >= q.r )
		return 0;
	else
		return 1;
}


int main() {
	int k;
	POINT P;
	CIRCLE Q;

	printf("������Բ��Բ������Ͱ뾶��\n""���ݼ��á�,������\n");
	scanf("%lf,%lf,%lf", &Q.x, &Q.y, &Q.r);

	printf("�����������꣺\n""���ݼ��á�,������\n");
	scanf("%lf,%lf", &P.x, &P.y);

	k = inCircle(P, Q);
	if (k = 1) {
		printf("����Բ�ڡ�\n");
	} else if (k = 0) {
		printf("�㲻��Բ�ڡ�\n");
	}
	system("PAUSE");
	return 0;
}