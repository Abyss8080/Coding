#include <stdio.h>
#include <stdlib.h>
#define SIZE 50
void push(int i);
//��ջ����
int pop(void);
//��ջ����
int *tos, *p1, stack[SIZE];

//ջ��ָ�롢ջ��ָ�롢��ջ
int main() {
	int value;
	tos = stack;
	p1 = stack;

	do {
		printf("����һ��������\n");
		scanf("%d", &value);
		if (value != 0)
			push(value);
		else
			printf("��ջ������%d\n", pop());
	} while (value != 0);
	system("PAUSE");
	return 0;
}

void push(int i) {
	p1++;
	if (p1 == (tos + SIZE)) {
		//�ж϶�ջ�Ƿ�����
		printf("��ջ����\n");
		system("PAUSE");
		exit(1);
	}
	*p1 = i;
}

int pop(void) {
	if (p1 == tos) {
		//�ж϶�ջ�Ƿ�Ϊ��
		printf("��ջ��\n");
		system("PAUSE");
		exit(1);
	}
//	p1--;
//	return *(p1 + 1);
	return *p1;
}