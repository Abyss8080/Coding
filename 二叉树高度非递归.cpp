#include <stdio.h>
#pragma warning (disable:4996)
#pragma warning (disable:6031)
#define MaxSize 100
void buildtree(int N, int &tree_count);

int main() {
	int N = 0;
	int tree_count = 0;
	printf("���������������߶ȣ�");
	scanf("%d", &N);
	printf("������£�");
	buildtree(N, tree_count);

	printf("\nCatalan is true or false:");

	return 1;
}

void buildtree(int N, int &tree_count) {
	int arr[MaxSize] = { 0 };
	int idx = 0;
	int i = 0, j = 0;
	arr[idx] = 1;
	idx++;
	while (idx > 0) {
		if (idx < N && arr[idx] < arr[idx - 1] * 2 + 1) {
			//��û���ҵ��㹻�Ķ����������arr[idx]�ĺϷ�ֵ��û��ȡ���ʱ��
			for (i = arr[idx] + 1; i < arr[idx - 1] * 2 + 1; i++) {
				for (j = 0; j < idx; j++) {
					if (i / 2 == arr[j]) {
						arr[idx] = i;
						break;
					}
				}
				break;
			}
			idx++;
		} else {
			if (idx == N) {
				tree_count++;
				printf("\n%d:", tree_count);
				for (i = 0; i < N; i++)
					printf("%d ", arr[i]);
			}
			idx--;
		}

	}

}