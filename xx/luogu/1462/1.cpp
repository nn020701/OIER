#include<cstdio>
#include<queue>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define M 100005
#define N 10005
#define INF 1000000005
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,b;
int f[N];
int head[N],nxt[M],to[M],cost[M],cnt;
int dist[N];
bool vis[N];
int ans = -1;

void add_edge(int a,int b,int v){
	to[++cnt] = b; nxt[cnt] = head[a]; head[a] = cnt; cost[cnt] = v;
	to[++cnt] = a; nxt[cnt] = head[b]; head[b] = cnt; cost[cnt] = v;
}

bool spfa(int w){
	queue<int> q;
	q.push(1);
	for(int i = 1;i <= n;++i)
		dist[i] = INF;
	dist[1] = 0;
	memset(vis,false,sizeof vis);
	while(!q.empty()){
		int u = q.front(); q.pop();
		vis[u] = false;
		for(int i = head[u];i;i = nxt[i])
			if(f[to[i]] <= w)
				if(dist[to[i]] > dist[u]+cost[i]){
					dist[to[i]] = dist[u]+cost[i];
					if(vis[to[i]])
						continue;
					q.push(to[i]);
					vis[to[i]] = true;
				}
	}
	if(dist[n] <= b) return true;
	return false;
}

int main(){
	n = read(); m = read(); b = read();
	for(int i = 1;i <= n;++i)
		f[i] = read();
	for(int i = 1;i <= m;++i){
		int a = read(),b = read(),v = read();
		add_edge(a,b,v);
	}
	int l = 1,r = 1000000000,mid;
	while(l <= r){
		mid = (l+r)>>1;
		if(spfa(mid)){
			ans = mid;
			r = mid-1;
		}
		else l = mid+1;
	}
	if(ans == -1) 
		printf("AFK\n");
	else
		printf("%d\n", ans);
	return 0;
}