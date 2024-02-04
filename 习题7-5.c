#include <stdio.h>

int main() {
	int a, b;
	int i = 0, j = 0;
	int k = 0, t = 0;
	int z;
	printf("请输入第一个数组的元素个数：");
	scanf("%d", &a);
	printf("请输入第二个数组的元素个数：");
	scanf("%d", &b);
	int first[a];
	int second[b];
	int best[a + b];
	for (i = 0; i<a; i++) {
		printf("请输入第一个函数第%d个元素：", i + 1);
		scanf("%d", &first[i]);
		best[i] = first[i];
	}
	for (j = 0; j<b; j++) {
		printf("请输入第二个函数第%d个元素：", j + 1);
		scanf("%d", &second[j]);
		best[j + a] = second[j];
	}/*读入两个数组*/

	for (k = 0; k< (a + b); k++) {
		for (t = 0; t<(a + b); t++) {
			if (best[k] <= best[t]) {
				;
			} else {
				z = best[k];
				best[k] = best[t];
				best[t] = z;
			}
		}
	}
	for (k = 0; k<(a + b); k++) {
		printf("best[%d]=%d\n", k, best[k]);
	}
	return 0;

}