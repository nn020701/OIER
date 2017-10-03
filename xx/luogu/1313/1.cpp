#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define mod 10007
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll a,b,k,n,m;
ll ans;
ll num[1005];

ll kuaisu(ll x,ll k){
	ll ans = 1;
	while(k){
		if(k&1) ans = (ans*x)%mod;
		x = (x*x)%mod;
		k >>= 1;
	}
	return ans;
}

int main(){
	a = read(); b = read(); k = read(); n = read(); m = read();
	ans = (kuaisu(a,n)*kuaisu(b,m))%mod;
//	printf("%lld\n",ans);
	num[0] = 1; num[1] = 1;
	for(ll i = 2;i <= k;i++) num[i] = (num[i-1]*i)%mod;
//	printf("%lld %lld %lld\n",num[n],num[k-n],num[k]);
	ll Scarlet = (num[k]*kuaisu((num[k-n]*num[n])%mod,mod-2))%mod;
//	printf("%lld\n",Scarlet);
	ans = (ans*Scarlet)%mod;
	printf("%lld\n",ans);
	return 0;
}
