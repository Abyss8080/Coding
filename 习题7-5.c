#include <stdio.h>

int main() {
	int a, b;
	int i = 0, j = 0;
	int k = 0, t = 0;
	int z;
	printf("�������һ�������Ԫ�ظ�����");
	scanf("%d", &a);
	printf("������ڶ��������Ԫ�ظ�����");
	scanf("%d", &b);
	int first[a];
	int second[b];
	int best[a + b];
	for (i = 0; i<a; i++) {
		printf("�������һ��������%d��Ԫ�أ�", i + 1);
		scanf("%d", &first[i]);
		best[i] = first[i];
	}
	for (j = 0; j<b; j++) {
		printf("������ڶ���������%d��Ԫ�أ�", j + 1);
		scanf("%d", &second[j]);
		best[j + a] = second[j];
	}/*������������*/

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