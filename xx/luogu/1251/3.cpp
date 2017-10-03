#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define INF 1e9
#define N 100005
#define M 200005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll ans;
bool vis[N];
int n,a,b,f,fa,fb,s,t;
int dist[N];
int cnt = 1,p[M],c[M],cc[M],nxt[N],head[N];

inline void insert(int x,int y,int z,int zz){
	p[++cnt] = y; c[cnt] = z; cc[cnt] = zz;
	nxt[cnt] = head[x]; head[x] = cnt;
}

bool spfa(int s,int t){
	memset(vis,0,sizeof vis); vis[t] = 1;
	for(int i = s;i <= t;i++) dist[i] = INF;
	dist[t] = 0;
	deque<int> q; q.push_back(t);
	while(!q.empty()){
		int now = q.front(); q.pop_front();
		for(int k = head[now];k;k = nxt[k])
			if(c[k^1] && dist[p[k]] > dist[now]-cc[k]){
				dist[p[k]] = dist[now] - cc[k];
				if(!vis[p[k]]){
					vis[p[k]] = 1;
					if(!q.empty() && dist[p[k]] < dist[q.front()])
						q.push_front(p[k]);
					else q.push_back(p[k]);
				}
			}
		vis[now] = 0;
	}
	return dist[s] < INF;
}

int dfs(int x,int low){
	vis[x] = 1;
	if(x == t) return low;
	int a,used = 0;
	for(int k = head[x];k;k = nxt[k])
		if(!vis[p[k]] && c[k] && dist[p[k]] == dist[x]-cc[k]){
			a = dfs(p[k],min(low-used,c[k]));
			if(a){
				c[k] -= a; c[k^1] += a;
				used += a; ans += (ll)a*cc[k];
			}
			if(used == low) break;
		}
	return used;
}

int costflow(){
	int flow = 0;
	while(spfa(s,t)){
		vis[t] = 1;
		while(vis[t]){
			memset(vis,0,sizeof vis);
			flow += dfs(s,INF);
		}
	}
	return flow;
}

int main(){
	n = read(); s = 0; t = 2*n+1;
	for(int i = 1;i <= n;i++){
		int x = read();
		insert(s,i,x,0); insert(i,s,0,0);
		insert(i+n,t,x,0); insert(t,n+i,0,0);
	}
	f = read();
	a = read(); fa = read();
	b = read(); fb = read();
	for(int i = 1;i <= n;i++){
		insert(s,i+n,INF,f); insert(i+n,s,0,-f);
		if(i < n) insert(i+n,i+n+1,INF,0),insert(i+n+1,i+n,0,0);
		if(i+a <= n) insert(i,i+n+a,INF,fa),insert(i+n+a,i,0,-fa);
		if(i+b <= n) insert(i,i+n+b,INF,fb),insert(i+n+b,i,0,-fb);
	}
	costflow(); printf("%lld\n",ans);
	return 0;
}
