#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
//#include "sqstack.cpp"
#pragma warning(disable:4996)
#define MaxSize 100
typedef char ElemType;

typedef struct {
	ElemType data[MaxSize];
	int top;				//ջָ��
} SqStack;					//����˳��ջ����

void StackSort(SqStack *&stack);
void ReStack(SqStack *&stack);

int main() {
	SqStack *stack;

	InitStack(stack);
	StackSort(stack);
	DestroyStack(stack);

	return 1;
}

void StackSort(SqStack *&stack) {
	char n;
	printf("��������Ҫ������ַ�����""\n������-1�������룩\n");
	while (true) {
		scanf("%c", &n);
		if (n == '-1')
			break;
		Push(stack, n);
	}
	ReStack(stack);
}

void ReStack(SqStack *&stack) {
	int i = 0, j = 0;
	char e;
	char s1, s2;
	SqStack *stackemp;
	InitStack(stackemp);
	Pop(stack, e);
	Push(stackemp, e);
	printf("\nstack��ջ��%c", e);
	printf("\nstackemp��ջ��%c", e);
	while (!StackEmpty(stack)) {
		GetTop(stack, s1);
		GetTop(stackemp, s2);
		if (s1 >= s2) {
			Pop(stack, e);
			Push(stackemp, e);
			printf("\n�� %c >= %c", s1, s2);
			printf("\nstack��ջ��%c", e);
			printf("\nstackemp��ջ��%c", e);
		} else {
			printf("\n�� %c > %c", s2, s1);
			Pop(stack, s1);
			printf("\nstack��ջ��%c", e);
			do {
				Pop(stackemp, s2);
				Push(stack, s2);
				printf("\nstackemp��ջ��%c", s2);
				printf("\nstack��ջ��%c", s2);
				GetTop(stackemp, s2);
				i++;
			} while (s1 < s2);
			Push(stackemp, s1);
			for (j = 0; j < i; j++) {
				Pop(stack, e);
				Push(stackemp, e);
				printf("\nstack��ջ��%c", e);
				printf("\nstackemp��ջ��%c", e);
			}
		}
	}
	while (stackemp->top != -1) {
		Pop(stackemp, s2);
		Push(stack, s2);
		printf("\nstackemp��ջ��%c", s2);
		printf("\nstack��ջ��%c", s2);
	}
}
