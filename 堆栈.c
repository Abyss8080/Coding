#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void push(int i);
//入栈函数
int pop(void);
//出栈函数
int *tos, *p1, stack[SIZE];

//栈底指针、栈顶指针、堆栈
int main() {
	int value;
	tos = stack;
	p1 = stack;

	do {
		printf("输入一个整数：\n");
		scanf("%d", &value);
		if (value != 0)
			push(value);
		else
			printf("出栈数据是%d\n", pop());
	} while (value != 0);
	system("PAUSE");
	return 0;
}

void push(int i) {
	p1++;
	if (p1 == (tos + SIZE)) {
		//判断堆栈是否已满
		printf("堆栈已满\n");
		system("PAUSE");
		exit(1);
	}
	*p1 = i;
}

int pop(void) {
	if (p1 == tos) {
		//判断堆栈是否为空
		printf("堆栈空\n");
		system("PAUSE");
		exit(1);
	}
//	p1--;
//	return *(p1 + 1);
	return *p1;
}