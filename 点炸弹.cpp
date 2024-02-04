#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAX 500

typedef struct node {
	struct node *rightnext;
	struct node *downnext;
	int boom;
} Point;
int num = 0, n, m;

void Boom(Point *p) {
	Point *t = p;
	p->boom = 1;
	while (t->rightnext->boom == 0) {
		t = t->rightnext;
		Boom(t);
	}
	t = p;
	while (t->downnext->boom == 0) {
		t = t->downnext;
		Boom(t);
	}
}

int main() {
	Point *lefthead[MAX], *uphead[MAX];
	Point *lefttail[MAX], *uptail[MAX];
	Point *p = NULL, *pnext = NULL, *ps = NULL;
	scanf("%d %d", &n, &m);
	int i = 0, j;
	char c[MAX];

	while (i < MAX) {
		lefthead[i] = NULL;
		lefttail[i] = NULL;
		i++;
	}
	i = 0;
	while (i < MAX) {
		uphead[i] = NULL;
		uptail[i] = NULL;
		i++;
	}
	for (i = 0; i < n; i++) {
		scanf("%s", c);
		for (j = 0; j < m; j++) {
			if (c[j] == '1') {
				Point *p = (Point *)malloc(sizeof(Point));
				p->rightnext = NULL;
				p->downnext = NULL;
				p->boom = 0;

				if (lefthead[i] == NULL) {
					lefthead[i] = p;
					p->rightnext = p;
				} else {
					lefttail[i]->rightnext = p;
					p->rightnext = lefthead[i];
				}
				lefttail[i] = p;
				if (uphead[j] == NULL) {
					uphead[j] = p;
					p->downnext = p;
				} else {
					uptail[j]->downnext = p;
					p->downnext = uphead[j];
				}
				uptail[j] = p;
			}
		}
	}
	for (i = 0; i < n; i++) {
		if (lefthead[i] != NULL && lefthead[i]->boom == 0) {
			num++;
			Boom(lefthead[i]);
		}
	}
	printf("%d", num);

	for (i = 0; i < n; i++) {
		ps = lefthead[i];
		if (ps == NULL)
			continue;
		p = ps->rightnext;
		while (p != ps) {//指针释放之后 不是null，他变成了一个野指针，不安全
			pnext = p->rightnext;
			free(p);
			p = pnext;
		}
	}
	return 0;
}