#include <stdio.h>
#include <stdlib.h>

struct node {
	int data;
	struct node *next;
};

int main() {
	struct node *head, *pnew, *ptail, *p;
	int i;

	pnew = (struct node *)malloc(sizeof(struct node));
	pnew->data = 0;
	pnew->next = NULL;

	head = pnew;
	p = pnew;

	scanf("%d", &i);
	do {
		p->data = i;

		pnew = (struct node *)malloc(sizeof(struct node));
		pnew->data = 0;
		pnew->next = NULL;

		p->next = pnew;
		p = pnew;

		scanf("%d", &i);
	} while (i != -1);


	p = head;
	do {
		printf("%d\t", p->data);
		p = p->next;
	} while (p->next != NULL);

	p = head;
	do {
		ptail = p->next;
		free(p);
		p = ptail;
	} while (p != NULL);

	system("PAUSE");
	return 0;
}




//int main(){
//	struct node a,b,c,*head,*p;
//	a.data=1;
//	b.data=2;
//	c.data=3;
//	head=&a;
//	a.next=&b;
//	b.next=&c;
//	c.next=NULL;
//	p=head;
//
//	do{
//		printf("%d\t",p->data);
//		p=p->next;
//	}while(p!=NULL);
//
//
//	system("PAUSE");
//	return 0;
//
//}