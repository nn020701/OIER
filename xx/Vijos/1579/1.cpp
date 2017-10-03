#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 20005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n;
ll ans;
int node[N],f[N];
struct edge{
	int u,v,w;
}e[N];

inline bool cmp(edge a,edge b){
	return a.w < b.w;
}

inline int getf(int x){
	if(x == f[x]) return x;
	return f[x] = getf(f[x]);
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		node[i] = 1,f[i] = i;
	for(int i = 1;i < n;i++){
		e[i].u = read(); e[i].v = read();
		e[i].w = read(); ans += e[i].w;
	}
	sort(e+1,e+n,cmp);
	for(int i = 1;i < n;i++){
		// printf("%lld\n",ans);
		int x = getf(e[i].u);
		int y = getf(e[i].v);
		ans += (ll)(node[x]*node[y]-1)*(ll)(e[i].w+1);
		f[x] = y;
		node[y] = node[x]+node[y];
	}
	printf("%lld\n",ans);
	return 0;
}