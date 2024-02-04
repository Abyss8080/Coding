#include <stdio.h>
#include <string.h>
#define MAX 200
#define MAXNA 21

int main() {
	int n, m;
	int i, j;
	int a, b, now = 0;
	int find1 = 0, find2 = 0;
	char name1[MAXNA], name2[MAXNA];
	char person[MAX][MAXNA];
	int isfriend[MAX][MAX];
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%s %s", name1, name2);
		for (j = 0; j < now; j++) {
			if (strcmp(name1, person[j]) == 0) {
				a = j;
				break;
			}
		}
		if (j == now) {
			strcpy(person[now], name1);
			a = now;
			now++;
		}
		for (j = 0; j < now; j++) {
			if (strcmp(name2, person[j]) == 0) {
				b = j;
				break;
			}
		}
		if (j == now) {
			strcpy(person[now], name2);
			b = now;
			now++;
		}
		isfriend[a][b] = isfriend[b][a] = 1;
	}

	scanf("%d", &m);
	for (i = 0; i < m; i++) {
		find1 = find2 = 0;
		scanf("%s %s", name1, name2);
		for (j = 0; j < now; j++) {
			if (strcmp(name1, person[j]) == 0) {
				a = j;
				find1 = 1;
				break;
			}
		}
		for (j = 0; j < now; j++) {
			if (strcmp(name2, person[j]) == 0) {
				b = j;
				find2 = 1;
				break;
			}
		}
		if (find1 && find2 && isfriend[a][b] == 1)
			printf("Yes\n");
		else
			printf("No\n");
	}
	return 0;
}
//自己和自己是朋友，没出现过的人不是朋友。