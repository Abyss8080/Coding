/*���ͼ������*/
#include <stdio.h>
long u, v;

/*������������u/v+a/b��ͺ�ķ��ӷ�ĸ���ݲ����С��*/
void addrat(int a, int b) {
	u = u * b + v * a;
	v *= b;

}

/*Լ��(շת�����)*/
void lowterm() {
	int numcopy, dencopy;
	int remainder;
	numcopy = u;
	dencopy = v;
	while (dencopy != 0) {
		remainder = numcopy % dencopy;
		numcopy = dencopy;
		dencopy = remainder;
	}
	if (numcopy != 0) { /*���һ�ֵĳ��������Լ��*/
		u /= numcopy;
		v /= numcopy;

	}
}




int main() {
	int n, nterm;
	printf("\n��ӭʹ�õ��ͼ�����ͳ���\n\n");
	printf("��������Ҫ��͵��ͼ�����������");
	scanf("%d", &n);


	if (n <= 0) {
		printf("Bad data!");

	} else {
		u = 0;
		v = 1;
		for (nterm = 1; nterm <= n; nterm++) {
			addrat(1, nterm);
			lowterm();
			printf("%d�������ĺͣ�%d/%d\n", nterm, u, v);

		}
	}
	return 0;
}