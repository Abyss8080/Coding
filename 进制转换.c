#include <stdio.h>

long long changeto(int x, int y) {
	long long n = 0;
	int i = 0, m = 0;
	int cnt = 0;
	int t;
	t = x;

	if (x < y) {
		n = (long long)x;
	} else if (x == y) {
		n = 1;
	} else if (x > y) {
		do {
			t /= y;
			cnt++;
		} while (t != 0);
		/*�ж��ٸ�����*/
		int a[cnt];
		for (i = 0; (i + 1) <= cnt; i++) {
			a[i] = x % y;
			x /= y;
		}
		for (m = 0; m <= cnt; m++) {
			n = n * 10 + a[cnt - m];
		}
	}
	return n;
}

int main() {
	long long  t;
	int x, y;
	printf("��������ת����ʮ��������Ŀ�Ľ��ƣ�\n"
	       "(���189ת����12���ƣ�������189 12.)\n");
	scanf("%d %d", &x, &y);
	t = changeto(x, y);
	printf("%d��%d���Ʊ�ʾΪ%llu��", x, y, t);
	return 0;

}