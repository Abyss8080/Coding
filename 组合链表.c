#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

void freedom(Node *p);
void create(Node *p);
Node *concatenate(Node *p1, Node *p2);
void print(Node *p);
int main() {
	Node *linklist1;
	Node *linklist2;
	Node *linklistal;
	linklist1 = (Node *)malloc(sizeof(Node ));
	linklist1->next = NULL;
	linklist2 = (Node *)malloc(sizeof(Node ));
	linklist2->next = NULL;
	linklistal = (Node *)malloc(sizeof(Node ));


	printf("Input numbers for linklist1 until ending -1:\n");
	create(linklist1);
	printf("Input numbers for linklist2 until ending -1:\n");
	create(linklist2);
	linklistal = concatenate(linklist1, linklist2);
	printf("\n\nlinklist1:\n");
	print(linklist1);
	printf("\n\nlinklist2:\n");
	print(linklist2);
	printf("\n\nlinklistal:\n");
	print(linklistal);


	freedom(linklist1);
	freedom(linklist2);
	freedom(linklistal);
	system("PAUSE");
	return 0;
}

void create(Node *p)
//创建一个链表直至输入-1
{
	Node *pnew;
	int n;

	scanf("%d", &n);
	if (n != -1)
		p->data = n;
	do {
		scanf("%d", &n);
		if (n != -1) {
			pnew = (Node *)malloc(sizeof(Node ));
			pnew->data = n;
			pnew->next = NULL;
			p->next = pnew;
			p = pnew;
		}
	} while (n != -1);

}


Node *concatenate(Node *p1, Node *p2)
//将链表p2串联在p1的后面
{
	Node *pal;
	Node *pnew;
	Node *ptail;
	pnew = (Node *)malloc(sizeof(Node ));
	pnew->data = p1->data;
	pnew->next = NULL;
	pal = pnew;
	ptail = pnew;
	p1 = p1->next;
	while ( p1 != NULL) {
		pnew = (Node *)malloc(sizeof(Node ));
		pnew->data = p1->data;
		pnew->next = NULL;
		ptail->next = pnew;
		ptail = pnew;
		p1 = p1->next;
	}
	while ( p2 != NULL) {
		pnew = (Node *)malloc(sizeof(Node ));
		pnew->data = p2->data;
		pnew->next = NULL;
		ptail->next = pnew;
		ptail = pnew;
		p2 = p2->next;
	}
	return pal;
}

void print(Node *p)
//输出链表
{
	do {
		printf("%d，", p->data);
		p = p->next;
	} while (p != NULL);
}


void freedom(Node *p)
//释放malloc的所有空间
{
	Node *pa;
	while (p != NULL) {
		pa = p->next;
		free(p);
		p = pa;
	}
}

