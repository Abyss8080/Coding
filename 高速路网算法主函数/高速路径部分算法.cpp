#include <string.h>
#define MAXN 3000
#define infi 0x3f3f3f3f

typedef struct {
	int x, y;
} dot;

typedef struct {
	int v, w;
	int next;
	int f;
} edge;

struct State {
	dot point[MAXN];
	edge e[MAXN * MAXN];
	int n, alle;
};
int eid, p[MAXN], visit[MAXN], d[MAXN], pre[MAXN];
int idx;

void changef1(struct State *s, int u, int v, int t) {
	int i = p[u];
	while (s->e[i].v != v)
		i = s->e[i].next;
	s->e[i].f = t;
}

void changef2(struct State *s, int u, int v, int t) {
	changef1(s, u, v, t);
	changef1(s, v, u, t);
}

void Dijkstra(struct State *s) {
	d[1] = 0;//这里非0，为起点的发达程度
	for (int i = 0; i < s->n; i++) {
		int mind = infi;
		int u = 0;
		for (int j = 1; j <= s->n; j++) {
			if (visit[j] == 0 && d[j] < mind) {
				mind = d[j];
				u = j;
			}
		}
		if (mind == infi)
			break;
		visit[u] = 1;
		for (int j = p[u]; j != -1; j = s->e[j].next) {
			int v = s->e[j].v;
			if (s->e[j].f && d[v] > d[u] + s->e[j].w && visit[v] == 0) {
				d[v] = d[u] + s->e[j].w;
				pre[v] = u;
			}
		}
	}
}

void Dijkstra1(struct State *s) {
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= s->n; i++)
		d[i] = infi;
	Dijkstra(s);
}

int solve1(struct State *s) {
	Dijkstra1(s);
	return d[idx];
}

int solve2(struct State *s) {
	int x = idx;
	int p = infi;
	while (pre[x] != -1) {
		changef2(s, x, pre[x], 0);
		Dijkstra1(s);
		int p2 = d[idx];
		changef2(s, x, pre[x], 1);
		if (p2 < p)
			p = p2;
		x = pre[x];
	}
	if (p == infi)
		return -1;
	return p;
}