#define MaxSize 100

//Ĭ��k<=100
typedef struct link {
	char data;
	struct link *lchild;
	struct link *rchild;
} Link;

typedef struct stack {
	Link *point[MaxSize];
	int top;
} Stackpath;

int CountLeaf(Link *head, int k) { //top+1==k����k��
	int i = 0;
	Link *p = head��
	          Link * pnext = NULL;
	Stackpath stack;
	p��ջ��
	while ��ջ���գ� {
	pnext = stack.point[stack.top];
		if (pnext->lchild == NULL && pnext->rchild == NULL) {
			if (stack.top + 1 == k) {
				i++;
			} else {
				pnext��ջ��
			}
		} else {

		}


	}
