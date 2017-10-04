#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
#define N 100005
inline ll read(){
	char ch=getchar(); ll x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}

ll a[N],f[N];
ll ti[N];
ll n,q;

void dfs2(ll x){
	if(ti[x] != -1) return;
	if(f[x] == 1){
		if(x == n) ti[x] = 0;
		else if(f[x+1] == 1){
			if(ti[x+1] != 0)
				ti[x] = ti[x+1]+a[x+1]-a[x];
			else ti[x] = 0;
		}
		else{
			ti[x+1] = ti[x] = (a[x+1]-a[x])/2;
		}
	}
}

void dfs1(ll x){
	if(ti[x] != -1) return;
	if(f[x] == 2){
		if(x == 1) ti[x] = 0;
		else if(f[x-1] == 1){
			ti[x-1] = ti[x] = (a[x]-a[x-1])/2;
		}
		else{
			if(ti[x-1] != 0)
				ti[x] = ti[x-1]+a[x]-a[x-1];
			else ti[x] = 0;
		}
	}
}

int main(){
	freopen("walk.in","r",stdin);
	freopen("walk.out","w",stdout);
	n = read(); q = read();
	for(ll i = 1;i <= n;i++){
		a[i] = read();
		f[i] = read();
	}
	memset(ti,-1,sizeof ti);
	for(ll i = 1;i <= n;i++)
		dfs1(i);
	for(ll i = n;i >= 1;i--)
		dfs2(i);
	for(ll i = 1;i <= q;i++){
		ll t = read(),x = read();
		if(ti[x] == 0 || ti[x] > t){
			if(f[x] == 1)
				printf("%lld\n",a[x]+t);
			else printf("%lld\n",a[x]-t);
		}
		else{
			if(f[x] == 1)
				printf("%lld\n",a[x]+ti[x]);
			else printf("%lld\n",a[x]-ti[x]);
		}
	}
	return 0;
}
