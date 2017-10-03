#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 2005
#define M 1005
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll n,m;
ll ans = 1<<30;
ll a[M][N];
ll f[M][N];

int main(){
	n = read(); m = read();
	for(ll i = 0;i < m;i++)
		for(ll j = 1;j <= n;j++)
			a[i][j] = read();
	for(ll i = 0;i < m;i++)
		f[i][1] = a[i][1];
	for(ll j = 1;j <= n;j++){
		for(ll i = 0;i < m;i++){
			if(i == 0) f[i][j] = min(f[i][j-1],f[m-1][j-1])+a[i][j];
			else f[i][j] = min(f[i][j-1],f[i-1][j-1])+a[i][j];
		}
	}
	for(ll i = 0;i < m;i++)
		ans = min(f[i][n],ans);
	printf("%lld\n",ans);
	return 0;
}
