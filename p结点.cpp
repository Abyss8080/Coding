#include <stdio.h>
#include <string.h>
#define MAX 1001
#define MAXG 101

typedef struct {
	int dnum;
	int child[MAX];
	int childnum;
	int father;
} Groups;
Groups groups[MAX];

int isP(Groups *groups, int j) {
	int is = 1;
	int k;
	if (groups[j].father == -1 && groups[j].childnum != 0) { //���ڵ�
		for (k = 0; k < groups[j].childnum; k++) {
			if (groups[j].dnum < groups[groups[j].child[k]].dnum) {
				is = 0;
				break;
			}
		}
	} else if (groups[j].father != -1 && groups[j].childnum == 0) {//Ҷ�ӽڵ�
		if (groups[j].dnum < groups[groups[j].father].dnum)
			is = 0;
	} else if (groups[j].father != -1 && groups[j].childnum != 0) {
		if (groups[j].dnum < groups[groups[j].father].dnum)
			is = 0;
		else {
			for (k = 0; k < groups[j].childnum; k++) {
				if (groups[j].dnum < groups[groups[j].child[k]].dnum) {
					is = 0;
					break;
				}
			}
		}
	}
	return is;
}

int main() {
	int t, n;
	int i, j, k;
	int x, y;
	int result[MAXG];
	for (i = 0; i < MAXG; i++)
		result[i] = 0;
	for (i = 1; i < MAX; i++)
		groups[i].father = -1;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		scanf("%d", &n);
		if (n == 1) {
			result[i]++;
			continue;
		}
		for (j = 1; j <= n; j++) {
			groups[j].dnum = 0;
			groups[j].childnum = 0;
			groups[j].father = -1;
		}
		for (j = 0; j < n - 1; j++) {
			scanf("%d %d", &x, &y);
			groups[x].dnum++;
//			groups[y].dnum++;
			groups[x].child[groups[x].childnum] = y;
			groups[x].childnum++;
			groups[y].father = x;
		}
		for (j = 1; j <= n ; j++) {
			if (isP(groups, j))
				result[i]++;
		}
	}
	for (i = 0; i < t; i++)
		printf("%d\n", result[i]);
	return 0;
}

/*��Ŀ
�����ʽ
����ĵ�һ�а���һ������ t��1\le t\le 1001��t��100������ʾ����������

������ t �����ݣ�ÿ�����ݵ�һ��һ���� nn��1\le n\le 10001��n��1000������ʾ���Ľڵ�����

Ȼ�� n-1 �У�ÿ�������� x��y��0\lt x,y\lt n0<x,y<n����
���� y �� x �Ķ��ӽڵ㣬����֮����һ���ո�ָ���

�����ʽ
��� t �У�ÿһ��һ������������ p �ڵ�ĸ�����*/
//�������Ķ�ֻ�����