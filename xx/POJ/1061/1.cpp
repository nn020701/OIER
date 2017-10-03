#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define M 32
#define mod 1000000007
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

ll x,y,n,m,L;

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

ll clac(ll a,ll b,ll c){
	ll x,y;
	ll gcd = exgcd(a,b,x,y);
	if(c%gcd != 0) return -1;
	x *= c/gcd;
	b /= gcd;
	if(b < 0) b = -b;
	ll ans = x%b;
	if(ans <= 0) ans += b;
	return ans;
}

int main(){
	while(~scanf("%lld %lld %lld %lld %lld",&x,&y,&m,&n,&L)){
		ll ans = clac(n-m,L,x-y);
		if(ans == -1) printf("Impossible\n");
		else printf("%lld\n", ans);
	}
	return 0;
}