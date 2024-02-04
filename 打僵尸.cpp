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

/*题目
蒜头君来到蘑菇森林，这里有 nn 只僵尸蘑菇，每只僵尸蘑菇的闪避值为 x ，血量为 y 。
只有蒜头君的命中值大于等于怪物的闪避值，才能对怪物造成伤害。
蒜头君一共有 m 点能量值，他每次攻击会消耗一点能量，
然后造成一点伤害（单体攻击，某个怪物血量减少 1）。
现在已知蒜头君的基础命中值为h，身上装备增加的命中值为 b。
现在蒜头君他想知道一共能杀死多少个僵尸蘑菇。

输入格式
第一行四个整数 n,m,h,b，分别表示僵尸蘑菇的数量，能量值，基础命中值，装备的命中值加成，
相邻两数之间以一个空格分隔。
接下来 n 行，每行两个整数 x,y，表示每个僵尸蘑菇的闪避值和血量，两数之间以一个空格分隔。

输出格式
一个整数，表示能杀死的僵尸蘑菇数量。
*/