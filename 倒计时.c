#include <stdio.h>

int main(void) {
	int count = 0;
	printf("�����뵹��ʱ��ʱ�䣺\n");
	scanf("%d", &count);

	while (count > 0) {
		count--;
		printf("%d\n", count);
	}
	printf("���䣡\n");
	return 0;
}