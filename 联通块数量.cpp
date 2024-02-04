#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <malloc.h>
#define MAX 20001

//这个代码虚拟机能跑，dev不行
typedef struct Anode {
	int adjvex;
	struct Anode *nextarc;
} ArcNode;

typedef struct Vnode {
	ArcNode *firstarc;
} VNode;

typedef struct {
	VNode adjlist[MAX];
	int n, e;
} AdjGraph;
int n, m;

int visit[MAX] = {0}, visitnum = 0;

void DFS(AdjGraph *G, int v) {
	ArcNode *p = NULL;
	visit[v] = 1;
	p = G->adjlist[v].firstarc;
	while (p != NULL) {
		if (visit[p->adjvex] == 0)
			DFS(G, p->adjvex);
		p = p->nextarc;
	}
}

void DFS1(AdjGraph *G) {
	for (int i = 1; i <= G->n; i++) {
		if (visit[i] == 0) {
			visitnum++;
			DFS(G, i);
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	int i;
	int a, b;
	AdjGraph *G = (AdjGraph *)malloc(sizeof(AdjGraph));
	ArcNode *p = NULL;
	ArcNode *pnext = NULL, *p1 = NULL;
	G->n = n;
	G->e = m;
	for (i = 0; i < n; i++)
		G->adjlist[i].firstarc = NULL;
	for (i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		if (a == b)
			continue;
		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = b;
		p->nextarc = G->adjlist[a].firstarc;
		G->adjlist[a].firstarc = p;

		p = (ArcNode *)malloc(sizeof(ArcNode));
		p->adjvex = a;
		p->nextarc = G->adjlist[b].firstarc;
		G->adjlist[b].firstarc = p;
	}
	DFS1(G);
	printf("%d", visitnum);

	for (i = 0; i < G->n; i++) {
		p1 = G->adjlist[i].firstarc;
		while (p != NULL) {
			pnext = p->nextarc;
			free(p);
			p = pnext;
		}
	}
	free(G);
	return 0;
}