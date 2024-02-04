#include "state.h"
#include<string.h>

int eid=1,pq[MAXN],d[MAXN],visit[MAXN],pre[MAXN],help[N][N];
int idx=0;  
int dir[6][2]={{8,0},{-8,0},{-4,8},{4,8},{-4,-8},{4,-8}};
int check(int x,int y,struct PNG *p)
{
    return x>=4&&x<=p->width-4&&y>=6&&y<=p->height-6;
}

void insert(struct State *s,int u,int v,int w)
{
    edge t={v,pq[u],1,w};
    s->e[eid]=t;
    pq[u]=eid++;
}

int weight(dot a,struct PNG *p)
{
    struct PXL * p1=get_PXL(p,a.x,a.y);
    int c=255*255*3-(p1->red)*(p1->red)-(p1->green)*(p1->green)-(p1->blue)*(p1->blue);
    return c;
}

void fun1(struct State *s,struct PNG *p)
{
    int m,i=1; 
    m=p->height%16;
    if(m==5) m=p->height/16*2;
    else m=p->height/16*2+1;
    int py=6,ex,ey;
    for(int j=1;j<=m;j++)
    {
        if(j%2==1){
            ex=4;
            ey=py+8*(j-1);
        }
        else if(j%2==0){
            ex=8;
            ey=py+8*(j-1);
        }
        while(1){
            if(check(ex,ey,p)){ 
                help[ex][ey]=i;
                s->point[i++]={ex,ey};
                ex=ex+8;
            }
            else break;
        }
    }
    idx=i-1;
    s->n=idx;
}

void fun2(struct State *s,struct PNG *p)
{
    int j=1,g=0;
    memset(pq,-1,sizeof(pq));
    for(j=1;j<=idx;j++)
    {
        dot t=s->point[j];
        for(int i1=0;i1<6;i1++)
        {
            t=s->point[j];
            t.x=t.x+dir[i1][0];
            t.y=t.y+dir[i1][1];
            if(!check(t.x,t.y,p)) continue;
            g=help[t.x][t.y];
            insert(s,j,g,weight(s->point[g],p));
        }
    } 
}

void changef1(struct State *s, int u, int v, int t) {
	int i = pq[u];
	while (s->e[i].v != v)
		i = s->e[i].next;
	s->e[i].f = t;
}

void changef2(struct State *s, int u, int v, int t) {
	changef1(s, u, v, t);
	changef1(s, v, u, t);
}

void Dijkstra(struct State *s) {
	d[1] = 0;
	for (int i = 0; i < s->n; i++) {
		int mind = infi;
		int u = 0;
		for (int j = 1; j <= s->n; j++) {
			if (visit[j] == 0 && d[j] < mind) {
				mind = d[j];
				u = j;
			}
		}
		if (mind == infi)
			break;
		visit[u] = 1;
		for (int j = pq[u]; j != -1; j = s->e[j].next) {
			int v = s->e[j].v;
			if (s->e[j].f && d[v] > d[u] + s->e[j].w && visit[v] == 0) {
				d[v] = d[u] + s->e[j].w;
			}
		}
	}
}

void Dijkstra1(struct State *s) {
	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= s->n; i++)
		d[i] = infi;
	Dijkstra(s);
}

void init_State(struct State *s) {
    s->n=0;
    s->alle=0;
}
void delete_State(struct State *s) {
    ;
}
void parse(struct State *s, struct PNG *p) {
    fun1(s,p);
    fun2(s,p);
}
long long solve1(struct State *s) {
	    memset(pre,-1,sizeof(pre));
    	memset(visit, 0, sizeof(visit));
	for (int i = 1; i <= s->n; i++)
		d[i] = infi;
    	d[1] = 0;
	for (int i = 0; i < s->n; i++) {
		int mind = infi;
		int u = 0;
		for (int j = 1; j <= s->n; j++) {
			if (visit[j] == 0 && d[j] < mind) {
				mind = d[j];
				u = j;
			}
		}
		if (mind == infi)
			break;
		visit[u] = 1;
		for (int j = pq[u]; j != -1; j = s->e[j].next) {
			int v = s->e[j].v;
			if (s->e[j].f && d[v] > d[u] + s->e[j].w && visit[v] == 0) {
				d[v] = d[u] + s->e[j].w;
				pre[v]=u;
			}
		}
	}
	return d[idx];
}
long long solve2(struct State *s) {
    long long min=d[idx];
   	int x = idx;
	int p = infi;
	while (pre[x] != -1) {
		changef2(s, x, pre[x], 0);
		Dijkstra1(s);
		int p2 = d[idx];
		changef2(s, x, pre[x], 1);
		if (p2 < p&&min<p2)
			p = p2;
		x = pre[x];
	}
	if (p == infi)
		return min;
	else if(p>min)
        return p;
}