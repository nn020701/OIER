#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 602
#define M 360002
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

struct edge{
	int u,v,w;
}e[M<<2];
int f[M],rank[M],cnt[M],ask_sum[M];
int n,m,K,tot,nm,en;
int a[N][N],num[N][N],b[M];
ll ans;

bool cmp(edge a,edge b){
	return a.w < b.w;
}

int getf(int x){
	if(x == f[x]) return x;
	f[x] = getf(f[x]);
	return f[x];
}

void Union(int u,int v){
	if(rank[u] < rank[v]){
		f[u] = v;
		cnt[v] += cnt[u];
		ask_sum[v] += ask_sum[u];
	}
	else{
		f[v] = u;
		cnt[u] += cnt[v];
		ask_sum[u] +=ask_sum[v];
		if(rank[u] == rank[v]) rank[u]++;
	}
}

int main(){
	n = read(); m = read(); K = read(); nm = n*m;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			a[i][j] = read();
			num[i][j] = ++en;
		}
	en = 0;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			b[num[i][j]] = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			if(i != n) e[++en] = (edge){num[i][j],num[i+1][j],abs(a[i][j]-a[i+1][j])};
			if(j != m) e[++en] = (edge){num[i][j],num[i][j+1],abs(a[i][j]-a[i][j+1])};
		}
	sort(e+1,e+en+1,cmp);
	for(int i = 1;i <= nm;i++){
		f[i] = i;
		cnt[i] = 1;
		ask_sum[i] = b[i];
	}
	for(int i = 1;i <= en;i++){
		int fa = getf(e[i].u),fb = getf(e[i].v);
		if(fa != fb){
			if(cnt[fa]+cnt[fb] >= K){
				if(cnt[fa] < K) ans += ((ll)e[i].w*(ll)ask_sum[fa]);
				if(cnt[fb] < K) ans += ((ll)e[i].w*(ll)ask_sum[fb]);
			}
			Union(fa,fb); tot++;
			if(tot == nm-1) break;
		}
	}
	printf("%lld\n",ans);
	return 0;
}
