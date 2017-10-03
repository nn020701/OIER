#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

ll ans;
ll n,k;

ll calc(ll a,ll b){
	return (b-a+1)*(b+a)/2;
}

int main(){
	n = read(); k = read();
	ans = n*k;
	for(ll i = 1;i <= min(n,k);i++){
		ans -= (k/i)*calc(i,min(k/(k/i),n));
		i = min(k/(k/i),n);
	}
	printf("%lld\n",ans);
	return 0;
}