#include <windows.h>
#include <stdio.h>

int main() {
	int a;
	a = 1000;
	printf("��");
	Sleep(a);/* VC ʹ��Sleep*/
	printf("��"); /*������㡱�͡��á�֮�����һǧ���룬�����һ�룬Sleep()�ĵ�λΪ����*/
	return 0;
}