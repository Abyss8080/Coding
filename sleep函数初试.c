#include <windows.h>
#include <stdio.h>

int main() {
	int a;
	a = 1000;
	printf("你");
	Sleep(a);/* VC 使用Sleep*/
	printf("好"); /*输出“你”和“好”之间会间隔一千毫秒，即间隔一秒，Sleep()的单位为毫秒*/
	return 0;
}