/*调和级数求和*/
#include <stdio.h>
long u, v;

/*计算两个分数u/v+a/b求和后的分子分母，暂不变成小数*/
void addrat(int a, int b) {
	u = u * b + v * a;
	v *= b;

}

/*约分(辗转相除法)*/
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
	if (numcopy != 0) { /*最后一轮的除数即最大公约数*/
		u /= numcopy;
		v /= numcopy;

	}
}




int main() {
	int n, nterm;
	printf("\n欢迎使用调和级数求和程序\n\n");
	printf("请输入需要求和调和级数的项数：");
	scanf("%d", &n);


	if (n <= 0) {
		printf("Bad data!");

	} else {
		u = 0;
		v = 1;
		for (nterm = 1; nterm <= n; nterm++) {
			addrat(1, nterm);
			lowterm();
			printf("%d个项数的和：%d/%d\n", nterm, u, v);

		}
	}
	return 0;
}