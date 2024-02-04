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
		//将起始柱上剩余的最后一个大圆盘移动到目标柱上
		move(n, one, three);
		//递归调用 hanoi() 函数，将辅助柱上的 n-1 圆盘移动到目标柱上
		hanoi(n - 1, two, one, three);
	}
}

int main() {
	int m;
	printf("Input the number of disks:");
	scanf("%d", &m);
	printf("The steps to moving %3d disks:\n", m);

	//以移动 3 个圆盘为例，起始柱、目标柱、辅助柱分别用 A、B、C 表示
	hanoi(m, 'A', 'B', 'C');

	return 0;
}