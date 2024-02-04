#include <stdio.h>
   int k;

void move(int n, char getone, char putone) {

	printf("%d step :\n", k + 1);
	printf("%d part :%c->%c\n\n", n, getone, putone);
	k++;
}

void hanoi(int n, char one, char two, char three) {

	if (n == 1) {
		move(1, one, three);

	} else {

		hanoi(n - 1, one, three, two );
		//����ʼ����ʣ������һ����Բ���ƶ���Ŀ������
		move(n, one, three);
		//�ݹ���� hanoi() ���������������ϵ� n-1 Բ���ƶ���Ŀ������
		hanoi(n - 1, two, one, three);
	}
}

int main() {
	int m;
	printf("Input the number of disks:");
	scanf("%d", &m);
	printf("The steps to moving %3d disks:\n", m);

	//���ƶ� 3 ��Բ��Ϊ������ʼ����Ŀ�������������ֱ��� A��B��C ��ʾ
	hanoi(m, 'A', 'B', 'C');

	return 0;
}