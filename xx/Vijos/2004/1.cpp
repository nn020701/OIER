#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 300005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n,m;
int head[N],nxt[N*2],to[N*2],cnt;
int f[20][N],deep[N],ans[N],val[N],tong[N],Maxdeep,w[N],num[N*3];
struct node{
	int s,t,lca,len;
}a[N];
vector<int> scarlet[N],scarlet1[N],scarlet2[N];

inline void insert(int u,int v){
	to[++cnt] = v; nxt[cnt] = head[u]; head[u] = cnt;
	to[++cnt] = u; nxt[cnt] = head[v]; head[v] = cnt;
}

inline void dfs_first(int x,int fa){
	for(int i = head[x];i;i = nxt[i])
		if(to[i] != fa){
			deep[to[i]] = deep[x]+1;
			f[0][to[i]] = x;
			dfs_first(to[i],x);
		}
}

inline void plan(){
	for(int i = 1;i <= n;i++)
		Maxdeep = max(Maxdeep,deep[i]);
	for(int j = 1;j <= 19;j++)
		for(int i = 1;i <= n;i++)
			f[j][i] = f[j-1][f[j-1][i]];
}

inline int lca(int u,int v){
	if(deep[u] > deep[v]) swap(u,v);
	int dep = deep[v] - deep[u];
	for(int i = 19;i >= 0;i--)
		if(dep & (1 << i))
			v = f[i][v];
	if(u == v) return v;
	for(int i = 19;i >= 0;i--)
		if(f[i][u] != f[i][v]){
			u = f[i][u];
			v = f[i][v];
		}
	u = f[0][u];
	return u;
}

inline void dfs(int x,int fa){
	int now = w[x]+deep[x],cun = 0;
	if(now <= Maxdeep) cun = tong[now];
	for(int i = head[x];i;i = nxt[i])
		if(to[i] != fa)
			dfs(to[i],x);
	tong[deep[x]] += val[x];
	if(now <= Maxdeep) ans[x] = tong[now] - cun;
	for(int i = 0,l = scarlet[x].size();i < l;i++)
		tong[deep[scarlet[x][i]]]--;
		//因为之后是往上回溯，之后就走不到观察点了，就将此点为终点的路径起点当时所加的都减去。
		//因为我们都是直接用这个深度的值，所以也要减原先深度的值。
}

inline void DFS(int x,int fa){
	int now = deep[x] - w[x],cun;
	now += 300000; cun = num[now];
	for(int i = head[x];i;i = nxt[i])
		if(to[i] != fa)
			DFS(to[i],x);
	for(int i = 0,l = scarlet1[x].size();i < l;i++)
		num[300000+scarlet1[x][i]]++;
	ans[x] += num[now]-cun;
	for(int i = 0,l = scarlet2[x].size();i < l;i++)
		num[300000+scarlet2[x][i]]--;
}

int main(){
	n = read(); m = read();
	for(int i = 1;i < n;i++){
		int x = read(),y = read();
		insert(x,y);
	}
	for(int i = 1;i <= n;i++) w[i] = read();
	deep[1] = 1;
	f[0][1] = 1;
	dfs_first(1,0);
	plan();
	for(int i = 1;i <= m;i++){
		a[i].s = read(); a[i].t = read(); val[a[i].s]++;
		a[i].lca = lca(a[i].s,a[i].t);
		a[i].len = deep[a[i].s] + deep[a[i].t] - 2 * deep[a[i].lca];	//路径长度
		scarlet[a[i].lca].push_back(a[i].s);		//存下以a[i].lca为终点的路径起点有哪些
	}
	dfs(1,0);
	for(int i = 1;i <= m;i++){
		scarlet1[a[i].t].push_back(deep[a[i].t] - a[i].len);		//其实是和上面一样的，基本不用解释了
		scarlet2[a[i].lca].push_back(deep[a[i].t] - a[i].len);
	}
	DFS(1,0);
	for(int i = 1;i <= m;i++)
		if(deep[a[i].s]-deep[a[i].lca] == w[a[i].lca])
			ans[a[i].lca]--;
	for(int i = 1;i <= n;i++)
		printf("%d ",ans[i]);
	return 0;
}