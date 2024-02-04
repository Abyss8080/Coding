#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#define MAX 64
#define infi 1073741824//64bits数字开根后小于30亿4千万，但是数组要求不能超过0x7fffffff，所以这里其实只实现了60bits大小的数字
int Mdouble[MAX];//M的二进制表示数组
char Prime[infi] = { 0 };
long long int E, N, D;//公共密钥(e,n),秘密密钥d

//按二进制表示M
int changeM(long long int m) {
	int i = 0, j = 0;
	long long int m1 = m;
	while (m1 != 0) {
		Mdouble[i] = m1 % 2;
		m1 /= 2;
		i += 1;
	}
	return i;
}

//i的j次方,在这里j最大为2
long long int pow(long long int i,int j) {
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
long long int Mod(int A0,long long int M, long long int N) 
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
	if (a < b)//让a >= b
	{
		long long int t = a;
		a = b;
		b = t;
	}
	t1 = a;
	t2 = b;
	t = t1 % t2;
	while (t!=0) {
		t1 = t2;
		t2 = t;
		t = t1 % t2;
	}
	return t2;
}

//找一个和f（n）互素的整数e--->最大公因数为1
long long int get_e(long long int fn) 
{
	long long int e=2;
	long long int max = 0 ;
	while (max != 1)
	{
		e++;
		max = get_gcd(e,fn);
	}
	return e;
}

//找e的逆元素d
long long int get_d(long long int fn) 
{
	long long int d=1;//ed=1(mod fn) (d(mod fn)e(mod fn))(mod fn)=1
	long long int d1 = d % fn;
	long long int e1 = E % fn;
	long long int ans = (d1 * e1) % fn;//ans溢出？？
	while (ans!=1) 
	{
		d++;
		d1 = d % fn;
		ans = (d1 * e1) % fn;
	}
	return d;
}

//创建密钥
void create_keys(void)
{
	int q, p;
	printf("Please input two prime numbers:\nForm Belike:3 5\n");
	scanf("%d %d", &q, &p);
	long long int fn;
	N = (long long int)q * (long long int)p;
	fn = (long long int)(q - 1) * (long long int)(p - 1);
	E = get_e(fn);
	D = get_d(fn);
	printf("(e,fn)==1,fn = %lld\n", fn);
	printf("Public keys (e,n) = (%lld,%lld)\n", E, N);
	printf("Personal key d = %lld\n", D);
}

//加密
void Encrypt(void)
{
	long long int m;
	printf("Please input the number waiting to be encrypted:");
	scanf("%lld", &m);
	long long int c = Mod(m, E, N);
	printf("Encrypt result = %lld\n",c);
}

//解密
void Decode(void)
{
	long long int c;
	printf("Please input the number waiting to be decoded:");
	scanf("%lld", &c);
	long long int m = Mod(c, E, N);
	printf("Encode result = %lld\n", m);
}

//找到64bits数开根号后所有正素数
void Find_prime(void) {
	Prime[2] = Prime[3] = 1;
	long long int i;
	long long int sq;
	bool is_prime = true;
	long long j;
	for (i = 4; i < infi; i++) {
		is_prime = true;
		sq = sqrt(i);
		j = 2;
		while (j <= sq) {
			if (i % j == 0) {
				is_prime = false;
				break;
			}
			j += 1;
			while (Prime[j] != 1)j++;
		}
		if (is_prime)
			Prime[i] = 1;
	}
}

//判断是否为正素数
bool is_positive_prime(long long int n) {
	if (n < infi)
		return Prime[n] == 1;
	long long int sq = sqrt(n);
	long long int j = 2;
	bool is_prime = true;
	while (j <= sq) {
		if (n % j == 0) {
			is_prime = false;
			break;
		}
		j += 1;
		while (Prime[j] != 1)j++;
	}
	return is_prime;
}

//勒让得符号求值（a/p）
int Lengendre(void) {
	int result;
	long long int a, p;
	printf("Welcome to Lengendre Realization System!\n");
	while (true) {
		printf("Please input \"a p\" respectfully to calculate (a/p):\n");
		scanf("%lld %lld", &a, &p);
		if (!is_positive_prime(p)) {
			printf("p is not permitted!\n");
			continue;
		}
		else if (get_gcd(a, p) != 0)
		{
			printf("(a,p) is not '1'!\n");
			continue;
		}
		else break;
	}
	if (a % p == 0) {
		result = 0;
	}
	else
	{
		if (a >= p) {
			int k = a / p;
			a = a - k * p;
		}
		long long int modp = Mod(a, (p - 1) / 2, p);
		if (modp == 1) {
			result = 1;
		}
		else result = -1;
	}
	return result;
}

