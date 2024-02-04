#include <stdio.h>
#include <string.h>
#include <malloc.h>
#define MAXN 200001
char *operation[MAXN];
int n;

void str1(int i, char p) {
	if (i > 1)
		operation[i] = strcpy(operation[i], operation[i - 1]);
	int len = strlen(operation[i]);
	operation[i][len] = p;
	operation[i][len + 1] = '\0';
}

void str2(int i, int x) {
	operation[i] = strcpy(operation[i], operation[x]);
}

void SpecialCount(int i, int l, int r) {
	int count = 0, lenth = 1;
	int len = strlen(operation[i]);
	while (lenth <= len) {
		if (l > len)
			break;
		if (lenth >= l && lenth <= r) {
			char *string1 = (char *)malloc(sizeof(char) * MAXN);
			string1 = strncpy(string1, operation[i], lenth);
			string1[lenth] = '\0';
			char *string2 = NULL;
			string2 = operation[i] + len - lenth;
			if (strcmp(string1, string2) == 0)
				count++;
			free(string1);
		}
		lenth++;
	}
	printf("%d\n", count);
}


int main() {
	int l, r, com;
	char p;
	int p1;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &com);
		operation[i] = (char *)malloc(sizeof(char) * MAXN);
		operation[i][0] = '\0';
		switch (com) {
			case 1:
				scanf(" %c %d %d", &p, &l, &r);
				str1(i, p);
				break;
			case 2:
				scanf("%d %d %d", &p1, &l, &r);
				str2(i, p1);
				break;
		}
		SpecialCount(i, l, r);
	}
	for (int i = 1; i <= n; i++)
		free(operation[i]);
	return 0;
}
