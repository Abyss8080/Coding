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
	if (groups[j].father == -1 && groups[j].childnum != 0) { //根节点
		for (k = 0; k < groups[j].childnum; k++) {
			if (groups[j].dnum < groups[groups[j].child[k]].dnum) {
				is = 0;
				break;
			}
		}
	} else if (groups[j].father != -1 && groups[j].childnum == 0) {//叶子节点
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

/*题目
输入格式
输入的第一行包含一个整数 t（1\le t\le 1001≤t≤100），表示数据组数。

接下来 t 组数据，每组数据第一行一个数 nn（1\le n\le 10001≤n≤1000），表示树的节点数。

然后 n-1 行，每行两个数 x，y（0\lt x,y\lt n0<x,y<n），
代表 y 是 x 的儿子节点，两数之间以一个空格分隔。

输出格式
输出 t 行，每一行一个整数，代表 p 节点的个数。*/
//有向树的度只算出度