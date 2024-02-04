#include <stdio.h>
#include <string.h>

int main() {
	char s[201];
	int i = 0;
	gets(s);
	char stack[200], c;
	int top = -1;
	top++;
	stack[top] = s[i];
	while (top != -1 && s[i] != '\0') {
		i++;
		if (s[i] == ' ') {
			c = stack[top];
			if (c != ' ') {
				top++;
				stack[top] = s[i];
			}
		} else {
			top++;
			stack[top] = s[i];
		}
	}
	top++;
	stack[top] = '\0';
	printf("%s", stack);
	return 0;
}