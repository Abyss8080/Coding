#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#define MAX 10000

typedef struct node {
	int val;
	struct node *next;
} Link;

int main() {
	int n, m, x, y;
	Link *head[MAX], *tail[MAX];
	Link *p = NULL;
	int i;
	scanf("%d %d", &n, &m);
	for (i = 0; i < MAX; i++) {
		head[i] = tail[i] = NULL;
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		x = x - 1;
		p = (Link *)malloc(sizeof(Link));
		p->next = NULL;
		p->val = y;
		if (head[x] == NULL)
			head[x] = tail[x] = p;
		else {
			tail[x]->next = p;
			tail[x] = p;
		}
	}
	for (i = 0; i < n; i++) {
		p = head[i];
		if (p != NULL) {
			while (p != NULL) {
				printf("%d ", p->val);
				p = p->next;
			}
		} else
			printf("\n");
		printf("\n");
	}
	return 0;
}