#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

Node *createrightlink_1(void);
int creatrightlink_2(Node **phead);
Node *creatleftlink_1(void);
int creatleftlink_2(Node **phead);
Node *insertsort(Node *head, int n);
Node* creatsortlink(Node*head);
Node*deletelink_1(Node*head,int n);
int deletelink_2(Node**phead,int n);
//一级指针传入结构指针的数据，但不能做修改

int main() {
	Node *head, *p, *ptail;
	int n;
	//节点个数
	int k;
	//数据
	int is;
	//is为1，删除成功；为0，数据不在链表内
	scanf("%d", &k);
	
//	head = createrightlink_1();
//	n = creatrightlink_2(&head);
//	head = creatleftlink_1();
//	n = creatleftlink_2(&head);
//head=insertsort(head,k);
//head=creatsortlink(head);
//is=deletelink_2(&head,k);
head=deletelink_1(head,k);
	printf("%d\n", n);
	p = head;
	do {
		printf("%d\t", p->data);
		p = p->next;
	} while (p != NULL);

	p = head;
	do {
		ptail = p->next;
		free(p);
		p = ptail;
	} while (p != NULL);

	system("PAUSE");
	return 0;
}


Node *createrightlink_1()
//创建一个链表直至输入-1
{
	Node *pnew, *ptail, *head;
	int n;
	pnew = (Node *)malloc(sizeof(Node ));
	pnew->data = 0;
	pnew->next = NULL;
	ptail = pnew;
	head = pnew;

	scanf("%d", &n);
	do {
		ptail->data = n;
		pnew = (Node *)malloc(sizeof(Node ));
		pnew->data = 0;
		pnew->next = NULL;
		ptail->next = pnew;
		ptail = pnew;
		scanf("%d", &n);
	} while (n != -1);
	return head;
}


int creatrightlink_2(Node **phead) {
	Node *new, *tail;
	int n, k = 0;

	*phead = NULL;
	scanf("%d", &n);
	while (n != -1) {
		new = (Node *)malloc(sizeof(Node ));
		new->data = n;
		new->next = NULL;

		if (*phead = NULL) {
			*phead = new;
		} else {
			tail->next = new;
		}

		tail = new;
		scanf("%d", &n);
		k++;
	}
	return k;
}


Node *creatleftlink_1() {
	Node *new, *phead;
	int n;
	phead = NULL;
	scanf("%d", &n);
	while (n != -1) {
		new = (Node *)malloc(sizeof(Node ));
		new->data = n;

		new->next = phead;
		phead = new;
		scanf("%d", &n);

	}
	return phead;
}


int creatleftlink_2(Node **phead) {
	Node  *new;
	int n, k = 0;
	*phead = NULL;
	scanf("%d", &n);
	while (n != -1) {
		new = (Node *)malloc(sizeof(Node ));
		new->data = n;
		new->next = *phead;

		*phead = new;
		scanf("%d", &n);
		k++;
	}
	return  k;
}


Node *insertsort(Node *head, int n) {
	Node *new, *p, *marker;
	new = (Node *)malloc(sizeof(Node ));
	new->data = n;
	p = head;
	while (p != NULL && p->data < n) {
		marker = p;
		p = p->next;
	}

	if (p == head) {
		new->next = head;
		head = new;
	} else {
		marker->next = new;
		new->next = marker;

	}

	return head;
}


Node* creatsortlink(Node*head){
	int n;
	head=NULL;
	
	scanf("%d",&n);
	while(n!=-1){
		head=insertsort(head,n);
		scanf("%d",&n);
	}
	return head;
}



Node*deletelink_1(Node*head,int n){
	Node*current,*p;
	current=head;
	while(current->data!=n&&current->next!=NULL){
		p=current;
		current=current->next;
	}
	if(current->data==n){
		if(current==head)
		head=current->next;
		else p->next=current->next;
		
		free(current);
	}
}

int deletelink_2(Node**phead,int n){
	Node*current,*p;
	current=*phead;
	while(current->data!=n&&current->next!=NULL){
		p=current;
		current=current->next;
	}
	if(current->data==n){
		
		if(current==*phead)
		*phead=current->next;
		else
		 p->next=current->next;
		
		free(current);
		return 1;
	}else{
		return 0;
	}
}
