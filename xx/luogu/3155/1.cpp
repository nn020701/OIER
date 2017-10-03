#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 10005
inline int read(){
	char ch=getchar(); int x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

int n,m;
int color[N];
int w[N],b[N],q[N];
int f[N];
int nxt[N*2],to[N*2],head[N],cnt;

void add_edge(int u,int v){
	to[++cnt] = v; nxt[cnt] = head[u]; head[u] = cnt;
	to[++cnt] = u; nxt[cnt] = head[v]; head[v] = cnt;
}

void dfs1(int x,int fa){
	if(x <= m){
		if(color[x] == 1)
			w[x] = 1;
		else b[x] = 1;
		return;
	}
	for(int i = head[x];i;i = nxt[i])
		if(to[i] != fa){
			dfs1(to[i],x);
			if(color[to[i]] == -1) q[x]++;
			else if(color[to[i]] == 1) w[x]++;
			else b[x]++;
			f[x] += f[to[i]];
		}
	if(b[x] > w[x]){
		color[x] = 0;
		f[x] -= b[x]+q[x]-1;
	}
	else if(b[x] < w[x]){
		color[x] = 1;
		f[x] -= w[x]+q[x]-1;
	}
	else{
		color[x] = -1;
		f[x] -= w[x]+q[x]-1;
	}
}

int main(){
	n = read(); m = read();
	for(int i = 1;i <= m;++i){
		f[i] = 1;
		color[i] = read();
	}
	for(int i = 1;i < n;++i){
		int a = read(),b = read();
		add_edge(a,b);
	}
	memset(b,0,sizeof b);
	memset(w,0,sizeof w);
	dfs1(m+1,0);
	// for(int i = 1;i <= n;++i){
	// 	printf("%d %d %d %d %d\n",w[i],b[i],q[i],color[i],f[i]);
	// }
	printf("%d\n",f[m+1]);
	return 0;
}