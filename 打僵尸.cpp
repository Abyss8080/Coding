#include <stdio.h>
#define MAX 5000

typedef struct {
	int x;
	int y;
} Zombie;

int Exclude(Zombie *zombie, int n, int base) {
	int i, j;
	Zombie temp;
	i = 0;
	j = n - 1;
	while (i < j) {
		while (zombie[i].x < base && i < j)
			i++;
		while (zombie[j].x > base && j > i)
			j--;
		if (i < j) {
			temp = zombie[i];
			zombie[i] = zombie[j];
			zombie[j] = temp;
		}
	}
	return i;
}

void SelectSort(Zombie *zombie, int n, int base) {
	int i, j, k;
	Zombie temp;
	n = Exclude(zombie, n, base);
	for (i = 0; i < n - 1; i++) {
		k = i;
		for (j = i + 1; j < n; j++) {
			if (zombie[j].x > base)
				return;
			else {
				if (zombie[j].y < zombie[k].y)
					k = j;
			}
		}
		if (k != i) {
			temp = zombie[i];
			zombie[i] = zombie[k];
			zombie[k] = temp;
		}
	}
}

int main() {
	int n, m, h, b;
	scanf("%d %d %d %d", &n, &m, &h, &b);
	int i, left, num;
	Zombie zombie[MAX];
	for (i = 0; i < n; i++)
		scanf("%d %d", &zombie[i].x, &zombie[i].y);
	SelectSort(zombie, n, h + b);
	left = m;
	num = 0;
	for (i = 0; i < n; i++) {
		if (h + b < zombie[i].x || left <= 0)
			break;
		if (left >= zombie[i].y) {
			num++;
			left = left - zombie[i].y;
		}
	}
	printf("%d", num);
	return 0;
}

/*��Ŀ
��ͷ������Ģ��ɭ�֣������� nn ֻ��ʬĢ����ÿֻ��ʬĢ��������ֵΪ x ��Ѫ��Ϊ y ��
ֻ����ͷ��������ֵ���ڵ��ڹ��������ֵ�����ܶԹ�������˺���
��ͷ��һ���� m ������ֵ����ÿ�ι���������һ��������
Ȼ�����һ���˺������幥����ĳ������Ѫ������ 1����
������֪��ͷ���Ļ�������ֵΪh������װ�����ӵ�����ֵΪ b��
������ͷ������֪��һ����ɱ�����ٸ���ʬĢ����

�����ʽ
��һ���ĸ����� n,m,h,b���ֱ��ʾ��ʬĢ��������������ֵ����������ֵ��װ��������ֵ�ӳɣ�
��������֮����һ���ո�ָ���
������ n �У�ÿ���������� x,y����ʾÿ����ʬĢ��������ֵ��Ѫ��������֮����һ���ո�ָ���

�����ʽ
һ����������ʾ��ɱ���Ľ�ʬĢ��������
*/