#include <stdio.h>
#include <stdlib.h>


typedef struct list {
	int data;
	struct list *pnext;
} node;

typedef node *link;

int main() {
	link pnew, p, p1, p2, ptail, phead;
	int k = 0, i = 0;

	printf("��������Ҫ�Ľڵ�����");
	scanf("%d", &k);

	pnew = (link)malloc(sizeof(node));
	pnew->data = 0;
	pnew->pnext = NULL;
	ptail = pnew;
	phead = pnew;
	for (i = 0; i < k - 1; i++) {
		pnew = (link)malloc(sizeof(node));
		pnew->data = 0;
		pnew->pnext = NULL;
		ptail->pnext = pnew;
		ptail = pnew;
	}

	p = phead;
	for (i = 0; i < k; i++) {
		printf("�������%d�����ݣ�", i + 1);
		scanf("%d", &(p->data));
		p = p->pnext;
	}

	if (k == 1) {
		printf("��1�������ǣ�%d\n", phead->data);
		free(phead);
	} else {
		p1 = phead->pnext;
		p2 = p1->pnext;
		phead->pnext = NULL;
		p1->pnext = phead;
		phead = p1;
		for (i = 0; i < k - 2; i++) {
			p1 = p2;
			p2 = p1->pnext;
			p1->pnext = phead;
			phead = p1;
		}

		for (i = 0; i < k; i++) {
			printf("��%d�������ǣ�%d\n", k - i, phead->data);
			phead = phead->pnext;
		}

		while (ptail != NULL) {
			p = ptail->pnext;
			free(ptail);
			ptail = p;
		}

	}

	system("pause");
	return 0;
}
