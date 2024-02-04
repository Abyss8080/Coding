#include <stdio.h>
#pragma warning (disable:4996)
#pragma warning (disable:6031)
#define MaxSize 100
void buildtree(int N, int &tree_count);

int main() {
	int N = 0;
	int tree_count = 0;
	printf("请输入满二叉树高度：");
	scanf("%d", &N);
	buildtree(N, tree_count);
	printf("tree_count is %d when N is %d.", tree_count, N);
	return 1;
}

void buildtree(int N, int &tree_count) {
	int arr[MaxSize] = { 0 }, top = -1, stack[MaxSize] = { 0 };
	int idx = 0;
	bool Find = false;
	arr[idx] = 1;
	idx++;
	top++;
	stack[top] = 1;
	while (idx >= 0) {
		if (idx == N) {
			tree_count++;
			printf("%d:", tree_count);
			for (int k = 0; k < N; k++)
				printf("%d ", arr[k]);
			printf("\n");
			idx--;
		}
		Find = false;
		for (int i = stack[top] + 1; i <= arr[idx - 1] * 2 + 1; i++) {
			for (int j = 0; j < idx; j++) {
				if (i / 2 == arr[j]) {
					arr[idx] = i;
					top = idx;
					stack[top] = arr[idx];
					Find = true;
					break;
				}
			}
			if (Find) {
				idx++;
				break;
			}
		}
		if (!Find) {
			idx--;
			top--;

		}
	}
}