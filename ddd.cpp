#include <stdio.h>
#include <math.h>
#pragma warning (disable:4996)
#pragma warning (disable:6031)
#define MaxSize 100

void Arrange(int arr[], int idx, int N, int &tree_count, int &height);

int main() {
	int N = 0, H = 0, log = 0;
	int arr[MaxSize] = { 0 };
	int tree_count = 0;
	double average = 0;
	int i = 0, j = 0;
	printf("���������������߶ȣ�");
	scanf("%d", &N);
	Arrange(arr, 0, N, tree_count, H);
	printf("tree_count is %d when N is %d.", tree_count, N);
	printf("\n�ܸ߶�        ��%d", H);
	printf("\n�ܶ���������  ��%d", tree_count);
	average = (H * 1.0) / (tree_count * 1.0);
	printf("\n������ƽ���߶ȣ�%f", average);
	while (i < N) {
		if (N == 1)
			break;
		log++;
		i = (int)pow(2, log);
	}
	if (log < average)
		printf("\nlog2 N < ƽ���߶�!");
	else
		printf("\nlog2 N >= ƽ���߶�!");

	return 1;
}

void Arrange(int arr[], int idx, int N, int &tree_count, int &height) {
	int i = 0, j = 0;
	int level = 0, m = 0;
	if (idx == N) {
		tree_count++;
		printf("%d:", tree_count);
		for (i = 0; i < N; i++)
			printf("%d ", arr[i]);
		printf("\n");
		while (arr[i - 1] > m) {
			level++;
			m = 2 * m + 1;
		}
		height = height + level;
		return;
	}
	if (idx == 0) {
		arr[idx] = 1;
		Arrange(arr, idx + 1, N, tree_count, height);
	} else {
		for (i = arr[idx - 1] + 1; i <= 2 * arr[idx - 1] + 1; i++)
			for (j = 0; j < idx; j++) { //������������������Ѿ�ѡȡ������һ�����ĺ��ӽڵ㣨��һ�㣩
				if (i / 2 == arr[j]) {
					arr[idx] = i;
					Arrange(arr, idx + 1, N, tree_count, height);
				}
			}
	}
}
