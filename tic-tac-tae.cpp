#include <stdio.h>

int main() {
	const int size = 3;
	int board[size][size];
	int i, j;
	int num0fx = 0, num0f0 = 0;
	int result = -1; /*-1û��Ӯ��1xӮ��00Ӯ*/
	int ax[size], bx[size]   ;              //����a0,bx��λ��ҡ�
	int ay[size], by[size]   ;              //x�������ۼƣ�y�������ۼƣ�����a_x[2]���� a�ڵڶ��е���������
	for (i = 0; i < size ; i++) {
		for (j = 0; j < size; j++) {
			scanf("%d", &board[i][j]);
		}
	}


	for (i = 0; i < size && result == -1; i++) {
		for (int j = 0; j < size; j++) {
			if (board[i][j] == 0) {
				ax[i] ++;
				ay[j] ++;
			} else if (board[i][j] == 1) {
				bx[i] ++;
				by[j] ++;
			}
			if (ax[i] == size || ay[j] == size) {
				result = 0;
				break;
			} else if (bx[i] == size || by[j] == size) {
				result = 1;
			}
		}

	}/*�������жϵĺϲ�*/
	for (i = 0; i < size; i++) {
		if (board[i][i] == 1) {
			num0fx++;
		} else if (board[i][i] == 0) {
			num0f0++;
		}
	}
	if (num0fx == 3) {
		result = 1;
	} else if (num0f0 == 3) {
		result = 0;
	}

	for (i = 0; i < size; i++) {
		if (board[i][size - i - 1] == 1) {
			num0fx++;
		} else if (board[i][size - i - 1] == 0) {
			num0f0++;
		}
	}
	if (num0fx == 3) {
		result = 1;
	} else if (num0f0 == 3) {
		result = 0;
	}/*�Խ����ж�*/
	printf("result=%d.\n");
	if (result == 0) {
		printf("0Ӯ");

	} else if (result == 1) {
		printf("xӮ");

	} else if (result == -1) {
		printf("û��Ӯ");
	}
	return 0;




}