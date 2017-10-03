#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n,m;
vector<int> son[N];
int dis[N];
int f[N][11];

void dfs(int x,int fa){
	f[x][0] = fa;
	dis[x] = dis[fa]+1;
	for(int i = 0;i < son[x].size();i++)
		dfs(son[x][i],x);
	return;
}

void zun(){
	for(int j = 1;j <= 10;j++)
		for(int i = 1;i <= n;i++)
			f[i][j] = f[f[i][j-1]][j-1];
}

int lca(int u,int v){
	if(dis[u] > dis[v]) swap(u,v);
	int dep = dis[v]-dis[u];
	for(int j = 0;j <= 10;j++,dep >>= 1)
		if(dep&1)
			v = f[v][j];
//	printf("@ %d %d %d %d\n",dis[u],dis[v],u,v);
	if(u == v) return u;
	for(int j = 10;j >= 0;j--)
		if(f[u][j] != f[v][j]){
			u = f[u][j];
			v = f[v][j];
		}
	u = f[u][0];
	return u;
}

int main(){
	n = read(); m = read();
	for(int i = 2;i <= n;i++){
//		printf("# %d\n",i);
		int x = read();
		son[x].push_back(i);
	}
	dis[1] = 0;
//	puts("1");
	dfs(1,1);
//	puts("1");
	zun();
//	puts("1");
	for(int i = 1;i <= m;i++){
//		printf("& %d\n",i);
		int a = read(),b = read();
		printf("%d\n",lca(a,b));
	}
	return 0;
} 
