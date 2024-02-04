#include <stdio.h>
#include <string.h>
#include <math.h>
#define Min(a,b) ((a)>(b)?(b):(a))
#define MAXN 201
#define infi 0x3f3f3f3f

typedef struct {
	int x, y;
} VNode;

typedef struct {
	int v;
	double w;
	int next;
	int f;
} Edge;
Edge e[MAXN * MAXN / 2];
int n, m, eid, p[MAXN], vis[MAXN];
int premin[MAXN], presemin[MAXN];
VNode point[MAXN];
double d[MAXN];

void insert1(int u, int v, double w) {
	Edge t;
	t.v = v;
	t.w = w;
	t.next = p[u];
	t.f = 1;
	e[eid] = t;
	p[u] = eid++;
}

void insert2(int u, int v, double w) {
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


double value(int x1, int x2) {
	VNode p1 = point[x1], p2 = point[x2];
	return sqrt(pow((double)(p1.x - p2.x), 2) + pow((double)(p1.y - p2.y), 2));
}

void resetw() { //s->snext的f设为0后，变换路径起点，重新给d赋值
	d[1] = 0;
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
				presemin[v] = u;
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//		printf("%d\n", presemin[i]);
}

double resetw1() {
	memset(vis, 0, sizeof(vis));
	for (int i = 1; i <= n; i++)
		d[i] = infi * 1.0;
	resetw();
	return d[n];
}

int main() {
	int x, y, i;
	double min[2] = {infi, infi};
	memset(presemin, -1, sizeof(presemin));
	memset(p, -1, sizeof(p));
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		scanf("%d %d", &x, &y);
		point[i].x = x;
		point[i].y = y;
	}
	for (i = 1; i <= m; i++) {
		scanf("%d %d", &x, &y);
		insert2(x, y, value(x, y));
	}
	min[0] = resetw1();
	for (i = 1; i <= n; i++)
		premin[i] = presemin[i];
//	printf("%.2f", min[0]);
	x = n;
	while (premin[x] != -1) {
		changef2(x, premin[x], 0);
		double p = resetw1();
		changef2(x, premin[x], 1);
		if (p < min[1])
			min[1] = p;
		x = premin[x];
	}
	if (min[1] == infi)
		printf("-1");
	else
		printf("%.2f", min[1]);
	return 0;
}