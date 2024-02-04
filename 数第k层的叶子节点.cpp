#define MaxSize 100

//默认k<=100
typedef struct link {
	char data;
	struct link *lchild;
	struct link *rchild;
} Link;

typedef struct stack {
	Link *point[MaxSize];
	int top;
} Stackpath;

int CountLeaf(Link *head, int k) { //top+1==k到第k层
	int i = 0;
	Link *p = head；
	          Link * pnext = NULL;
	Stackpath stack;
	p入栈；
	while （栈不空） {
	pnext = stack.point[stack.top];
		if (pnext->lchild == NULL && pnext->rchild == NULL) {
			if (stack.top + 1 == k) {
				i++;
			} else {
				pnext退栈；
			}
		} else {

		}


	}
