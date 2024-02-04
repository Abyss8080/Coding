#include <stdio.h>
#include <math.h>

int main() {
	int x = 0;
	printf("请输入一个正整数：");
	scanf("%d", &x);
	int cnt = 0;
	int t = x;

	do {
		t /= 10;
		cnt++;
	} while (t > 0);
//	printf("%d", cnt);/*求得x为cnt位数*/
	int i, j, k = 0;
	int m = x;

	for (i = 1; i <= cnt; i++) {

		j = m % 10;
		m /= 10;
		k += pow(j, cnt);
	}

	if (k == x) {
		printf("%d是水仙花数。", x);
	} else {
		printf("%d不是水仙花数。", x);
	}

	return 0;
}