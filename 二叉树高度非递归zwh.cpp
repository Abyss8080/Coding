#include <stdio.h>
#include <stdlib.h>
#define MAX 100

void buildtree(int N, int &tree_count) {
	int arr[MAX], idx = 0, stack[MAX], top = -1;
	arr[idx] = 1;
	idx++;
	top++;
	stack[top] = 1;
	bool flag;
	while (idx > 0) {
		if (idx == N) {
			tree_count++;
			printf("%d:", tree_count);
			for (int i = 0; i < N; i++)
				printf("%d ", arr[i]);
			printf("\n");
			idx--;
			top--;
		}
		flag = false;
		for (int i = stack[top] + 1; i <= arr[idx - 1] * 2 + 1; i++) {
			for (int j = 0; j < idx; j++)
				if (i / 2 == arr[j] && i > arr[idx - 1]) {
					stack[top] = i;
					arr[idx] = i;
					idx++;
					top++;
					stack[top] = 1;
					flag = true;
					break;
				}
			if (flag == true)
				break;
		}
		if (flag == false) {
			idx--;
			top--;
		}
	}
}

int main() {
	int N, tree_count = 0;
	printf("请输入树的结点个数：");
	scanf("%d", &N);
	buildtree(N, tree_count);
	printf("tree_count is %d when N is %d", tree_count, N);
	return 0;
}