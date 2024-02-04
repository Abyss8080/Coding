#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#pragma warning(disable:4996)
#define MAX 32

int Mdouble[MAX];//M的二进制表示数组
int MK[MAX];//窗口法，M的表示

int changeM(long long int m);//按二进制表示M
long long int pow(int i, int j);//i的j次方
int log2(long long int M);//计算log2（M），向下取整
void changeMK(long long int m, int k);//按窗口法表示M，窗口大小k

//k表示M的二进制位数；
long long int Mod1(int k, int a0, long long int M, long long int N);//模重复平方法1
long long int Mod2(int k, int a0, long long int M, long long int N);//模重复平方法2
long long int Mod3(int a0, long long int M, long long int N);//固定窗口法

int main() {
	int k = 0, a0 = 0;
	long long int M, N;
	printf("a**m mod n = b\nplease input 'a','m','n' respectively:\n ");
	scanf("%d %lld %lld", &a0, &M, &N);
	k = changeM(M);
	clock_t t[4];
	t[0] = clock();
	int b1 = Mod1(k, a0, M, N);
	t[1] = clock();
	int b2 = Mod2(k, a0, M, N);
	t[2] = clock();
	//int b3 = Mod3(a0, M, N);
	//t[3] = clock();

	printf("Mod1:b==%d  耗时：%f\n", b1, (double)(t[1] - t[0]) / CLK_TCK);
	printf("Mod2:b==%d  耗时：%f\n", b2, (double)(t[2] - t[1]) / CLK_TCK);
	//printf("Mod2:b==%d  耗时：%f\n", b3, (double)(t[3] - t[2]) / CLK_TCK);
	
	return 0;
}

int changeM(long long int m) {
	int i = 0, j = 0;
	int m1 = m;
	while (m1 != 0) {
		Mdouble[i] = m1 % 2;
		m1 /= 2;
		i += 1;
	}
	/*printf("%lld=", m);
	j = i - 1;
	while (j >= 0) {
		printf("%d", Mdouble[j]);
		j -= 1;
	}
	printf("\n");*/
	return i;
}

long long int pow(int i, int j) {
	long long int goal = 1;
	int j1 = j;
	while (j1 > 0) {
		goal *= i;
		j1 -= 1;
	}
	//printf("%d**%d = %lld\n", i, j, goal);
	return goal;
}

//向下取整
int log2(long long int M) {
	int goal = 0;
	long long int front = 2, later = 1;
	while (!(front > M && M >= later)) {
		goal += 1;
		later = front;
		front *= 2;
	}
	return goal;
}

void changeMK(long long int m, int k) {
	int k1 = log2(m) + 1;
	int t = k1 / k;
	int t1 = k1 - k * t;
	if (t1 == 0)
	{
		MK[0] = 0;
	}
	else {
		int inf = pow(2, k) - 1;
		int mtemp = m;
		for (int n = t; n > 0; n--) {
			int p = pow(2, k1 - k * (t - n + 1));
			int goal = inf;
			while (goal * p > mtemp) {
				goal--;
			}
			mtemp -= goal * p;
			MK[n] = goal;
		}
		MK[0] = mtemp;
	}
}

long long int Mod1(int k, int a0, long long int M, long long int N) {
	int A[MAX], i = 0;
	long long int B[MAX];
	A[0] = a0;
	B[0] = pow(A[0], Mdouble[0]) % N;
	while (i < k) {
		i = i + 1;
		A[i] = int(pow(A[i - 1], 2) % N);
		B[i] = B[i - 1] * pow(A[i], Mdouble[i]) % N;
	}

	return B[i];
}

long long int Mod2(int k, int a0, long long int M, long long int N) {
	int i = k;
	int A[MAX];
	long long int B[MAX];
	A[k] = 1;
	B[k] = pow(a0, Mdouble[k]) % N;
	while (i > 0) {
		i -= 1;
		A[i] = pow(B[i + 1], 2) % N;
		B[i] = A[i] * pow(a0, Mdouble[i]) % N;
	}

	return B[0];

}

long long int Mod3(int a0, long long int M, long long int N) {
	int k1 = log2(M) + 1;
	int k;
	printf("please input windows size:");
	scanf("%d", &k);
	int t = k1 / k;
	int t1 = k1 - k * t;
	int i = t;
	changeMK(M, k);

	long long int a = pow(a0, MK[i]) % N;
	long long int b1 = a;
	long long int b0;
	while (i > 1) {
		i--;
		a = pow(a0, MK[i]) % N;
		b1 = (a * pow(b1, pow(2, k))) % N;
	}
	if (t1 == 0) {
		b0 = b1;
	}
	else 
		b0 = pow(b1, t1) * pow(a0, MK[0]);
	return b0;
}