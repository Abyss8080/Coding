#include <stdio.h>

int peach(int x, int y) {
	int t;
	if (x == 1)
		t = y;
	else {
		y = (y + 1) * 2;
		peach(x - 1, y);
	}
	return y;
}

int main() {
	int t, x, y;
	printf("���������ں���Ӧ������ʣ������"
	       "������10��ʣ��1����������10 1\n");
	scanf("%d %d", &x, &y);
	t = peach(x, y);
	printf("��һ�칲ժ%d���ҡ�", t);
	return 0;
}