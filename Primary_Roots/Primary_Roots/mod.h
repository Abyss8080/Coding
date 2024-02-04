#pragma once
#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable: 6031)
#pragma warning(disable: 4996)
#define MAX 64
#define infi 16777216//这里其实只实现了24bits大小的数字
int Mdouble[MAX];//M的二进制表示数组
char Prime[infi];
char Root[infi / 2];//2/4/素时，=1；a=2时，=2；a>2,k=1时，=3；a>2,k=2时，=4；
long long int result = 0;

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
		t *= a;
	}
	return (long long int)(t);
}

//找到<=n所有正素数(n>0)，返回这些正素数的个数；
//count初始为n，表示《=n的正素数个数
long long int Find_Prime(long long int n) {
	if (n <= 1) return 0;
	else if (n == 2) {
		Prime[n] = 1;
		return 1;
	}
	else if (n == 3) {
		Prime[n] = 1;
		Prime[2] = 1;
		return 2;
	}
	//以下是>=4的情况
	long long int pri_number = Find_Prime(n - 1);
	long long int sqn = sqrt(n);
	bool is_prime = true;
	long long int i;
	i = 2;
	while (i <= sqn) {
		if (n % i == 0) {
			is_prime = false;
			break;
		}
		i++;
		while (Prime[i] != 1 && i <= sqn)i++;
	}
	if (is_prime) {
		Prime[n] = 1;
		pri_number++;
	}
	return pri_number;
}

//找一个m的原根，只实现到正奇素数和2和4
long long int One_Pri_Roots(long long int m) {
	if (m == 4)return 3;
	else if (m == 2) return 1;
	else if (Prime[m] == 1)//m是个奇素数
	{
		bool find = false;
		long long int i = 2, g = 1;
		while (!find && g < m) {
			while (i <= m) {
				if (Prime[i] == 1 && (m - 1) % i == 0) {
					if (Mod(g, (m - 1) / i, m) == 1) {
						break;
					}
				}
				i++;
			}
			if (i > m) {
				find = true;
				break;
			}
			g++;
			i = 2;
		}
		//printf("----------------------------------\n");
		//printf("One Primary Root = %lld\n", g);
		//printf("----------------------------------\n");
		return g;
	}
}

//只实现到正奇素数和2和4
void All_Pri_Roots(long long int m) {
	result = One_Pri_Roots(m);
	long long int d = 1;
	//long long int count = 0;
	for (d = 1; d <= m - 1; d++) {
		if (get_gcd(d, m - 1) == 1)
		{
			long long int temp = Mod(result, d, m);
			Root[temp] = 1;
			//count++;
			//printf("%lld\t", temp);
			//if (count % 5 == 0)printf("\n");
		}
	}
	//printf("\n----------------------------------\n");
	//printf("count = %lld\n", count);
	//printf("----------------------------------\n");
}

//试图将m写成 k*（p^a）形式 , k=1 or 2(直接判断奇偶),p是奇素数
bool CheckM(long long int m, int* k, long long int* p, long long int* a) {
	bool flag = false;
	long long int temp = 1;
	if (m % 2 == 0) {
		*k = 2;
		m = m / 2;
	}
	else
		*k = 1;
	for (long long int i = 3; i < m; i++)
	{

		if (Prime[i] == 1)
		{
			*p = i;
			while (m % (*p) == 0) {
				(*a)++;
				m = m / (*p);
			}
			if (m == 1) flag = true;
		}
		if (flag)break;
	}
	return flag;
}

//实现k*（p^a）的原根求解,有p^a(a>=2),2p^a(a>=1)两种大情况,p是奇素数
void All_Pri_Roots1(long long int m, int k, long long int p, long long int a) {
	All_Pri_Roots(p);
	long long int i = 1;
	//标注k=1，a=1时的原根，=1
	//标注k=1，a>=2时的原根，=10
	//标注k=2，a》=1时的原根，=100
	while (i < m) {
		while (Root[i] != 1 && i < m)i++;
		long long int temp1 = Expon(i, p - 1);
		long long int temp2 = Expon(i + p, p - 1);
		if (Mod(i, p - 1, p) == 1 && get_gcd((temp1 - 1) / p, p) == 1)
		{
			Root[i] += 10;
			result = i;
		}
		if (Mod(i + p, p - 1, p) == 1 && get_gcd((temp2 - 1) / p, p) == 1)
		{
			Root[i + p] += 10;
			result = i;
		}
		if (k == 2 && Root[i] >= 10) {
			if (i % 2 == 1)
			{
				Root[i] += 100;
				result = i;
			}
			else
			{
				long long int t = i + Expon(p, a);
				Root[t] += 100;
				result = t;
			}
		}
	}
}


void Simplify_Surplus_System(long long int m) {
	long long int i = 1, num = 0;//简化剩余系个数
	long long int count = 0;
	while (i < m) {
		if (get_gcd(i, m) == 1)
			num++;
		i++;
	}
	printf("\n%lld's simplify surplus system:\n", m);
	for (i = 0; i < num; i++) {
		printf("%lld\t", Mod(result, i, m));
		count++;
		if (count % 5 == 0)printf("\n");
	}
}


//标注k=1，a=1时的原根，=1
//标注k=1，a>=2时的原根，=10
//标注k=2，a>=1时的原根，=100
//打印原根及简化剩余系
void Print(int size, long long int m) {
	long long int i = 0;
	long long int count = 0;
	printf("%lld has primary roots:\n", m);
	for (i = 0; i < m; i++) {
		switch (size) {
		case 1:
			if (Root[i] % 10 == 1)
			{
				printf("%lld\t", i);
				count++;
				if (count % 5 == 0)printf("\n");
			}
			break;
		case 10:
			if (Root[i] % 100 >= 10)
			{
				printf("%lld\t", i);
				count++;
				if (count % 5 == 0)printf("\n");
			}
			break;
		case 100:
			if (Root[i] / 100 == 1) {
				count++;
				printf("%lld\t", i);
				if (count % 5 == 0)printf("\n");
			}
			break;
		}
	}
	Simplify_Surplus_System(m);
}


void Pri_Roots_System(void)
{
	long long int m;
	long long int p = 0, a = 0;
	bool flag = true;
	int k = 1;
	printf("Please input the number of which you want to primary roots: ");
	scanf("%lld", &m);
	Find_Prime(m);
	if (m <= 0)
		printf("%lld has no primary roots!\n", m);
	else if (m == 2 || m == 4 || Prime[m] == 1)
	{
		All_Pri_Roots(m);//只实现到正奇素数和2和4
		Print(1, m);
	}
	else {
		flag = CheckM(m, &k, &p, &a);
		if (flag == false)printf("%lld has no primary roots!\n", m);
		else {
			All_Pri_Roots1(m, k, p, a);
			if (k == 1)Print(10, m);
			else if (k == 2) Print(100, m);
		}
	}
}
