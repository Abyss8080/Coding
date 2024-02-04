#include <stdio.h>
#include <string.h>
#define MAXN 1001
#define MAXM 5001
#define infi 0x3f3f3f3f
#define min(a,b) ((a)>(b)?(b):(a))

typedef struct {
	int v, w;
	int next;
} Edge;
Edge edge[MAXM * 2];
int p[MAXN], eid, n, m, s, d[MAXN], vis[MAXN];

void insert1(int u, int v, int w) {
	Edge t = {v, w, p[u]};
	edge[eid] = t;
	p[u] = eid++;
}

void insert2(int u, int v, int w) {
	insert1(u, v, w);
	insert1(v, u, w);
}

int main() {
	int i, j, t = 0;
	int a, b, c;
	memset(p, -1, sizeof(p));
	memset(d, 0x3f, sizeof(d));
	memset(vis, 0, sizeof(vis));
	s = 1;
	d[s] = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		insert2(a, b, c);
	}
	for (i = 0; i < n; i++) {
		int mind = infi;
		int u = 0;
		for (j = 1; j <= n; j++) {
			if (vis[j] == 0 && d[j] < mind) {
				mind = d[j];
				u = j;
			}
		}
		if (mind == infi)
			break;
		vis[u] = 1;
		for (j = p[u]; j != -1; j = edge[j].next) {
			int v = edge[j].v;
			d[v] = min(d[u] + edge[j].w, d[v]);
		}
	}
//	for (int i = 1; i <= n; i++) {
//		printf("%d ", d[i]);
//	}

	printf("%d", d[n]);
	return 0;
}