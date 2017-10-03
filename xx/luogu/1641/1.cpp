#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 2000005
#define mod 20100403
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

ll a[N],b[N];
ll n,m;

ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b == 0){
		x = 1;
		y = 0;
		return a;
	}
	ll ans = exgcd(b,a%b,x,y);
	ll tmp = x;
	x = y;
	y = tmp-a/b*y;
	return ans;
}

ll C(ll n,ll m){
	ll tmp = (a[n]*b[n-m]%mod)*b[m]%mod;
	return tmp;
}

int main(){
	n = read(); m = read();
	a[0] = 1;
	for(ll i = 1;i <= n+m;++i)
		a[i] = (a[i-1]*i)%mod;
	ll y;
	exgcd(a[n+m],mod,b[n+m],y);
	b[n+m] = (b[n+m]+mod)%mod;
	for(ll i = n+m-1;i >= 0;i--)
		b[i] = (b[i+1]*(i+1))%mod;
	printf("%lld\n",(C(n+m,m)-C(n+m,m-1)+mod)%mod);
	return 0;
}