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

ll m,k,n;
ll b[M],cnt;
ll ans;

struct Matrix{
	ll a[M][M];
	Matrix(){
		memset(a,0,sizeof a);
	}

	friend Matrix operator *(Matrix a,Matrix b){
		Matrix ans;
		for(ll k = 1;k <= cnt;k++)
			for(ll i = 1;i <= cnt;i++)
				if(a.a[i][k])
					for(ll j = 1;j <= cnt;j++)
						ans.a[i][j] = (ans.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
		return ans;
	}

	friend Matrix operator ^(Matrix a,ll b){
		Matrix ans;
		for(ll i = 1;i <= cnt;i++)
			ans.a[i][i] = 1;
		while(b){
			if(b&1) ans = ans*a;
			a = a*a;
			b >>= 1;
		}
		return ans;
	}
}vis;

ll Num(ll x){
	ll sum = 0;
	for(ll i = 0;i < m;i++)
		if(x&(1 << i))
			sum++;
	return sum;
}

void getvis(){
	for(ll i = 0;i < (1 << m);++i)
		if(Num(i) <= k)
			b[++cnt] = i;
	for(ll i = 1;i <= cnt;i++)
		for(ll j = 1;j <= cnt;j++){
			ll x = b[i],y = b[j];
			for(ll k = 0;k < m-1;k++){
				if(((x>>k)&1) != (y>>(k+1)&1)) break;
				if(k == m-2) vis.a[i][j] = 1;
			}
		}
}

int main(){
	n = read(); m = read(); k = read();
	getvis();
	Matrix num;
	num = vis^n;
	for(ll i = 1;i <= cnt;i++)
		ans = (ans+num.a[i][i])%mod;
	printf("%lld\n", ans);
	return 0;
}