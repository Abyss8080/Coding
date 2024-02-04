#include <stdio.h>
#include <string.h>
#define MAX 100000

int main() {
	int n, i, x = 0;
	scanf("%d", &n);
	char demand[3][8] = {"VISIT", "BACK", "FORWARD"};
	char input[8];
	int arr[MAX] = {0};
	char address[MAX + 1][100];
	int addressnum = -1;
	int stack1[MAX], stack2[MAX];
	int top1 = -1, top2 = -1;
	int isnew = 1;
	for (i = 0; i < n; i++) {
		scanf("%s", input);
		if (strcmp(input, demand[0]) == 0) {
			arr[i] = 0;
			addressnum++;
			scanf("%s", address[ addressnum]);
		} else if (strcmp(input, demand[1]) == 0) {
			arr[i] = 1;
		} else if (strcmp(input, demand[2]) == 0) {
			arr[i] = 2;
		}
	}

	x = -1;
	for (i = 0; i < n; i++) {
		if (arr[i] == 0) {
			x++;
			top1++;
			stack1[top1] = x;
			printf("%s\n", address[stack1[top1]]);
			top2 = -1;
		} else if (arr[i] == 1) {
			if (top1 - 1 < 0)
				printf("Ignore\n");
			else {
				top2++;
				stack2[top2] = stack1[top1];
				top1--;
				printf("%s\n", address[stack1[top1]]);
			}
		} else if (arr[i] == 2) {
			if (top2 == -1)
				printf("Ignore\n");
			else {
				top1++;
				stack1[top1] = stack2[top2];
				top2--;
				printf("%s\n", address[stack1[top1]]);
			}
		}
	}
	return 0;
}