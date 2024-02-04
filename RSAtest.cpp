#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)
#pragma warning(disable:6031)
#define MAX 64
int Mdouble[MAX];//M�Ķ����Ʊ�ʾ����
long long int E, N, D;//������Կ(e,n),������Կd
//�������Ʊ�ʾM
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

//i��j�η�,������j���Ϊ2
long long int pow(long long int i,int j) {
	long long int goal = 1;
	int j1 = j;
	while (j1 > 0) {
		goal *= i;
		j1 -= 1;
	}
	return goal;
}

//ģ�ظ�ƽ����
long long int Mod(int A0,long long int M, long long int N) 
{
	int i = 0;
	long long int B[MAX], A[MAX];
	int k = changeM(M);//M�������Ʊ�ʾ��λ��-1��<32;
	A[0] = A0;
	B[0] = pow(A[0], Mdouble[0]) % N;
	while (i < k) {
		i = i + 1;
		A[i] = pow(A[i - 1], 2) % N;
		B[i] = B[i - 1] * pow(A[i], Mdouble[i]) % N;
	}
	return B[i];
}

//���������
long long int get_gcd(long long int a, long long int b) 
{
	long long int t, t1, t2;
	if (a < b)//��a >= b
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


//��һ����f��n�����ص�����e--->�������Ϊ1
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

//��e����Ԫ��d
long long int get_d(long long int fn) 
{
	long long int d=1;//ed=1(mod fn) (d(mod fn)e(mod fn))(mod fn)=1
	long long int d1 = d % fn;
	long long int e1 = E % fn;
	long long int ans = (d1 * e1) % fn;//ans�������
	while (ans!=1) 
	{
		d++;
		d1 = d % fn;
		ans = (d1 * e1) % fn;
	}
	return d;
}

//������Կ
void create_keys(void)
{
	int q, p;
	printf("Form Belike:3 5\nPlease input two prime numbers:");
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

//����
void Encrypt(void)
{
	long long int m;
	printf("Please input the number waiting to be encrypted:");
	scanf("%lld", &m);
	long long int c = Mod(m, E, N);
	printf("Encrypt result = %lld\n",c);
}

//����
void Decode(void)
{
	long long int c;
	printf("Please input the number waiting to be decoded:");
	scanf("%lld", &c);
	long long int m = Mod(c, E, N);
	printf("Encode result = %lld\n", m);
}

//������Կ(E,N),������ԿD
int main() {
	int choice = 0;
	create_keys();
	/*printf("Welcome to CodeED System!\n");
	while(1) 
	{
		printf("Please choose function:\n1.Encrypt\n2.Decode\n3.Quit System\n");
		printf("Your choice:"); 
		scanf("%d", &choice);
		if (choice == 1)
			Encrypt();
		else if (choice == 2)
			Decode();
		else if (choice == 3)
			break;
		else continue;
	}*/
	return 0;
}





