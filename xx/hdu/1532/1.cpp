#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define INF 1e9
#define N 205
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int head[N],to[N<<1],nxt[N<<1],cap[N<<1],cnt;
//cap是指流量 
bool used[N];

inline void insert(int _from,int _to,int _cap){
	to[++cnt] = _to; cap[cnt] = _cap; nxt[cnt] = head[_from]; head[_from] = cnt;
	to[++cnt] = _from; cap[cnt] = 0; nxt[cnt] = head[_to]; head[_to] = cnt;
}

int dfs(int s,int t,int f){
	if(s == t) return f;
	used[s] = true;
	for(int i = head[s];i;i = nxt[i]){
		if(!used[to[i]] && cap[i] > 0){
			int d = dfs(to[i],t,min(f,cap[i]));
			if(d > 0){
				cap[i] -= d;
				cap[i^1] += d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t){
	int flow = 0;
	for(;;){
		memset(used,false,sizeof used);
		int f = dfs(s,t,INF);
		if(f == 0) return flow;
		flow += f;
	}
}

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		memset(head,0,sizeof head);
		cnt = 1;
		for(int i = 0;i < n;i++){
			int x = read(),y = read(),z = read();
			insert(x,y,z);
		}
		printf("%d\n",max_flow(1,m));
	}
	return 0;
}
