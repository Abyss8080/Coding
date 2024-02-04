#include <stdio.h>
#pragma warning (disable:4996)
#pragma warning (disable:6031)
#define MaxSize 100
void arrange(int arr[], int idx, int N, int &tree_count);
bool Catalan(int M, int N);

int main() {
	int N = 0;
	int arr[MaxSize] = { 0 };
	int tree_count = 0;
	printf("请输入满二叉树高度：");
	scanf("%d", &N);
	arrange(arr, 0, N, tree_count);
	printf("tree_count is %d when N is %d.", tree_count, N);
	printf("\nCatalan is true or false:");
	if (Catalan(tree_count, N))
		printf("True!");
	else
		printf("False!");

	return 1;
}

void arrange(int arr[], int idx, int N, int &tree_count) {
	int i = 0, j = 0;
	if (idx == N) {
		tree_count++;
		printf("%d:", tree_count);
		for (i = 0; i < N; i++)
			printf("%d ", arr[i]);
		printf("\n");
		return;
	}
	if (idx == 0) {
		arr[idx] = 1;
		arrange(arr, idx + 1, N, tree_count);
	} else {
		for (i = arr[idx - 1] + 1; i <= 2 * arr[idx - 1] + 1; i++)
			for (j = 0; j < idx; j++) { //如果这个二叉树结点是已经选取的任意一个结点的孩子节点（下一层）
				if (i / 2 == arr[j]) {
					arr[idx] = i;
					arrange(arr, idx + 1, N, tree_count);
				}
			}
	}
}

bool Catalan(int M, int N) {
	int k = 1;
	for (int i = 2 * N; i >= N + 2; i--)
		k = k * i;
	for (int i = 1; i <= N; i++)
		k = k / i;
	if (M == k)
		return true;
	else
		return false;
}