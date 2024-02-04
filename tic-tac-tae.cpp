#include <stdio.h>

int main() {
	const int size = 3;
	int board[size][size];
	int i, j;
	int num0fx = 0, num0f0 = 0;
	int result = -1; /*-1没人赢，1x赢，00赢*/
	int ax[size], bx[size]   ;              //假设a0,bx两位玩家。
	int ay[size], by[size]   ;              //x代表行累计，y代表列累计（例如a_x[2]代表 a在第二行的棋子数）
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

	}/*行列上判断的合并*/
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
	}/*对角线判断*/
	printf("result=%d.\n");
	if (result == 0) {
		printf("0赢");

	} else if (result == 1) {
		printf("x赢");

	} else if (result == -1) {
		printf("没人赢");
	}
	return 0;




}