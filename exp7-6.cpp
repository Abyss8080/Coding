#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;

typedef struct node {
	ElemType data;			//����Ԫ��
	struct node *lchild;	//ָ�����ӽ��
	struct node *rchild;	//ָ���Һ��ӽ��
} BTNode;
int Nodes(BTNode *b);
int LeafNodes(BTNode *b);
int FindNodeLevel(BTNode *b, ElemType x, int height);
int TreeWidth(BTNode *b);

void CreateBTree(BTNode *&b, char *str) {	//����������
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//�����Ķ�������ʼʱΪ��
	ch = str[j];
	while (ch != '\0') {	//strδɨ����ʱѭ��
		switch (ch) {
			case '(':
				top++;
				St[top] = p;
				k = 1;
				break;		//Ϊ���ӽ��
			case ')':
				top--;
				break;
			case ',':
				k = 2;
				break;                      		//Ϊ���ӽ���ҽ��
			default:
				p = (BTNode *)malloc(sizeof(BTNode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if (b == NULL)                    	 	//*pΪ�������ĸ����
					b = p;
				else {								//�ѽ��������������
					switch (k) {
						case 1:
							St[top]->lchild = p;
							break;
						case 2:
							St[top]->rchild = p;
							break;
					}
				}
		}
		j++;
		ch = str[j];
	}
}
void DestroyBTree(BTNode *&b) {	//���ٶ�����
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
void DispBTree(BTNode *b) { //�����ű�ʾ�����������
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");						//�к��ӽ��ʱ�����(
			DispBTree(b->lchild);				//�ݹ鴦��������
			if (b->rchild != NULL)
				printf(",");	//���Һ��ӽ��ʱ�����,
			DispBTree(b->rchild);				//�ݹ鴦��������
			printf(")");						//�к��ӽ��ʱ�����)
		}
	}
}

int main() {
	ElemType str[MaxSize] = "A(B(D, E(H(J, K(L, M(, N))))), C(F, G(, I)))";
	ElemType x;
	BTNode *b;
	int i = 0;
	CreateBTree(b, str);
	printf("������bΪ��");
	DispBTree(b);
	printf("\n������b�Ľ�����Ϊ��%d��\n", Nodes(b));
	printf("������b��Ҷ�ӽ�����Ϊ��%d��\n", LeafNodes(b));
	printf("�����������˽������ڲ�εĽ��ֵ��");
	scanf("%c", &x);
	i = FindNodeLevel(b, x, 1);
	if (i == 0)
		printf("������b��û�н��ֵΪ%c�Ľ�㡣", x);
	else
		printf("������b���ֵΪ%c�Ľ����Ϊ��%d��\n", x, FindNodeLevel(b, x, 1) );
	printf("������b�Ŀ��Ϊ��%d��\n", TreeWidth(b));

	DestroyBTree(b);
	return 1;
}

int Nodes(BTNode *b) {
	int Hlchild, Hrchild;
	if (b == NULL)
		return 0;
	else if (b->lchild == NULL && b->rchild == NULL)
		return 1;
	else {
		Hlchild = Nodes(b->lchild);
		Hrchild = Nodes(b->rchild);
		return Hlchild + Hrchild + 1;
	}
}

int LeafNodes(BTNode *b) {
	int lleaf, rleaf;
	if (b == NULL)
		return 0;
	else if (b->lchild == NULL && b->rchild == NULL)
		return 1;
	else {
		lleaf = LeafNodes(b->lchild);
		rleaf = LeafNodes(b->rchild);
		return lleaf + rleaf;
	}
}

int FindNodeLevel(BTNode *b, ElemType x, int h) {
	int height;
	if (b == NULL)
		return 0;
	else if (b->data == x)
		return h;
	else {
		height = FindNodeLevel(b->lchild, x, h + 1);
		if (height == 0)//ֻ������һ�εݹ�û�н��ʱhΪ0�����������Ĵ�����ܴӵ�һ�㿪ʼ
			height =  FindNodeLevel(b->rchild, x, h + 1);
		return height;
	}
}

int TreeWidth(BTNode *b) {
	BTNode *temp[MaxSize / 2] = { NULL };
	BTNode *pre[MaxSize / 2] = { NULL };
	int i = 0, j = 0;
	int widmax = 1;
	int widpre = 1;
	int wid = 0;
	pre[0] = b;
	while (widpre != 0) {
		for (j = 0; j < widpre; j++) {
			if (pre[j]->lchild != NULL) {
				temp[wid] = pre[j]->lchild;
				wid++;
			}
			if (pre[j]->rchild != NULL) {
				temp[wid] = pre[j]->rchild;
				wid++;
			}
		}
		if (wid > widmax)
			widmax = wid;
		widpre = wid;
		for (j = 0; j < wid; j++)
			pre[j] = temp[j];
		wid = 0;
	}
	return widmax;
}