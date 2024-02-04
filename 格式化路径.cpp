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





/*题目
实现一个对输入的路径进行处理、并输出正确结果的程序。具体要求如下：

所有输入中的\被当做/加以处理，且在输出中被转换为/。
连续多个/被压缩成一个。
输入中单独的.被直接删除。若为连续的.，则参考下面一条规则。
输入中的..会导致..之前的一级目录被删去。然而如果输入中已经不存在父目录，则直接输出Value Error。保证不会出现...、....等不合法的情况。
如果输入为空，或者所有父目录被删去，则根据下面的规则输出空串或/。
当且仅当输入以/开始（或以\开始）时，输出才以/开始。
无论输入是否以/结尾，输出的结尾不带有/，除非输出是/。
使用之前学到的白盒测试和黑盒测试方法，尽量减少错误次数。能一次通过最好啦！

输入格式

输入 T(1 \leq T \leq 10)T(1≤T≤10) 行，每行为一个长度不超过 100100 的字符串（包含字母、数字、.、\和/），表示输入的路径。

输出格式
输出 TT 行字符串，表示处理后的 TT 个路径。*/