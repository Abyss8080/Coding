#include <stdio.h>
#include <stdlib.h>


typedef struct node {
	char *data;
	struct node *next;
} Node;

int main() {
	Node *phead;
	//����ͷ
	Node *pnew;
	Node *ptail;
	//����β
	Node *poff;
	//�ͷ�malloc�ռ�ʱ�����ı���
	Node *pre1;

	Node *pre2;
	//����ʱ�����ı���
	Node *pheadout;

	Node *ptailout;
	//���ʱ�����ı���
	int i = 0;
	printf("Input 10 words:\n");
	pnew = (Node *)malloc(sizeof(Node));
	pnew->data = (char *)malloc(20 * sizeof(char));
	gets(pnew->data);
	pnew->next = NULL;
	phead = pnew;
	ptail = pnew;
	//�����һ���ڵ�������
	for (i = 0; i < 9; i++) {
		pnew = (Node *)malloc(sizeof(Node *));
		pnew->data = (char *)malloc(21 * sizeof(char));
		gets(pnew->data);
		pnew->next = NULL;
		ptail->next = pnew;
		ptail = pnew;
	}
	//����ʣ�µĽڵ�������



	printf("\nThe oringinal data is:\n");
	pheadout = phead;
	while (pheadout != NULL) {
		puts(pheadout->data);
		pheadout = pheadout->next;
	}
	printf("\n");
	//���ԭ������


	pre1 = phead->next;
	pre2 = pre1->next;
	phead->next = NULL;
	//�������һ���ڵ��nextָ���
	pre1->next = phead;
	//������ĵڶ����ڵ�ָ���һ���ڵ�
	while (pre2 != NULL) {
		phead = pre1;
		pre1 = pre2;
		pre2 = pre1->next;
		pre1->next = phead;
	}
	//��ʣ��û�иı�Ľڵ�����
	ptailout = ptail;
	printf("\nThe reversal data is:\n");
	while (ptailout != NULL) {
		puts(ptailout->data);
		ptailout = ptailout->next;
	}
	printf("\n");
	//�����������



	while (ptail != NULL) {

		poff = ptail->next;
		free(ptail->data);
		free(ptail);
		ptail = poff;
	}
	//�ͷ�����malloc������ռ�
	system("PAUSE");
	return 0;

}