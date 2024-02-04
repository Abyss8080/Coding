#include <stdio.h>

int main() {
	int arr[10];
	int i = 0, j = 0, k, temp;
	for (i = 0; i < 10; i++)
		scanf("%d", &arr[i]);
	i = 0;
	j = 9;
	while (i < j) {
		while (arr[i] % 2 != 0 && i < j) {
			i++;
		}
		while (arr[j] % 2 == 0 && j > i) {
			j--;
		}
		if (j > i) {
			temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	k = i;
	for (i = 0; i < k; i++) {
		for (j = 0; j < k - 1; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = k; i < 10; i++) {
		for (j = k; j < 9; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
	for (i = 0; i < 10; i++)
		printf("%d ", arr[i]);

	return 0;
}