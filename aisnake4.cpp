/**
 * @file player.h
 * @author yangboyang@jisuanke.com
 * @copyright jisuanke.com
 * @date 2021-07-01
 */

#include <string.h>
#include "../include/playerbase.h"
#include <stdio.h>
#define MAX 700

typedef struct {
	int head;
	int sta[MAX];
} Status;

typedef struct {
	int x, y;
	int step;
	Status sta;
	int last;
	int len;
} St;
int lenth;
St pre;

int step[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Status vis[10][10], possta;

int in(int x, int y, struct Player *player) {
	return (x >= 0 && x < player->row_cnt && y >= 0 && y < player->col_cnt);
}

int equal(Status a, Status b, int nowlen) {
	if (a.head != b.head)
		return 0;
	for (int i = a.head; i >= a.head - nowlen; i--) {
		if (a.sta[i] != b.sta[i])
			return 0;
	}
	return 1;
}

int is_inner_and_nocrash(St now, int nx, int ny, struct Player *player) {
//判断是否在界内且不会撞到蛇身
//player->your_posx!=x,y同理,这里没有冗余；
	if (!in(nx, ny, player))
		return 0;
	if ( now.len == 1)
		return 1;
	int x = now.x;
	int y = now.y;
	int xb = x, yb = y;
	// printf("\n\nnow:(%d,%d) next:(%d,%d)-----'%c'\n", now.x, now.y, nx, ny, player->mat[nx][ny]);
	// printf("now.len=%d\n", now.len);
	// printf("now.step=%d\n", now.step);
	for (int i = now.sta.head; i > now.sta.head - now.len ; i--) { ///调试完记得改i的边界条件
		xb = xb + step[now.sta.sta[i]][0];
		yb = yb + step[now.sta.sta[i]][1];
		//printf("(%d,%d)->", xb, yb);
		if (xb == nx && yb == ny)
			return 0;
	}
	return 1;
}

int Judge(int x, int y, struct Player *player) {
	int count = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + step[i][0];
		int ny = y + step[i][1];
		if (!in(nx, ny, player))
			count++;
		else if (player->mat[nx][ny] == '#' || player->mat[nx][ny] == '1')
			count++;
	}
	if (count >= 3)
		return 0;
	return 1;
}


void BFS(struct Player *player) {
	int i, j;
	St qu[MAX];
	int l, r;
	l = r = 0;
	int x = player->your_posx;
	int y = player->your_posy;
	St to = {x, y, 0, possta, -1, lenth};
	qu[r++] = to;
	for (i = 0; i <= possta.head; i++)
		vis[x][y].sta[i] = possta.sta[i];
	vis[x][y].head = possta.head;
	while (l < r) {
		St now = qu[l++];
		x = now.x;
		y = now.y;
		for (i = 0; i < 4; i++) {
			int nx = x - step[i][0];
			int ny = y - step[i][1];
			if (is_inner_and_nocrash(now, nx, ny, player)
			        && (player->mat[nx][ny] == '.' || player->mat[nx][ny] == 'o' || player->mat[nx][ny] == 'O')) {
				Status nextsta;
				for (j = 0; j <= now.sta.head; j++)
					nextsta.sta[j] = now.sta.sta[j];
				nextsta.head = now.sta.head;
				nextsta.head++;
				nextsta.sta[nextsta.head] = i; //如果要走，下一步更新的status
				St next = {nx, ny, now.step + 1, nextsta, l - 1, now.len};
				if (lenth + now.step < 3 * (player->col_cnt + player->row_cnt) / 8 + 1)
					next.len += 1;
				if (vis[nx][ny].head == -1 || !equal(vis[nx][ny], nextsta, next.len)) {
					for (j = 0; j <= nextsta.head; j++)
						vis[nx][ny].sta[j] = nextsta.sta[j];
					vis[nx][ny].head = nextsta.head;
					qu[r++] = next;
					if ((player->mat[nx][ny] == 'o' || player->mat[nx][ny] == 'O')
					        && Judge(nx, ny, player)) {
						pre = next;
						while (qu[pre.last].last != -1)
							pre = qu[pre.last];
						return;
					}
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {
		int nx = to.x + step[i][0];
		int ny = to.y + step[i][1];
		if (is_inner_and_nocrash(to, nx, ny, player) && player->mat[nx][ny] == '.') {
			pre.x = nx;
			pre.y = ny;
			return;
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
	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			vis[i][j].head = -1;
			memset(vis[i][j].sta, 0, sizeof(vis[i][j].sta));
		}
	}
	BFS(player);
	//printf("\npre(%d,%d)\n", pre.x, pre.y);
	if (pre.x != -1 && pre.y != -1) {
		for (i = 0; i < 4; i++) {
			int x = pre.x + step[i][0];
			int y = pre.y + step[i][1];
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
		return initPoint(pre.x, pre.y);
	}
	if (player->round >= 3 * (player->col_cnt + player->row_cnt) / 8 + 1)
		lenth--;
	return initPoint(player->your_posx, player->your_posy);
}