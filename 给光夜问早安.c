#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int type;
	scanf("%d", &type);
	if (type == 1) {
		printf("���Ϻã�11��");
	} else if (type == 2) {
		printf("���Ϻã����ˣ�");
	} else if (type == 3) {
		printf("���Ϻã�С���꣡");
	} else if (type == 4) {
		printf("���Ϻã�δ���");
	} else if (type == 5)
		printf("���Ϻã���Բ��");
	else {
		printf("���Ϻã�С���ʦ��");
	}
	return 0;
}