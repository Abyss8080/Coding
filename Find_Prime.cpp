#include<stdio.h>
#include<stdlib.h>
#define MAX 64
#define infi 16777216//������ʵֻʵ����24bits��С������
int Mdouble[MAX];//M�Ķ����Ʊ�ʾ����
char Prime[infi];
int Root[infi / 2];//2/4/��ʱ��=1��a=2ʱ��=2��a>2,k=1ʱ��=3��a>2,k=2ʱ��=4��

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
long long int pow(long long int i, int j) {
	long long int goal = 1;
	int j1 = j;
	while (j1 > 0) {
		goal *= i;
		j1 -= 1;
	}
	return goal;
}

//��n������
long long int sqrt(long long int n) {
	long long int i = 1;
	while (i * i <= n) {
		i++;
	}
	i = i - 1;
	return i;
}

//ģ�ظ�ƽ����,A0��M�η�ģN
long long int Mod(int A0, long long int M, long long int N)
{
	int i = 0;
	long long int B[MAX], A[MAX];
	int k = changeM(M);//M�������Ʊ�ʾ��λ��-1��<32;
	A[0] = A0;
	B[0] = pow(A[0], Mdouble[0]) % N;
	while (i < k - 1) {
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
	if (a < 0)a = -a;
	if (b < 0)b = -b;
	if (a < b)//��a >= b
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

//������
long long int Expon(long long int a, long long int m) {
	long long int t = 1;
	for (; m > 0; m--)
	{
		t *= a;
	}
	return (long long int)(t);
}

//�ҵ�<=n����������(n>0)��������Щ�������ĸ�����
//count��ʼΪn����ʾ��=n������������
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
	//������>=4�����
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

//��һ��m��ԭ����ֻʵ�ֵ�����������2��4
long long int One_Pri_Roots(long long int m) {
	if (Prime[m] == 0) {
		if (m == 4)return 3;
	}
	else if (m == 2) return 1;
	else if (Prime[m] == 1)//m�Ǹ�������
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

//ֻʵ�ֵ�����������2��4
void All_Pri_Roots(long long int m) {
	long long int result = One_Pri_Roots(m);
	long long int d = 1;
	//long long int count = 0;
	printf("%lld has primary roots!\n", m);
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

//��ͼ��mд�� k*��p^a����ʽ , k=1 or 2(ֱ���ж���ż),p��������
bool CheckM(long long int m,int *k, long long int* p, long long int* a) {
	bool flag = false;
	long long int temp=1;
	if (m % 2 == 0) {
		*k = 2;
		m = m / 2;
	}
	else
		*k = 1;
	for (long long int i = 3; i < m; i++)
	{
		*p = Prime[i];
		if (*p == 1)
		{
			while (m % (*p) == 0) {
				(*a)++;
				m = m / (*p);
			}
			if (m == 1) flag = true;
		}
	}
	return flag;
}

//ʵ��k*��p^a����ԭ�����,��p^a(a>=2),2p^a(a>=1)���ִ����,p��������
void All_Pri_Roots1(long long int m, int k, long long int p, long long int a) {
	All_Pri_Roots(p);
	long long int i = 1;
	//��עk=1��a=1ʱ��ԭ����=1
	//��עk=1��a=2ʱ��ԭ����=10
	//��עk=1��a>2ʱ��ԭ����=100
	//��עk=2��a��=1ʱ��ԭ����=1000
	while (Root[i] == 1) {
		long long int temp1 = Expon(i, p - 1);
		long long int temp2 = Expon(i + p, p - 1);
		if (Mod(i, p - 1, p) == 1 && get_gcd((temp1 - 1) / p, p) == 1)
		{
			Root[i] += 10;
		}
		if (Mod(i + p, p - 1, p) == 1 && get_gcd((temp2 - 1) / p, p) == 1)
		{
			Root[i + p] += 10;
		}
		if (Root[i] == 2)Root[i] += 100;
		if (k == 2 && Prime[i] > 0) {
			if (i % 2 == 1)Prime[i] += 1000;
			else Prime[i + Expon(p, a)] += 1000;
		}
	}
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
		printf("Way1:\n");
		All_Pri_Roots(m);//ֻʵ�ֵ�����������2��4
	}
	else {
			flag = CheckM(m, &k,&p, &a);
		if (flag == false)printf("%lld has no primary roots!\n", m);
		else {
			printf("Way2:\n");
			All_Pri_Roots1(m, k, p, a);
		}
	}
}
