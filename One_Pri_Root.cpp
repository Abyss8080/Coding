#include<stdio.h>
#define MAX 64
#define infi 1073741824//这里其实只实现了30bits大小的数字
int Mdouble[MAX];//M的二进制表示数组
char Prime[infi];

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
	while (i < k-1 ){
		i = i + 1;
		A[i] = pow(A[i - 1], 2) % N;
		B[i] = B[i - 1] * pow(A[i], Mdouble[i]) % N;
	}
	return B[i];
}

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
long long int One_Pri_Roots(long long int m) {
	Find_Prime(m);
	if (Prime[m] == 0 || m <= 0) {
		printf("No!\n");
	}
	else if (m == 2)  return 1;
	else if (Prime[m] == 1)//m是个奇素数
	{
		bool find = false;
		long long int i = 2, g = 1;
		while (!find && g < m) {
			while (i <= m) {
				if (Prime[i] == 1 && (m - 1)% i == 0) {
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
			while(g<m&&get_gcd(g,m)!=1)g++;
			i = 2;
		}
		if (g >= m)g = -1;
		printf("----------------------------------\n");
		printf("One Primary Root = %lld\n", g);
		printf("----------------------------------\n");
		return g;
	}
}
void All_Pri_Roots(long long int m) {
	long long int result = One_Pri_Roots(m);
	if (result == -1)
		printf("%lld has no primary roots!\n", m);
	else {
		long long int d = 1;
		long long int count = 0;
		printf("%lld has primary roots:\n", m);
		for (d = 1; d < m - 1; d++) {
			if (get_gcd(d, m - 1) == 1)
			{
				count++;
				printf("%lld\t", Mod(result, d, m));
				if (count % 5 == 0)printf("\n");
			}
		}
		printf("\n----------------------------------\n");
		printf("count = %lld\n", count);
		printf("----------------------------------\n");
	}
}
int main(){
	long long int m=41;
//	One_Pri_Roots(m);
	All_Pri_Roots(m);
	return 0;
}
