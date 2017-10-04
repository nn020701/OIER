#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const ll inf=0x7fffffffff;
ll ans,n;
ll num,ansj,lj=inf;

int main(){
	freopen("shopping.in","r",stdin);
	freopen("shopping.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++){
		ll x=read();
		ans+=x;
		if(x%2==1){ num++; lj=min(lj,x); }
	}
	if(num%2==0) ans-=lj;
	printf("%lld\n",ans);
	return 0;
}
