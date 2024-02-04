#include <stdio.h>
#include <string.h>
#define MAX 2001
#define MAXN 1000001
int min = MAXN, minr, minl;
int has[MAX], pn[MAXN], vis[MAX];
int M, N;
int l, num;

int allin(void) {
	for (int i = 1; i <= M; i++)
		if (has[i] == 0)
			return 0;
	return 1;
}

int main() {
	l = 1;
	memset(has, 0, sizeof(has));
	memset(vis, 0, sizeof(vis));
	scanf("%d %d", &N, &M);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &pn[i]);
		has[pn[i]]++;
		if (vis[pn[i]] == 0) {
			num++;
			vis[pn[i]] = 1;
		}
		if (num == M ) {
			do {
				has[pn[l]]--;
				l++;
				if (has[pn[l - 1]] == 0 && vis[pn[l - 1]] == 1) {
					num--;
					vis[pn[l - 1]] = 0;
				}
			} while (num == M);
			if (min > (i - l + 2)) {
				minr = i;
				minl = l - 1;
				min = minr - minl + 1;
			}
		}
	}
	printf("%d %d", minl, minr);
	return 0;
}