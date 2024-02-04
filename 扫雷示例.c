#ifndef __Test_H__
#define __Test_H__

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <time.h>
#define	WHAT '*'
#define NUM  20
#define COL  10
#define ROW  10
void Game();
#pragma warning(disable:4996)
#endif       //以上都是头文件
void Game() {
	srand((unsigned long)time(NULL)); //生成随机数种子

	char show_board[ROW][COL];
	char mines_board[ROW][COL];

	memset(show_board, WHAT, sizeof(show_board));
	memset(mines_board, '0', sizeof(mines_board));

	SetMines(mines_board, ROW, COL);

	int count = (ROW - 2) * (COL - 2) - NUM;  //若扫完这些次 不触雷则胜利

	while (count) {
		system("cls");
		ShowBoard(show_board, ROW, COL);
		printf("请选择你要扫描的区域坐标 ");
		int x = 0;
		int y = 0;
		scanf("%d %d", &x, &y);
		if (x < 1 || x > ROW - 2 || y < 1 || y > COL - 2) { //非法性输入判断
			printf("输入错误！\n");
			continue;
		}
		if (show_board[x][y] != WHAT) {
			printf("此处已经被扫过了，请从新输出\n");
			continue;
		}
		if (mines_board[x][y] == '1') {
			system("cls");
			ShowBoard(mines_board, ROW, COL);
			printf("踩雷了!游戏结束!\n");
			break;
		}

		show_board[x][y] = CountMines(mines_board, x, y);
		count--;
	}
}


CountMines(char board[][COL], int x, int y) { //统计周围雷的个数
	return board[x - 1][y - 1] + board[x - 1][y] + board[x - 1][y + 1] + \
	       board[x][y + 1] + board[x + 1][y + 1] + board[x + 1][y] + \
	       board[x + 1][y - 1] + board[x][y - 1] - 7 * '0';//本来减八个零，但是整形转字符加一个‘0’
}

void ShowBoard(char board[][COL], int row, int col) { //扫雷展示面板
	printf("     ");
	for (int i = 1; i <= (col - 2); i++) {
		printf("%d   ", i);
	}
	printf("\n");
	ShowLine(col);//显示行线
	for (int i = 1; i <= (row - 2); i++) {
		printf("%-3d|", i);
		for (int j = 1; j <= (col - 2); j++) {
			printf(" %c |", board[i][j]);
		}
		printf("\n");
		ShowLine(col);
	}
}

void SetMines(char board[][COL], int row, int col) { //放雷函数
	int count = NUM;
	while (count) {
		int x = rand() % (row - 2) + 1;
		int y = rand() % (col - 2) + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			count--;
		}
	}
}

void ShowLine(int col) {

	for (int i = 0; i <= (col - 2); i++) {
		printf("----");
	}
	printf("\n");
}

Menu() {  //用户交互函数
	printf("########################\n");
	printf("# 1. Play       0.Exit #\n");
	printf("########################\n");
}


int main() {
	int quit = 0;
	int select = 0;
	while (!quit) {
		Menu();
		printf("请输入 ");
		scanf("%d", &select);
		switch (select) {
			case 1:
				Game();
				break;
			case 0:
				quit = 1;
				break;
			default:
				printf("输入错误，请重试！\n");
				break;
		}
	}

	printf("byebye!\n");

	system("pause");
	return 0;
}


