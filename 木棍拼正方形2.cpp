#include <stdio.h>
#include <string.h>
#define MAXN 20
int n, p[MAXN], pile[MAXN];
int total = 0;
int is = 0;

void DFS(int id, int nowsum, int num) {
	if (nowsum > total / 4 || is == 1)
		return;
	if (id == 4 && nowsum == total / 4) {
		is = 1;
		return;
	}
	if (nowsum == total / 4) {
		int i = 0;
		for (i = 0; i < n; i++)
			if (pile[i] == 0)
				break;
		DFS(id + 1, 0, i);
	} else {
		if (num >= n)
			return;
		pile[num] = 1;
		int i = 0;
		for (i = num + 1; i < n; i++)
			if (pile[i] == 0)
				break;
		DFS(id, nowsum + p[num], i);
		pile[num] = 0;
		DFS(id, nowsum, i);
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]);
		total += p[i];
	}
	memset(pile, 0, sizeof(pile));
	if (total % 4 == 0) {
		DFS(1, 0, 0);
		if (is)
			printf("Yes");
		else
			printf("No");
	} else
		printf("No");
	return 0;
}
