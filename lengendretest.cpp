#include<stdio.h>
#include<stdlib.h>
#define MAX 64
#define infi 1073741824//这里其实只实现了30bits大小的数字
int Mdouble[MAX];//M的二进制表示数组
char Prime[infi];

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

//找到小于等于根号n所有正素数
void Find_prime1(long long int n) {
	Prime[2] = Prime[3] = 1;
	long long int i, sqi;
	long long int sqn = sqrt(n);
	bool is_prime = true;
	long long j;
	for (i = 4; i <= sqn; i++) {
		if (i % 2 == 0)continue;
		is_prime = true;
		sqi = sqrt(i);
		j = 2;
		while (j <= sqi) {
			if (i % j == 0) {
				is_prime = false;
				break;
			}
			j += 1;
			while (Prime[j] != 1 && j <= sqi)j++;
		}
		if (is_prime)Prime[i] = 1;
	}
}

//找到小于等于n所有正素数
void Find_prime2(long long int n) {
	Find_prime1(n);
	long long int sqn = sqrt(n),sqi;
	bool is_prime = true;
	long long int j = 2;
	for (long long int i = sqn; i <= n; i++) {
		if (i % 2 == 0)continue;
		is_prime = true;
		j = 2;
		sqi = sqrt(i);
		while (j<=sqi) {
			if (i % j == 0) {
				is_prime = false;
				break;
			}
			j += 1;
			while (Prime[j] != 1 && j <= sqi)j++;
		}
		if (is_prime)Prime[i] = 1;
	}
}

//判断是否为正素数
bool is_positive_prime(long long int n) {
	long long int sq = sqrt(n);
	long long int j = 2;
	bool is_prime = true;
	while (j <= sq) {
		if (n % j == 0) {
			is_prime = false;
			break;
		}
		j += 1;
		while (Prime[j] != 1 && j <= sq)j++;
	}
	return is_prime;
}

//判断乘积是不是偶数,偶数返回1
int mul_is_even(long long int i, long long int j) {
	if (i % 2 == 1 && j % 2 == 1)
		return -1;
	return 1;
}

//勒让得符号求值（a/p）,进入函数的ap互素且p是素数
int Lengendre(long long int a, long long int p) {
	if (p < 0)p = -p;
	if (p != 2) {
		if (a % p == 0)return 0;
		if (a == 1)return 1;
		if (a == -1)return mul_is_even((p - 1) / 2, 1);
		if (a < -1) return Lengendre(-1, p) * Lengendre(-a, p);
		//以下是a>1，p奇素的情况
		if (a >= p) {//这里不用考虑k超界，只要a，p不超，k就不超
			long long int k = a / p;
			a = a - (long long int)(k * p);
		}
		if (a * 1000 < p && is_positive_prime(a))return mul_is_even((a - 1) / 2, (p - 1) / 2) * Lengendre(p, a);//如果a，p大小悬殊
		else {
			long long int modp = Mod(a, (p - 1) / 2, p);
			if (modp != 1)
				return -1;
			else return 1;
		}
	}
	//以下是p==2时；
	if (a % 2 == 1)return 1;
	else return 0;
}

void Lengendre_System(void) {
	long long int a, p;
	printf("\nWelcome to Lengendre Realization System!\n");
	while (true) {
		printf("Please input \"a p\" respectfully to calculate (a/p):\n");
		scanf("%lld %lld", &a, &p);
		Find_prime1(p);
		if (!is_positive_prime(p) || !is_positive_prime(-p)) {//p==1没有传进去
			printf("p is not permitted!\n");
			continue;
		}
		else if (get_gcd(a, p) != 1)
		{
			printf("(a,p) is not '1'!\n");
			continue;
		}
		else break;
	}
	printf("Lengendre : ( %lld / %lld ) == %d\n", a, p, Lengendre(a, p));
}

//雅可比符号（a/m），进入函数的m奇数,a是任意整数
int Jacobi(long long int a, long long int m) {
	if (m < 0)m = -m;
	if (m == 1)return 0;
	//m>1
	if (a < -1)return mul_is_even((m - 1) / 2, 1) * Jacobi(-a, m);
	else if (a == -1) return mul_is_even((m - 1) / 2, 1);
	else if (a == 0)return 0;
	else if (a == 1) return 1;
	else {//a>1,m>1
		if (a >= m) {
			long long int k = a / m;
			a = a - (long long int)(k * m);
			return Jacobi(a, m);
		}//a>1,a<m
		else {
			long long int gcd = 3;//已知3是素数
			while (gcd <= m) {
				if (m % gcd == 0)
				{
					if(m!=gcd)
					    return Lengendre(a, gcd)* Jacobi(a, m / gcd);
					else return Lengendre(a,m);
				}
				gcd++; 
				while (Prime[gcd] == 0 && gcd <= m) gcd+=1;
			}
		}
	}
}

void Jacobi_System(void) {//m奇整，a整数
	long long int a, m;
	printf("\nWelcome to Jacobi Realization System!\n");
	while (true) {
		printf("Please input \"a p\" respectfully to calculate (a/m):\n");
		scanf("%lld %lld", &a, &m);
		if (m % 2 == 0) {
			printf("m is not permitted!\n");
			continue;
		}
		else break;
	}
	Find_prime2(m);
	printf("Jacobi : ( %lld / %lld ) == %d\n", a, m, Jacobi(a, m));
}

int main() {
	Lengendre_System();
	Jacobi_System();
	return 0;
}
