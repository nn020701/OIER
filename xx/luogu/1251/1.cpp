#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 2005
#define M 1000005
#define INF 1000000000
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,p,fn,fp,sn,sp,r[N],s,t;
struct edge{
	int v,nxt,c,f,w;
}e[M<<1];
int cnt,h[N];

void insert(int u,int v,int c,int w){
	e[++cnt].v = v; e[cnt].c = c; e[cnt].f = 0; e[cnt].w = w;
	e[cnt].nxt = h[u]; h[u] = cnt;
	e[++cnt].v = u; e[cnt].c = 0; e[cnt].f = 0; e[cnt].w = -w; 
	e[cnt].nxt = h[v]; h[v] = cnt;
}

void build(){
	s = 0; t = n*2+1;
	for(int i = 1;i <= n;i++){
		insert(s,i,r[i],0);
		insert(i+n,t,r[i],0);
		insert(s,i+n,INF,p);
		if(i+1 <= n) insert(i,i+1,INF,0);
		if(i+fn <= n) insert(i,i+n+fn,INF,fp);
		if(i+sn <= n) insert(i,i+n+sn,INF,sp);
	}
}

int d[N],q[N],head,tail,inq[N],pre[N],pos[N];

void lop(int &x){
	if(x == N) x = 1;
	else if(x == 0) x == N-1;
}

bool spfa(){
	memset(d,127,sizeof d);
	memset(inq,0,sizeof inq);
	head = tail = 1;
	d[s] = 0; inq[s] = 1; q[tail++] = s;
	pre[t] = -1;
	while(head != tail){
		int u = q[head++]; inq[u] = 0; lop(head);
		for(int i = h[u];i;i = e[i].nxt){
			int v = e[i].v,w = e[i].w;
			if(d[v] > d[u]+w && e[i].c > e[i].f){
				d[v] = d[u]+w;
				pre[v] = u; pos[v] = i;
				if(!inq[v]){
					inq[v] = 1;
					if(d[v] < d[q[head]]){
						head--; lop(head);
						q[head] = v;
					}
					else{
						q[tail++] = v; lop(tail);
					}
				}
			}
		}
	}
	return pre[t] != -1;
}

int mcmf(){
	int flow = 0,cost = 0;
	while(spfa()){
		int f = INF;
		for(int i = t;i != s;i = pre[i]) f = min(f,e[pos[i]].c-e[pos[i]].f);
		flow += f; cost += d[t]*f;
		for(int i = t;i != s;i = pre[i]){
			e[pos[i]].f += f;
			e[((pos[i]-1)^1)+1].f -= f;
		}
	}
	return cost;
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++) r[i] = read();
	p = read();
	fn = read(); fp = read();
	sn = read(); sp = read();
	build();
	printf("%d",mcmf());
	return 0;
}
