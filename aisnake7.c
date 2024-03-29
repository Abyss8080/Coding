/**
 * @file player.h
 * @author yangboyang@jisuanke.com
 * @copyright jisuanke.com
 * @date 2021-07-01
 */

#include <string.h>
#include "../include/playerbase.h"
#include <stdio.h>
#define MAX 500

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

int lenth, tailnum, hasget;
St pre;
struct Point tail;
int step[4][2] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1}};
Status possta;
int vis[10][10], vs[10][10];

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
	for (int i = now.sta.head; i > now.sta.head - now.len ; i--) {
		xb = xb + step[now.sta.sta[i]][0];
		yb = yb + step[now.sta.sta[i]][1];
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
		else if (player->mat[nx][ny] == '#'
		         || (player->mat[nx][ny] == '1' && nx != player->your_posx && ny != player->your_posy)
		         || (player->mat[nx][ny] == '2' && nx != player->opponent_posx && ny != player->opponent_posy))
			count++;
	}
	if (count >= 3)
		return 0;
	return 1;
}

int shrink(struct Player *player, int nx, int ny) {
	int shrink_count = player->round / 40;//已缩圈的次数
	if (player->round_to_shrink <= 2
	        && ((nx == shrink_count || nx == player->row_cnt - shrink_count - 1)
	            || (ny == shrink_count || ny == player->col_cnt - shrink_count - 1))) {
		return 0;
	}
	return 1;
}

int dfs(struct Player *player, int x, int y, int steps) {
	if (steps >= 3) {
		return 1;
	}
	for (int i = 0; i < 4; i++) {
		int xx = x + step[i][0];
		int yy = y + step[i][1];
		if (in(xx, yy, player)
		        && (player->mat[xx][yy] == '.'
		            || player->mat[xx][yy] == 'o'
		            || player->mat[xx][yy] == 'O'
		            || (player->mat[xx][yy] == '1' && xx == tail.X && yy == tail.Y))
		        && !vs[xx][yy]) {
			vs[xx][yy] = 1;
			int flag = dfs(player, xx, yy, steps + 1);
			vs[xx][yy] = 0;
			if (flag == 1)
				return 1;
		}
	}
	return 0;
}

int is_access(struct Player *player, int nx, int ny) {
	memset(vs, 0, sizeof(vs));
	vs[nx][ny] = 1;
	return dfs(player, nx, ny, 0);
}

void ChangeTail(void) {
	int num = possta.head - lenth + 2;
	if (num != tailnum) {
		tailnum = num;
		tail.X = tail.X - step[possta.sta[tailnum]][0];
		tail.Y = tail.Y - step[possta.sta[tailnum]][1];
	}
}

int Suicide(struct Player *player) {
	if (lenth == 1)
		return 0;
	int count = 0;
	for (int i = 0; i < 4; i++) {
		int nx = player->your_posx + step[i][0];
		int ny = player->your_posy + step[i][1];
		if (!in(nx, ny, player))
			count++;
		else if (player->mat[nx][ny] == '#'
		         || (player->mat[nx][ny] == '1' && nx != tail.X && ny != tail.Y))
			count++;
	}
	if (count == 4)
		return 1;
	return 0;
}

void BFS(struct Player *player) {
	int i,j;
	St qu[MAX];
	int l, r;
	l = r = 0;
	int x = player->your_posx;
	int y = player->your_posy;
	St to = {x, y, 0, possta, -1, lenth};
	qu[r++] = to;
	vis[x][y] = 1;
	while (l < r) {
		St now = qu[l++];
		x = now.x;
		y = now.y;
		for (i = 0; i < 4; i++) {
			int nx = x - step[i][0];
			int ny = y - step[i][1];
			if (is_inner_and_nocrash(now, nx, ny, player)
			        && (player->mat[nx][ny] == '.'
			            || player->mat[nx][ny] == 'o'
			            || player->mat[nx][ny] == 'O'
			        || (player->mat[nx][ny] == '1' && nx == tail.X && ny == tail.Y))) {
				Status nextsta;
				for (j = 0; j <= now.sta.head; j++)
					nextsta.sta[j] = now.sta.sta[j];
				nextsta.head = now.sta.head;
				nextsta.head++;
				nextsta.sta[nextsta.head] = i; //如果要走，下一步更新的status
				St next = {nx, ny, now.step + 1, nextsta, l - 1, now.len};
				if (lenth + now.step < 3 * (player->col_cnt + player->row_cnt) / 8 + 1)
					next.len += 1;
				if (!vis[nx][ny]) {
					vis[nx][ny] = 1;
					qu[r++] = next;
					if ((player->mat[nx][ny] == 'o' || player->mat[nx][ny] == 'O')
					        && Judge(nx, ny, player)) {
						pre = next;
						while (qu[pre.last].last != -1)
							pre = qu[pre.last];
						if (!shrink(player, pre.x, pre.y) || !is_access(player, pre.x, pre.y)) {
							continue;
						}
						return;
					}
				}
			}
		}
	}
	for (i = 0; i < 4; i++) {
		int nx = to.x + step[i][0];
		int ny = to.y + step[i][1];
		if (is_inner_and_nocrash(to, nx, ny, player)
		        && ( player->mat[nx][ny] == '.' || (player->mat[nx][ny] == '1' && nx == tail.X && ny == tail.Y))
		        && shrink(player, nx, ny) && Judge(nx, ny, player)) {
			pre.x = nx;
			pre.y = ny;
			return;
		}
	}
}

void init(struct Player *player) {
	lenth = 1;
	possta.head = -1;
	tailnum = -1;
	tail.X = player->your_posx;
	tail.Y = player->your_posy;
	hasget = 0;
	// This function will be executed at the begin of each game, only once.
}

struct Point walk(struct Player *player) {
	// This function will be executed in each round.
	int i;
	pre.x = pre.y = -1;
	memset(vis, 0, sizeof(vis));
	if (player->round / 40 >= 2) {
		int is_suicide = Suicide(player);
		if (is_suicide)
			return initPoint(player->your_posx, player->your_posy);
	}
	BFS(player);
	if (pre.x != -1 && pre.y != -1) {
		for (i = 0; i < 4; i++) {
			int x = pre.x + step[i][0];
			int y = pre.y + step[i][1];
			if (x == player->your_posx && y == player->your_posy)
				break;
		}
		possta.head++;
		possta.sta[possta.head] = i;
		if (player->mat[pre.x][pre.y] == 'o'
		        && player->mat[pre.x][pre.y] == 'O'
		        && player->round < 3 * (player->col_cnt + player->row_cnt) / 8 + 1) //如果在增长基础长度的回合里吃到了道具
			hasget++;
		if (player->round < 3 * (player->col_cnt + player->row_cnt) / 8 + 1 || hasget > 0) {
			lenth++;
			if (player->round >= 3 * (player->col_cnt + player->row_cnt) / 8 + 1 && hasget > 0)
				hasget--;
		}
		ChangeTail();
		return initPoint(pre.x, pre.y);
	}
	if (player->round >= 3 * (player->col_cnt + player->row_cnt) / 8 + 1 && hasget <= 0)
		lenth--;
	ChangeTail();
	return initPoint(player->your_posx, player->your_posy);
}
