#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int type;
	scanf("%d", &type);
	switch (type) {
		case 1:
			printf("���Ϻã�11��");
			break;
		case 2 :
			printf("���Ϻã����ˣ�");
			break;
		case 3:
			printf("���Ϻã�С���꣡");
			break;
		case 4:
			printf("���Ϻã�δ���");
			break;
		case 5:
			printf("���Ϻã���Բ��");
			break;
		default:
			printf("���Ϻã�С���ʦ��");
	}

	return 0;
}