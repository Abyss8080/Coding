#ifndef STATE_H_
#define STATE_H_
#include "suan_png.h"
#include "pxl.h"
#include<malloc.h>
#define MAXN 3000
#define infi 0x3f3f3f3f
#define N 600
typedef struct 
{
    int x,y;
}dot;
typedef struct
{
    int v,next,f,w;
}edge;
struct State {
    dot point[MAXN];
    edge e[MAXN*MAXN];
    int n,alle;
    // data structure
};
/*struct State *s;
int eid,pq[MAXN],d[MAXN],visit[MAXN],pre[MAXN];
int idx=0;  //终点序号
int dir[6][2]={{8,0},{-8,0},{8,4},{-8,4},{-8,-4},{8,-4}};*/
int check(int x,int y,struct PNG *p);
void insert(int u,int v,double w);
int weight(dot a);
void fun1(struct State *s,struct PNG *p);
void fun2(struct State *s,struct PNG *p);
void init_State(struct State *s);
void delete_State(struct State *s);
void assign(struct State *a, struct State *b);
void parse(struct State *s, struct PNG *p);
long long solve1(struct State *s);
long long solve2(struct State *s);

#endif