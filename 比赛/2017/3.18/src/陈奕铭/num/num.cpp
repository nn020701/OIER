#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const ll N=1001,mod=999983;
int f[N][10001];
ll n,a[10];

ll sum(ll x){
	ll pp=0;
	for(ll j=0;j<=x*9;j++)
		if(f[x][j])
			(pp+=1LL*f[x][j]*f[x][j])%=mod;
	return pp;
}

int main(){
	freopen("num.in","r",stdin);
	freopen("num.out","w",stdout);
	n=read();
	char s[12];
	scanf("%s",s+1);
	int l=strlen(s+1);
	for(ll i=1;i<=l;i++) a[i]=s[i]-'0';
	f[0][0]=1;
	for(ll i=0;i<n;i++)
		for(ll j=0;j<=n*9;j++)
			if(f[i][j])
				for(ll k=1;k<=l;k++)
					f[i+1][j+a[k]]=(f[i+1][j+a[k]]+f[i][j])%mod;
	ll ans=(sum(n)*2-sum(n/2)*sum(n-n/2))%mod;
	printf("%lld",(ans%mod+mod)%mod);
	return 0;
}
