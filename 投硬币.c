#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int flip() {
	int x;
	x = rand() % 2;
	return x;
}

int main() {
	int x = 1;
	int y = 0;
	int ret = 0;
	time_t t;
//	<time.h>
//#ifndef __TIME_T
//#define __TIME_T      /* �����ظ����� time_t */
//typedef long      time_t;    /* ʱ��ֵtime_t Ϊ�����͵ı���*/
//#endif
	srand((unsigned int)time(&t));
	//rand()����ÿ�ε���ǰ�����ѯ�Ƿ���ù�srand(seed)���Ƿ��seed�趨��һ��ֵ
	//�������ô�����Զ�����srand(seed)һ������ʼ��������ʼֵ
	//seed��ͬ�������������Ҳ����ͬ
	for (x = 1; x <= 100; x++) {
		y = flip();
		if (y == 1) {
			ret++;
			printf("����\n");
		} else {
			printf("����\n");
		}
	}
	printf("��100��ͶӲ�ҵĽ���У���%d�����棬%d�η��档", ret, 100 - ret);
	return 0;
}