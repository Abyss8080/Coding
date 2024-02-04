#include <stdio.h>
#include <string.h>
#define MAX 50001

typedef struct {
	int i;
	char c;
} S;

typedef struct {
	int left;
	int right;
} Pair;

int main() {
	char arr[MAX];
	int i = 0, j = -1;
	scanf("%s", arr);
	int len = strlen(arr);
	if (len % 2 != 0) {
		printf("No");
		return 0;
	}
	S stack[MAX];
	Pair p[MAX];
	int top = -1, num = -1;
	top++;
	stack[top].c = arr[i];
	stack[top].i = i;
	i++;
	while (arr[i] != '\0') {
		if (arr[i] == '(') {
			top++;
			stack[top].c = arr[i];
			stack[top].i = i;
		} else if (arr[i] == ')') {
			if (top == -1) {
				printf("No");
				return 0;
			}
			num++;
			p[num].left = stack[top].i + 1;
			p[num].right = i + 1;
			top--;
		}
		i++;
	}
	if (arr[i] == '\0' && top == -1) {
		printf("Yes\n");
		for (i = num; i >= 0; i--)
			if (p[i].left == 1)
				printf("%d %d\n", p[i].left, p[i].right);
		for (i = num; i >= 0; i--)
			if (p[i].left != 1)
				printf("%d %d\n", p[i].left, p[i].right);
	} else
		printf("No");
	return 0;
}