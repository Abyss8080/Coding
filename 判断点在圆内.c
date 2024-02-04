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

	printf("请输入圆的圆心坐标和半径：\n""数据间用‘,’连接\n");
	scanf("%lf,%lf,%lf", &Q.x, &Q.y, &Q.r);

	printf("请输入点的坐标：\n""数据间用‘,’连接\n");
	scanf("%lf,%lf", &P.x, &P.y);

	k = inCircle(P, Q);
	if (k = 1) {
		printf("点在圆内。\n");
	} else if (k = 0) {
		printf("点不在圆内。\n");
	}
	system("PAUSE");
	return 0;
}