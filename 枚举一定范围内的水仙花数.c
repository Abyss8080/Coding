#include <stdio.h>
#include <math.h>

int main() {
	int x = 0, n = 0;

	printf("�����뷶Χ�����������");
	scanf("%d", &n);
	for (x = 0; x <= n; x++) {

		int cnt = 0;
		int t = x;
		do {
			t /= 10;
			cnt++;
		} while (t > 0);
//	printf("%d", cnt);/*���xΪcntλ��*/
		int i, j, k = 0;
		int m = x;
		for (i = 1; i <= cnt; i++) {
			j = m % 10;
			m /= 10;
			k += pow(j, cnt);
		}/*�������λ�ϵ�����cnt�η�*/
		if (k == x) {
			printf("%d\t", x);
			int z = 0;
			z++;
			if (z == 5) {
				printf("\n");
				int z = 0;
				z = 0;
			} else {
				printf(" ");
//				\*ûִ�з��У�����ִ��������ո�*\
			}
		}
	}
}
return 0;
}