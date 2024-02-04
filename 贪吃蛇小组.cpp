/**
 * @file player.h
 * @author yangboyang@jisuanke.com
 * @copyright jisuanke.com
 * @date 2021-07-01
 */

#include <string.h>
#include "../include/playerbase.h"
#include <stdio.h>
#define MAX 100

typedef struct {
	int head;
	char sta[MAX];
} Status;

typedef struct {
	int x, y;
	int step;
	Status sta;
	int last;
} St;
int lenth;
St pre;

int step[4][2] = { 0, 1, 0, -1, 1, 0, -1, 0};
Status vis[MAX][MAX], possta;

int in(int x, int y, struct Player *player) {
	return (x >= 0 && x < player->row_cnt && y >= 0 && y < player->col_cnt);
}

int equal(Status a, Status b) {
	if (a.head != b.head)
		return 0;
	for (int i = a.head; i >= a.head - lenth + 1; i--) {
		if (a.sta[i] != b.sta[i])
			return 0;
	}
	return 1;
}

int is_inner_and_nocrash(int x, int y, int nx, int ny, struct Player *player) {
//判断是否在界内且不会撞到蛇身
//player->your_posx!=x,y同理,这里没有冗余；
	if (!in(nx, ny, player))
		return 0;
	if (lenth == 1)
		return 1;
	int p;
	if (lenth > 2)
		p = 2;
	else
		p = 1; //p=1表示lenth为2，p=2表示lenth>2
	int xb = x, yb = y;
	for (int i = 0; i < lenth - p; i++) {
		int a = vis[x][y].head;
		xb = xb + step[(int)vis[x][y].sta[a]][0];
		yb = yb + step[(int)vis[x][y].sta[a]][1];
		a--;
		if (xb == nx && yb == ny)
			return 0;
	}
	return 1;
}

void BFS(struct Player *player, Status psta) {
	int i, j;
	St qu[MAX];
	int l, r;
	l = r = 0;
	int x = player->your_posx;
	int y = player->your_posy;
	St to = {x, y, 0, psta, -1};
	qu[r++] = to;
	while (l < r) {
		St now = qu[l++];
		x = now.x;
		y = now.y;
		for (i = 0; i <= psta.head; i++)
			vis[x][y].sta[i] = psta.sta[i];
		vis[x][y].head = psta.head;
		if (player->mat[x][y] == 'o' || player->mat[x][y] == 'O') {
			pre = now;
			while (qu[pre.last].last != -1)
				pre = qu[pre.last];
			return;
		}
		for (i = 0; i < 4; i++) {
			int nx = x - step[i][0];
			int ny = y - step[i][1];
			if (is_inner_and_nocrash(x, y, nx, ny, player)
			        && (player->mat[nx][ny] == '.' || player->mat[nx][ny] == 'o' || player->mat[nx][ny] == 'O')) {
				Status nextsta;
				for (j = 0; j <= vis[x][y].head; j++)
					nextsta.sta[j] = vis[x][y].sta[j];
				nextsta.head = vis[x][y].head;
				nextsta.head++;
				nextsta.sta[nextsta.head] = i; //如果要走，下一步更新的status
				if (vis[nx][ny].head == -1 || !equal(vis[nx][ny], nextsta)) { //没有访问过或者没有以status的状态访问过
					St next = {nx, ny, now.step + 1, nextsta, l - 1};
					qu[r++] = next;
				}
			}
		}
	}
}


void init(struct Player *player) {
	lenth = 1;
	possta.head = -1;
	// This function will be executed at the begin of each game, only once.
}

struct Point walk(struct Player *player) {
	// This function will be executed in each round.
	int i, j;
	pre.x = pre.y = -1;

	for (i = 0; i < player->your_posx; i++) {
		for (j = 0; j < player->your_posy; j++) {
			vis[i][j].head = -1;
			strcpy(vis[i][j].sta, "");
		}
	}
	BFS(player, possta);
	if (pre.x != -1 && pre.y != -1) {
		printf("@@@@@@@@@@@@@@@@@@@@@@@@@WJLWJLWJLWJL\n");
		for (i = 0; i < 4; i++) {
			int x = pre.x - step[i][0];
			int y = pre.y - step[i][1];
			if (x == player->your_posx && y == player->your_posy)
				break;
		}
		possta.head++;
		possta.sta[possta.head] = i;
		if (player->round >= 3 * (player->col_cnt + player->row_cnt) / 8 + 1) { //大于基础长度
			if (player->mat[pre.x][pre.y] == 'o' && player->mat[pre.x][pre.y] == 'O')//吃到了道具
				lenth++;
		} else//小于基础长度
			lenth++;
		//printf("2、now(%d,%d)->pre(%d,%d)\n", player->your_posx, player->your_posy, pre.x, pre.y);
		return initPoint(pre.x, pre.y);
	}
	if (player->round >= 3 * (player->col_cnt + player->row_cnt) / 8 + 1)
		lenth--;
	return initPoint(player->your_posx, player->your_posy);
}