#include <stdio.h>
#include <string.h>
#define MAX 1000
#define infi 0x3f3f3f3f

typedef struct {
	int v;
	int w;
	int next;
	int f;
} Edge;

typedef struct {
	int u;
	int v;
	int w;
} Ed;
Edge e[MAX * MAX / 2];
int p[MAX], eid, vis[MAX], d[MAX];
Ed destroy[MAX * MAX / 2];
int n, m, r;
int A, B, minlen;

void insert1(int u, int v, int w) {
	e[eid].v = v;
	e[eid].w = w;
	e[eid].next = p[u];
	e[eid].f = 1;
	p[u] = eid++;
}

void insert2(int u, int v, int w) {
	insert1(u, v, w);
	insert1(v, u, w);
}

void changef1(int u, int v, int t) {
	int i = p[u];
	while (e[i].v != v)
		i = e[i].next;
	e[i].f = t;
}

void changef2(int u, int v, int t) {
	changef1(u, v, t);
	changef1(v, u, t);
}

void resetw() {
	d[A] = 0;
	for (int i = 0; i < n; i++) {
		int mind = infi;
		int u = 0;
		for (int j = 1; j <= n; j++) {
			if (vis[j] == 0 && d[j] < mind) {
				mind = d[j];
				u = j;
			}
		}
		if (mind == infi)
			break;
		vis[u] = 1;
		for (int j = p[u]; j != -1; j = e[j].next) {
			int v = e[j].v;
			if (e[j].f && d[v] > d[u] + e[j].w && vis[v] == 0) {
				d[v] = d[u] + e[j].w;
			}
		}
	}
}

void resetw1() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		d[i] = infi * 1.0;
	resetw();
}

int h(int num) {
	int wmin = infi;
	for (int i = num; i < r; i++)
		wmin = wmin < destroy[i].w ? wmin : destroy[i].w;
	return wmin;
}

void DFS(int num, int len) {
	if (d[B] < infi) {
		minlen = minlen > len ? len : minlen;
		return;
	}
	if (num >= r || len >= minlen)
		return;
	DFS(num + 1, len);
	int x = destroy[num].u;
	int y = destroy[num].v;
	int w;
	changef2(x, y, 1);
	resetw1();
	for (int j = p[x]; j != -1; j = e[j].next)
		if (e[j].v == y)
			w = e[j].w;
	if (h(num) + len < minlen)
		DFS(num + 1, len + w );
	changef2(x, y, 0);
	resetw1();
}

int main() {
	int i, j, k;
	int q, s;
	memset(p, -1, sizeof(p));
	minlen = infi;
	scanf("%d", &n);
	scanf("%d", &m);
	for (q = 0; q < m; q++) {
		scanf("%d %d %d", &i, &j, &k);
		insert2(i, j, k);
	}
	scanf("%d", &r);
	for (q = 0; q < r; q++) {
		scanf("%d %d", &i, &j);
		destroy[q].u = i;
		destroy[q].v = j;
		for (s = p[i]; s != -1; s = e[s].next) {
			if (e[s].v == j)
				destroy[q].w = e[s].w;
		}
		changef2(i, j, 0);
	}
	scanf("%d %d", &A, &B);
	resetw1();
	DFS(0, 0);
	printf("%d", minlen)
	;
	return 0;
}
