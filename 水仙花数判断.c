#include <stdio.h>
#include <math.h>

int main() {
	int x = 0;
	printf("������һ����������");
	scanf("%d", &x);
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
	}

	if (k == x) {
		printf("%d��ˮ�ɻ�����", x);
	} else {
		printf("%d����ˮ�ɻ�����", x);
	}

	return 0;
}