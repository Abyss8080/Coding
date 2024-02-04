#pragma once
#pragma warning(disable:4996)
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <string.h>
#define MAX 100000//保证包括符号的18位十进制数+1位符号+1位结束符安全只需要20位，这里扩展是防止溢出
#define PRE 20
#define CAN 1000000000//9位

//将字符串转换成超长整型，并取绝对值
long long int trans(char* p) {
	int t = 1;
	long long int goal = 0;
	char temp;
	temp = p[t];
	//printf("\n传入trans的字符串数组是：%s\n", p);
	while (t<PRE-1&&temp!='\0') {
		goal = goal * 10 + (temp - 48);
		temp = p[++t];
	}
	p[t] = '\0';
	return goal;
}

//求最小公倍数并输出
void Minmul(long long int d1, long long int d2, long long int maxfac, char minmul[MAX * 2 + 1]) {
	long long int d1fro, d1bac, d2fro, d2bac;
	long long int A[4], C1, C2;
	long long int B[5];
	d1 = d1 / maxfac;
	//9位的四则运算均可在超长整型中完成
	d1fro = d1 / CAN;
	d1bac = d1 % CAN;
	d2fro = d2 / CAN;
	d2bac = d2 % CAN;
	A[1] = d1bac * d2bac;
	A[2] = d1fro * d2bac + d1bac * d2fro;
	A[3] = d1fro * d2fro;
	B[1] = A[1] % CAN;
	B[2] = (A[1] / CAN + A[2] % CAN) % CAN;
	C1 = (A[1] / CAN + A[2] % CAN) / CAN;
	B[3] = (C1 + A[2] / CAN + A[3] % CAN) % CAN;
	C2 = (C1 + A[2] / CAN + A[3] % CAN) / CAN;
	B[4] = A[3] / CAN + C2;//结果按读的顺序是B4321；

	//将超长整型转换成字符串数组
	for (int i = 4; i > 0; i--) {
		for (int j = (5 - i) * 9 - 1; j >= (4 - i) * 9; j--) {
			minmul[j] = B[i] % 10;
			B[i] /= 10;
		}
	}
}

//求最大公因数并根据func号选择输出最大公因数或者最小公倍数或者两者，并利用指针将其传回主函数
void Maxfac_Minmul(char* dividend, char* divider, long long int* max, char min[MAX * 2]) {
	long long int  t1, t2, t;
	long long int tm1, tm2;
	int func = -1;
	bool flag = 0;
	dividend = (char*)malloc(sizeof(char) * MAX);
	divider = (char*)malloc(sizeof(char) * MAX);
	printf("\n请输入待求最大公因数或最小公倍数的18位以内的两个整数：\n例如：+126721 -823789\n");
	scanf("%s", dividend);
	//printf("\n%s", dividend);
	scanf("%s", divider);
	//printf("\n%s", divider);
	t1 = tm1 = trans(dividend);
	t2 = tm2 = trans(divider);
	//printf("\nt1==%lld\n\nt2==%lld\n", t1, t2);

	if (t1 < t2) {
		t = t1;
		t1 = t2;
		t2 = t;
	}//t1>=t2

	while (t2 != 0) {
		t = t1 % t2;
		t1 = t2;
		t2 = t;
	}//辗转相除法
	*max = t1;//最大公因数计算完毕

	do {
		printf("请选择功能：\n0：既求最大公因数，又求最小公倍数；\n1：只求最大公因数；\n2：只求最小公倍数。\n");
		scanf("%1d", &func);
	} while (func > 2 || func < 0);

	if (func == 1) {
		printf("\n数%s与数%s的最大公因数是：%lld\n", dividend, divider, t1);
	}
	else {
		if(func==0)
		    printf("\n数%s与数%s的最大公因数是：%lld\n", dividend, divider, t1);

		Minmul(tm1, tm2, t1, min);
        printf("\n数%s与数%s的最小公倍数是：", dividend, divider);
		for (t = 0; t < PRE * 2 - 4; t++)
		{
			if (!flag && min[t] == 0) {
				continue;
			}
			flag = 1;
			printf("%d", min[t]);
		}
	}
	free(dividend);
	free(divider);
}