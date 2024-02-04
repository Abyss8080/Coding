#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 6031)
#pragma warning(disable: 4996)
#define MAX 64
int Mdouble[MAX];//M的二进制表示数组

//按二进制表示M
int changeM(long long int m) {
	int i = 0, j = 0;
	long long int m1 = m;
	if (m1 == 0) {
		Mdouble[0] = 0;
		i += 1;
	}
	else
		while (m1 != 0) {
			Mdouble[i] = m1 % 2;
			m1 /= 2;
			i += 1;
		}
	return i - 1;
}

//i的j次方,在这里j最大为2
long long int pow(long long int i, int j) {
	long long int goal = 1;
	int j1 = j;
	while (j1 > 0) {
		goal *= i;
		j1 -= 1;
	}
	return goal;
}

//对n开根号
long long int sqrt(long long int n) {
	long long int i = 1;
	while (i * i <= n) {
		i++;
	}
	i = i - 1;
	return i;
}

//模重复平方法,A0的M次方模N
long long int Mod(int A0, long long int M, long long int N)
{
	int i = 0;
	long long int B[MAX], A[MAX];
	int k = changeM(M);//M按二进制表示的位数-1，<32;
	A[0] = A0;
	B[0] = pow(A[0], Mdouble[0]) % N;
	while (i < k) {
		i = i + 1;
		A[i] = pow(A[i - 1], 2) % N;
		B[i] = B[i - 1] * pow(A[i], Mdouble[i]) % N;
	}
	return B[i];
}

//找最大公因数
long long int get_gcd(long long int a, long long int b)
{
	long long int t, t1, t2;
	if (a < 0)a = -a;
	if (b < 0)b = -b;
	if (a < b)//让a >= b
	{
		long long int t = a;
		a = b;
		b = t;
	}
	t1 = a;
	t2 = b;
	t = t1 % t2;
	while (t != 0) {
		t1 = t2;
		t2 = t;
		t = t1 % t2;
	}
	return t2;
}

//幂运算
long long int Expon(long long int a, long long int m) {
	long long int t = 1;
	for (; m > 0; m--)
	{
		t = t * a;
	}
	return (long long int)(t);
}

void get_kq(long long n1, long long int* k, long long* q)
{
	*k = 0;
	*q = 0;
	while (n1 % 2 == 0) {
		n1 /= 2;
		(*k)++;
	}
	*q = n1;
}

bool R_M(long long int n) {
	long long int k, q, j, temp, temp1;
	long long int Base[7] = { 2,325,9375,28178,450775,9780504,1795265022 };
	bool flag = false;
	char i = 0;
	if (n < 2)return flag;
	else if (n == 2) return true;
	get_kq(n - 1, &k, &q);
	for (; i < 7; i++) {
		if (Base[i] < n ) {
			long long int temp = Mod(Base[i], q, n);
			if (temp == 1 || temp == n - 1) {
				flag = true;
				break;
			}
			else
			{
				for (j = 0; j < k; j++)
				{
					temp1 = Mod(temp, 2, n);
					if (temp1 == n - 1) {
						flag = true;
						break;
					}
					else if (temp1 == 1)
						return false;
					else
						temp = temp1;
				}
				if (flag)
				    break;
			}
			if (!flag)break;
		}
	}
	return flag;
}

void Rabin_Miler_System(void)
{
	long long int m;
	printf("Please input the number that you wann to check whether it is a prime number by R_M Al:\n");
	scanf("%lld", &m);
	bool flag = R_M(m);
	if (flag)
		printf("%lld is a prime number!\n", m);
	else
		printf("%lld is not a prime number!\n", m);
}