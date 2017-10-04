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

ll n,m;
ll f[30000];
ll sum,x,ans;

int main(){
	freopen("team.in","r",stdin);
	freopen("team.out","w",stdout);
	m=read();n=read();
	f[0]=1;
	for(ll i=1;i<=n;i++){
		x=read();
		for(ll j=sum;j>=0;j--)
			f[j+x]+=f[j];
		sum+=x;
	}
	for(ll i=sum;i>=1;i--){
		if(m<=f[i]){
			ans+=m*i;
			break;
		}
		else{
			ans+=f[i]*i;
			m-=f[i];
		}
	}
	printf("%lld",ans);
	return 0;
}