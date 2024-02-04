#include <stdio.h>
#include <malloc.h>
#define MaxSize 100
typedef char ElemType;

typedef struct node {
	ElemType data;			//数据元素
	struct node *lchild;	//指向左孩子结点
	struct node *rchild;	//指向右孩子结点
} BTNode;
int Nodes(BTNode *b);
int LeafNodes(BTNode *b);
int FindNodeLevel(BTNode *b, ElemType x, int height);
int TreeWidth(BTNode *b);

void CreateBTree(BTNode *&b, char *str) {	//创建二叉树
	BTNode *St[MaxSize], *p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//建立的二叉树初始时为空
	ch = str[j];
	while (ch != '\0') {	//str未扫描完时循环
		switch (ch) {
			case '(':
				top++;
				St[top] = p;
				k = 1;
				break;		//为左孩子结点
			case ')':
				top--;
				break;
			case ',':
				k = 2;
				break;                      		//为孩子结点右结点
			default:
				p = (BTNode *)malloc(sizeof(BTNode));
				p->data = ch;
				p->lchild = p->rchild = NULL;
				if (b == NULL)                    	 	//*p为二叉树的根结点
					b = p;
				else {								//已建立二叉树根结点
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
void DestroyBTree(BTNode *&b) {	//销毁二叉树
	if (b != NULL) {
		DestroyBTree(b->lchild);
		DestroyBTree(b->rchild);
		free(b);
	}
}
void DispBTree(BTNode *b) { //以括号表示法输出二叉树
	if (b != NULL) {
		printf("%c", b->data);
		if (b->lchild != NULL || b->rchild != NULL) {
			printf("(");						//有孩子结点时才输出(
			DispBTree(b->lchild);				//递归处理左子树
			if (b->rchild != NULL)
				printf(",");	//有右孩子结点时才输出,
			DispBTree(b->rchild);				//递归处理右子树
			printf(")");						//有孩子结点时才输出)
		}
	}
}

int main() {
	ElemType str[MaxSize] = "A(B(D, E(H(J, K(L, M(, N))))), C(F, G(, I)))";
	ElemType x;
	BTNode *b;
	int i = 0;
	CreateBTree(b, str);
	printf("二叉树b为：");
	DispBTree(b);
	printf("\n二叉树b的结点个数为：%d。\n", Nodes(b));
	printf("二叉树b的叶子结点个数为：%d。\n", LeafNodes(b));
	printf("请输入您想了解结点所在层次的结点值：");
	scanf("%c", &x);
	i = FindNodeLevel(b, x, 1);
	if (i == 0)
		printf("二叉树b中没有结点值为%c的结点。", x);
	else
		printf("二叉树b结点值为%c的结点层次为：%d。\n", x, FindNodeLevel(b, x, 1) );
	printf("二叉树b的宽度为：%d。\n", TreeWidth(b));

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
		if (height == 0)//只有在上一次递归没有结果时h为0，对右子树的处理才能从第一层开始
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