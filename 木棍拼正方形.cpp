#include <stdio.h>
#define MAXN 20
int n, p[MAXN];
int is = 0;

int check(int l1, int l2, int l3, int l4) {
	return l1 == l2 && l2 == l3 && l3 == l4 && l4 != 0;
}

void DFS(int num, int l1, int l2, int l3, int l4) {
	if (num >= n || is == 1)
		return;
	if (num >= 3 && check(l1, l2, l3, l4)) {

		is = 1;
		return;
	}
	DFS(num + 1, l1 + p[num], l2, l3, l4);
	DFS(num + 1, l1, l2 + p[num], l3, l4);
	DFS(num + 1, l1, l2, l3 + p[num], l4);
	DFS(num + 1, l1, l2, l3, l4 + p[num]);

}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &p[i]);
	DFS(0, 0, 0, 0, 0);
	if (is)
		printf("Yes");
	else
		printf("No");
	return 0;
}
