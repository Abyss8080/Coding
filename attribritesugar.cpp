#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAX 100001

typedef struct nnode {
	int num;
	struct nnode *next;
} Kid;

typedef struct node {
	Kid *first;
} KHead;

int has[MAX] = {0};

int time[MAX] = {0};
int n, m;
KHead *co[MAX];

int BFS(int x) {
	int queue[MAX];
	int l, r, tmax;
	l = r = 0;
	memset(has, 0, sizeof(has));
	memset(time, 0, sizeof(time));
	queue[r++] = x;
	time[x] = 1;
	has[x] = 1;
	tmax = 0;
	while (l < r) {
		int now = queue[l++];
		if (tmax < time[now])
			tmax = time[now];
		Kid *p = co[now]->first;
		while (p != NULL) {
			int cl = p->num;
			if (has[cl] == 0) {
				queue[r++] = cl;
				time[cl] = time[now] + 1;
				has[cl] = 1;
			}
			p = p->next;
		}
	}
	return tmax + m;
}

int main() {
	int p, c, i;
	int kid1, kid2;
	scanf("%d %d %d", &n, &p, &c);
	scanf("%d", &m);
	co[0] = NULL;
	for (i = 1; i <= n; i++) {
		co[i] = (KHead *)malloc(sizeof(KHead));
		co[i]->first = NULL;
	}
	for (i = 0; i < p; i++) {
		scanf("%d %d", &kid1, &kid2);
		Kid *pt = NULL;
		pt = (Kid *)malloc(sizeof(Kid));
		pt->num = kid2;
		pt->next = co[kid1]->first;
		co[kid1]->first = pt;
		pt = (Kid *)malloc(sizeof(Kid));
		pt->num = kid1;
		pt->next = co[kid2]->first;
		co[kid2]->first = pt;
	}
	printf("%d", BFS(c));
	Kid *pnow = NULL, *pnext = NULL;
	for (i = 1; i <= n; i++) {
		pnow = co[i]->first;
		while (pnow != NULL) {
			pnext = pnow->next;
			free(pnow);
			pnow = pnext;
		}
		free(co[i]);
	}
	return 0;
}