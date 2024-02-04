#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	double data;
	struct node *next;
} Node;

Node  *create(void);
//创建一个链表，输入-1结束
Node  *search(Node *p, double n);
//搜索目的值，并返回节点指针
int main() {
	Node *p;
	Node *px;
	Node *pn;
	double n = 1.2;

	printf("\nInput numbers:\n");
	p = create();
	pn = search(p, n);
	if (pn == NULL) {
		printf("\nNULL\n");
	} else {
		printf("\n%.3f\n", pn->data);
		printf("%p\n", &pn);
	}

	while (p != NULL) {
		px = p->next;
		free(p);
		p = px;
	}
	system("PAUSE");
	return 0;
}



Node  *create(void) {
	Node *phead;
	Node *pnew;
	Node *ptail;
	double n;


	scanf("%lf", &n);
	pnew = (Node *)malloc(sizeof(Node));
	pnew->data = n;
	pnew->next = NULL;
	phead = pnew;
	ptail = pnew;

	do {
		scanf("%lf", &n);
		if (n != -1) {
			pnew = (Node *)malloc(sizeof(Node));
			pnew->data = n;
			pnew->next = NULL;
			ptail->next = pnew;
			ptail = pnew;
		}
	} while (n != -1);

	return phead;
}


Node  *search(Node *p, double n) {
	Node *pgoal = NULL;
	if (p->data == n)
		pgoal = p;
	else if (p->next != NULL)
		pgoal = search(p->next, n);

	return pgoal;
}