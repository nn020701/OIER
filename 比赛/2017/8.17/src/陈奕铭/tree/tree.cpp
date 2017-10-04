#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 400005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

int n,logn;
int bei2[21] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192,16384,32768,65536,131072,262144,524288,1048576};
int f[21][N],Max[21][N];
int to[N],nxt[N],w[N],head[N],cnt;
int heap[N];
bool vis[N];

void insert(int a,int b,int c){
	to[++cnt] = b; nxt[cnt] = head[a]; head[a] = cnt; w[cnt] = c;
	to[++cnt] = a; nxt[cnt] = head[b]; head[b] = cnt; w[cnt] = c;
}

void dfs(int x,int fa){
	for(int i = head[x];i;i = nxt[i])
		if(to[i] != fa){
			f[0][to[i]] = x;
			Max[0][to[i]] = w[i];
			heap[to[i]] = heap[x]+1;
			dfs(to[i],x);
		}
	return;
}

void zhunbei(){
	for(int j = 1;j <= logn;j++)
		for(int i = 1;i <= n;i++){
			f[j][i] = f[j-1][f[j-1][i]];
			Max[j][i] = max(Max[j-1][i],Max[j-1][f[j-1][i]]);
		}
}

int lca(int u,int v){		//AC 
	if(heap[u] > heap[v]) swap(u,v);
	int k = heap[v]-heap[u];
	for(int i = 0;(1<<i) <= k;i++)
		if((1<<i) & k)
			v = f[i][v];
	if(u != v){
		for(int i = logn;i >= 0;i--)
			if(f[i][u] != f[i][v]){
				u = f[i][u];
				v = f[i][v];
			}
		u = f[0][u];
	}
	return u;
}

int solve(int u,int v){				//AC
	int ans = 0;
	if(heap[u] > heap[v]) swap(u,v);
	for(int i = logn;i >= 0;i--){
		if(heap[u] <= heap[f[i][v]]){
			ans = max(Max[i][v],ans);
			v = f[i][v];
		}
	}
	return ans;
}

int jisuan(int a,int u,int v){
	int ans = 0;
	int ca=lca(u,v);
	int caa=lca(ca,a);
	if(caa == a)
		ans = solve(ca,a);
	else{
		if(caa != ca)
			ans = max(solve(ca,caa),solve(a,caa));
		else
			ans = min(min(solve(a,lca(a,ca)),solve(a,lca(a,u))),solve(a,lca(a,v)));
	}
//	printf("%d %d %d\n",Max1,Max2,Max3);
	return ans;
}

void add(int u,int v,int c){
	f[0][u] = v;
	Max[0][u] = c;
	heap[u] = heap[v]+1;
	for(int j = 1;j <= logn;j++){
		f[j][u] = f[j-1][f[j-1][u]];
		Max[j][u] = max(Max[j-1][u],Max[j-1][f[j-1][u]]);
	}
}

int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n = read(); int q = read();
	logn = 20;
//	printf("%d\n",logn);
	for(int i = 1;i < n;i++){
		int a = read(),b = read(),c = read();
		insert(a,b,c);
	}
	f[0][1] = 1;
	heap[1] = 1;
	dfs(1,1);
	zhunbei();
	int ans = 0;
/*	while(q--){
		int a = read(),b = read();
		printf("%d\n",lca(a,b));
	}*/
	while(q--){
		int opt = read();
		if(opt == 1){
			int a = read()^ans;
			int u = read()^ans;
			int v = read()^ans;
			ans = jisuan(a,u,v);
			printf("%d\n",ans);
		}
		else{
			int a = read()^ans;
			int b = read()^ans;
			n++;
			add(n,a,b);
		}
	}
	return 0;
}
