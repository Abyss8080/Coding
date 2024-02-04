#include <stdio.h>
#include <math.h>
#include <string.h>
#define MAXN 1000
#define infi 1000000000

typedef struct {
	long long x;
	long long y;
	long long z;
	int steps;
} Point;
int n;
long long h, r;
Point ball[MAXN];
int vis[MAXN];

int isgo(Point p1, Point p2) {
	double dist = sqrt( pow((double)(p1.x - p2.x), 2)
	                    + pow((double)(p1.y - p2.y), 2)
	                    + pow((double)(p1.z - p2.z), 2));
	if (dist > 2 * r)
		return 0;
	else
		return 1;
}

int BFS(int x) {
	Point p = ball[x];
	Point queue[MAXN];
	int l, rq, i;
	l = rq = 0;
	memset(vis, 0, sizeof(vis));
	p.steps = 1;
	vis[x] = 1;
	queue[rq++] = p;
	while (l < rq) {
		Point pnow = queue[l++];
		long long t = h - pnow.z;
		if (fabs((double)t) <= r)
			return pnow.steps;
		for (i = 0; i < n; i++) {
			if (vis[i] == 0 && isgo(ball[i], pnow)) {
				vis[i] = 1;
				Point pnext = ball[i];
				pnext.steps = pnow.steps + 1;
				queue[rq++] = pnext;
			}
		}
	}
	return -1;
}

int main() {
	int t, i, j;
	long long x, y, z;
	int min = infi;
	scanf("%d", &t);
	for (i = 0; i < t; i++) {
		min = infi;
		scanf("%d %lld %lld", &n, &h, &r);
		for (j = 0; j < n; j++) {
			scanf("%lld %lld %lld", &x, &y, &z);
			ball[j].x = x;
			ball[j].y = y;
			ball[j].z = z;
			ball[j].steps = 0;
		}
		for (j = 0; j < n; j++) {
			if (fabs((double)ball[j].z) <= r) {
				int num = BFS(j);
				if (num > 0 && num < min)
					min = num;
			}
		}

		if (min == infi)
			printf("-1\n");
		else
			printf("%d\n", min);
	}
	return 0;
}