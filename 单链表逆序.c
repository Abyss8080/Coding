#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	char *data;
	struct node *next;
} Node;

int main() {
	Node *phead;
	//链表头
	Node *pnew;
	Node *ptail;
	//链表尾
	Node *poff;
	//释放malloc空间时借助的变量
	Node *pre1;

	Node *pre2;
	//逆序时借助的变量
	Node *pheadout;

	Node *ptailout;
	//输出时借助的变量
	int i = 0;
	printf("Input 10 words:\n");
	pnew = (Node *)malloc(sizeof(Node));
	pnew->data = (char *)malloc(20 * sizeof(char));
	gets(pnew->data);
	pnew->next = NULL;
	phead = pnew;
	ptail = pnew;
	//输入第一个节点数据域
	for (i = 0; i < 9; i++) {
		pnew = (Node *)malloc(sizeof(Node *));
		pnew->data = (char *)malloc(21 * sizeof(char));
		gets(pnew->data);
		pnew->next = NULL;
		ptail->next = pnew;
		ptail = pnew;
	}
	//输入剩下的节点数据域



	printf("\nThe oringinal data is:\n");
	pheadout = phead;
	while (pheadout != NULL) {
		puts(pheadout->data);
		pheadout = pheadout->next;
	}
	printf("\n");
	//输出原序链表


	pre1 = phead->next;
	pre2 = pre1->next;
	phead->next = NULL;
	//让链表第一个节点的next指向空
	pre1->next = phead;
	//让链表的第二个节点指向第一个节点
	while (pre2 != NULL) {
		phead = pre1;
		pre1 = pre2;
		pre2 = pre1->next;
		pre1->next = phead;
	}
	//让剩余没有改变的节点逆序
	ptailout = ptail;
	printf("\nThe reversal data is:\n");
	while (ptailout != NULL) {
		puts(ptailout->data);
		ptailout = ptailout->next;
	}
	printf("\n");
	//输出逆序链表



	while (ptail != NULL) {

		poff = ptail->next;
		free(ptail->data);
		free(ptail);
		ptail = poff;
	}
	//释放所有malloc的链表空间
	system("PAUSE");
	return 0;

}