#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 100005
#define M 300005

inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}
inline ll readll(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n,m,cnt;
int f[N];
ll ans;
struct node{
	ll x;
	int num;
	friend bool operator <(node a,node b){
		return a.x < b.x || (a.x == b.x && a.num < b.num);
	}
}a[N],b[N],c[N];
struct edge{
	ll x;
	int u,v;
	friend bool operator <(edge a,edge b){
		return a.x < b.x;
	}
}e[M];

int getf(int x){
	if(x == f[x])
		return x;
	return f[x] = getf(f[x]);
}

int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	n = read();
	for(int i = 1;i <= n;i++){
		a[i].x = readll();
		b[i].x = readll();
		c[i].x = readll();
		a[i].num = b[i].num = c[i].num = i;
	}
	sort(a+1,a+n+1);
	sort(b+1,b+n+1);
	sort(c+1,c+n+1);
	for(int i = 2;i <= n;i++){
		e[++cnt].x = a[i].x-a[i-1].x;
		e[cnt].u = a[i-1].num;
		e[cnt].v = a[i].num;
		e[++cnt].x = b[i].x-b[i-1].x;
		e[cnt].u = b[i-1].num;
		e[cnt].v = b[i].num;
		e[++cnt].x = c[i].x-c[i-1].x;
		e[cnt].u = c[i-1].num;
		e[cnt].v = c[i].num;
	}
	sort(e+1,e+cnt+1);
	m = 0;
	for(int i = 1;i <= n;i++)
		f[i] = i;
	for(int i = 1;i <= cnt;i++){
		int fu = getf(e[i].u);
		int fv = getf(e[i].v);
		if(fu == fv) continue;
		ans += e[i].x;
		f[fu] = fv;
		m++;
		if(m == n-1) break;
	}
	printf("%lld\n",ans);
	return 0;
}