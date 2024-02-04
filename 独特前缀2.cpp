#include <stdio.h>
#include <string.h>
#define MAX 200000

int main() {
	int stack[MAX];
	int top = -1, n, com, l, r;
	char p1;
	int p2;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &com);
		top++;
		if (com == 1) {
			scanf(" %c %d %d", &p1, &l, &r);
			stack[top] = p1 + MAX;
		} else {
			scanf("%d %d %d", &p2, &l, &r);
			stack[top] = p2;
		}
		char str[MAX];
		int count = 0;
		for (int j = top; j >= 0; j--) {
			if (stack[j] > MAX) {
				str[count] = stack[j] - MAX;
				count++;
			} else {
				j = stack[j];
			}
		}
		int len = l;
		int upst = 0;
		while (len <= count) {
			int flag = 0;
			if (len >= l && len <= r)
				flag = strncmp(str, str + count - len, len);
			if (flag == 0)
				upst++;
			len++;
		}
		printf("%d\n", upst);
	}
	return 0;
}