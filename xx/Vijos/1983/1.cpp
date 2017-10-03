#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define lowbit(x) (x&(-x))
#define N 300005
#define INF 1e9
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int f[20][N],deep[N],dist[20][N];
int to[N*2],nxt[N*2],head[N],w[N*2],cnt;
int a[N],Scarlet[N];
int n,m,mid,tot;
bool flag;
int Maxw;
struct path{
	int a,b,len,lca;
}p[N];

void insert(int u,int v,int x){
	to[++cnt] = v; nxt[cnt] = head[u]; head[u] = cnt; w[cnt] = x;
	to[++cnt] = u; nxt[cnt] = head[v]; head[v] = cnt; w[cnt] = x;
}

void dfs(int x,int fa){
	for(int i = head[x];i;i = nxt[i])
		if(to[i] != fa){
			f[0][to[i]] = x;
			dist[0][to[i]] = w[i];
			deep[to[i]] = deep[x]+1;
			dfs(to[i],x);
		}
}

void doublemodify(){
	for(int j = 1;j <= 19;j++)
		for(int i = 1;i <= n;i++){
			f[j][i] = f[j-1][f[j-1][i]];
			dist[j][i] = dist[j-1][i]+dist[j-1][f[j-1][i]];
		}
}

void lca(int u,int v,int x){
	if(deep[u] > deep[v]) swap(u,v);
	int len = 0;
	int dep = deep[v] - deep[u];
	for(int i = 19;i >= 0;i--)
		if(dep & (1<<i)){
			len += dist[i][v];
			v = f[i][v];
		}
	if(v == u){
		p[x].len = len;
		p[x].lca = v;
		return;
	}
	for(int i = 19;i >= 0;i--)
		if(f[i][u] != f[i][v]){
			len += dist[i][u] + dist[i][v];
			u = f[i][u];
			v = f[i][v];
		}
	len += dist[0][u]+dist[0][v];
	u = f[0][u];
	p[x].lca = u;
	p[x].len = len;
	return;
}

bool cmp(path a,path b){
	return a.len > b.len;
}

int Dfs(int x,int f){
	int num = 0;
	for(int i = head[x];i;i = nxt[i])
		if(flag) return num;
		else if(to[i] != f)
			num += Dfs(to[i],x);
	num += a[x];
	if(num == tot && Maxw - dist[0][x] <= mid)
		flag = true;
	return num;
}

bool check(){
	tot = 1;
	memset(a,0,sizeof a);
	while(p[tot].len > mid){
		a[p[tot].lca] -= 2;
		a[p[tot].a]++;
		a[p[tot].b]++;
		tot++;
	}
	tot--;
	if(tot == 0) return true;
	flag = false;
	Dfs(1,1);
	return flag;
}

int main(){
	n = read(); m = read();
	for(int i = 1;i < n;i++){
		int u = read(),v = read(),x = read();
		insert(u,v,x);
	}
	deep[1] = 1;
	f[0][1] = 1;
	dist[0][1] = 0;
	dfs(1,1);
	doublemodify();
	for(int i = 1;i <= m;i++){
		p[i].a = read(); p[i].b = read();
		lca(p[i].a,p[i].b,i);
		Maxw = max(Maxw,p[i].len);
	}
	sort(p+1,p+m+1,cmp);
	int l = 0,r = Maxw;
	while(l < r){
		mid = (l+r) >> 1;
		if(check()) r = mid;
		else l = mid+1;
	}
	printf("%d\n",l);
	return 0;
}