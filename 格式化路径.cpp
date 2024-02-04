#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 102

void Format(char *path) {
	int top = -1, i = 0, flag = 0;
	char stack[MAX];
	if (path[0] == '/' || path[0] == '\\')
		flag = 1;
	while (i < strlen(path)) {
		if ((path[i] == '/' || path[i] == '\\')
		        && (top == -1 || stack[top] != '/')) {
			stack[++top] = '/';
		} else if (path[i] == '.') {
			if (i + 1 >= strlen(path)) {
				break;
			} else if (path[i + 1] == '.') {
				if (top == -1 || (stack[top] == '/' && top == 0)) {
					strcpy(path, "Value Error");
					return;
				} else {
					top--;
					while (stack[top] != '/' && top > -1) {
						top--;
					}
					i += 2;
					continue;
				}
			}
		} else if (path[i] != '/' && path[i] != '\\') {
			stack[++top] = path[i];
		}
		i++;
	}

	if (stack[0] == '/' && flag == 0) {
		int i = 0;
		while (i < top) {
			stack[i] = stack[i + 1];
			i++;
		}
		top--;
	}
	if (top < 0) {
		strcpy(path, "");
		return;
	}
	if (top != 0 && stack[top] == '/') {
		top--;
	}
	int j = 0;
	while (j <= top) {
		path[j] = stack[j];
		j++;
	}
	path[j] = '\0';
}


int main() {
	char path[MAX];
	while (scanf("%s", path) != -1) {
		Format(path);
		puts(path);
	}
}





/*��Ŀ
ʵ��һ���������·�����д����������ȷ����ĳ��򡣾���Ҫ�����£�

���������е�\������/���Դ�����������б�ת��Ϊ/��
�������/��ѹ����һ����
�����е�����.��ֱ��ɾ������Ϊ������.����ο�����һ������
�����е�..�ᵼ��..֮ǰ��һ��Ŀ¼��ɾȥ��Ȼ������������Ѿ������ڸ�Ŀ¼����ֱ�����Value Error����֤�������...��....�Ȳ��Ϸ��������
�������Ϊ�գ��������и�Ŀ¼��ɾȥ�����������Ĺ�������մ���/��
���ҽ���������/��ʼ������\��ʼ��ʱ���������/��ʼ��
���������Ƿ���/��β������Ľ�β������/�����������/��
ʹ��֮ǰѧ���İ׺в��Ժͺںв��Է������������ٴ����������һ��ͨ���������

�����ʽ

���� T(1 \leq T \leq 10)T(1��T��10) �У�ÿ��Ϊһ�����Ȳ����� 100100 ���ַ�����������ĸ�����֡�.��\��/������ʾ�����·����

�����ʽ
��� TT ���ַ�������ʾ������ TT ��·����*/