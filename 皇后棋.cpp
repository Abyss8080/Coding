#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#pragma warning(disable:4996)
#define MaxSize 20

typedef struct {
	int n;
	int yet;
} number;

typedef struct {
	number col;
	number row;
	int step;
} BOX;

typedef struct {
	BOX box[MaxSize];
	int top;
} Goal;

int j = 0;

void queen(Goal *&goal, int n);
void disp(Goal *goal);//输出当前站内的全部内容
void push(BOX x, Goal *&goal);
void pop(BOX x, Goal *&goal);

int main() {
	int r;
	Goal *goal;
	bool isdata = false;
	goal = (Goal *)malloc(sizeof(Goal));
	goal->top = -1;
	for (r = 0; r < MaxSize; r++) {
		goal->box[r] = { {0, 0}, {0, 0}, 0, };
	}
	do {
		printf("请输入您想寻找的皇后个数：");
		scanf("%d", &r);
		if (r <= 0 || r > 20)
			printf("您输入的数据有误。\n");
		else
			isdata = true;

	} while (!isdata);
	queen(goal, r);

	system("PAUSE");
	return 1;
}


void queen(Goal *&goal, int n) {
	BOX x = { {0, 0}, {0, 0} }, y = { {0, 0}, {0, 0} };
	int k = goal->top;
	bool find = false;
	bool ok = true;
	push(x, goal);
	while (goal->top < n) {
		x = goal->box[goal->top];
		x.row.n++;
		if (j == 0)
			x.col.n--;
		else
			x.col.n = -1;
		while (!find) {
			x.col.n++;
			while (k > -1) {
				//对角线上有皇后棋
				if (x.col.n - x.row.n == goal->box[k].col.n - goal->box[k].row.n
				        || x.row.n + x.col.n == goal->box[k].col.n + goal->box[k].row.n) {
					ok = false;
					break;
				}
				k--;
			}
			if (!ok)
				break;
			else {
				if (x.col.yet == 0 && x.col.n < n) {
					find = true;
					push(x, goal);
					break;
				}
			}
		}
		if (!find)
			pop(y, goal);
	}
	disp(goal);

}

void disp(Goal *goal) {
	int i = goal->top;
	printf("\n第%d组解：\n", j);
	j++;
	while (i != -1) {
		goal->box[i].step++;
		printf("(%d,%d) ", goal->box[i].row .n + 1, goal->box[i].col.n + 1);
		i--;
	}
}

void push(BOX x, Goal *&goal) {
	goal->top++;
	x.col.yet = -1;
	x.row.yet = -1;
	goal->box[goal->top] = x;
}

void pop(BOX x, Goal *&goal) {
	x.col.yet = 0;
	x.row.yet = 0;
	x = goal->box[goal->top];
	goal->top--;
}
