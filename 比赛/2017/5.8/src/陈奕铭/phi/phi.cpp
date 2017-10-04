#include<iostream>
#include<cmath>
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

const int N=1000010;
const ll mod=1e9+7;
ll ff[N],q[N],tot,inv[N],n,pri[N],f[N],sum[N],S[N],ans=1;
bool mark[N];

void init(){
	n=1e6;
	for(ll i=2;i<=n;i++){
		if(!mark[i]) pri[++pri[0]]=i;
		for(ll j=1;j<=pri[0]&&i*pri[j]<=n;++j){
			mark[i*pri[j]]=1;
			if(!(i%pri[j])) break;
		}
	}
	inv[0]=inv[1]=sum[0]=sum[1]=1;
	for(ll i=2;i<=n;i++){
		inv[i]=inv[mod%i]*(mod-mod/i)%mod;
		sum[i]=sum[i-1]*i%mod;
	}
	for(ll i=1;i<=pri[0];i++) ff[pri[i]]=i;
}

void work(ll x){
	ll t=sqrt(x); tot=0;
	for(ll i=1;i<=pri[0];i++){
		if(pri[i]>t) break;
		if(!(x%pri[i])){
			q[++tot]=i; S[tot]=0;
			while(!(x%pri[i])){
				x/=pri[i];
				++S[tot];
			}
		}
	}
	if(x>1){ q[++tot]=ff[x]; S[tot]=1; }
	for(ll i=1;i<=tot;i++){
		ll tmp=1,now=0;
		for(ll j=0;j<=S[i];j++){
			now=(now+tmp)%mod;
			tmp=tmp*pri[q[i]]%mod;
		}
		f[q[i]]=f[q[i]]*now%mod;
	}
}

int main(){
	freopen("phi.in","r",stdin);
	freopen("phi.out","w",stdout);
	init(); n=read();
	for(ll i=1;i<=pri[0];i++) f[i]=1;
	for(ll i=1;i<=n;i++) work(read());
	for(ll i=1;i<=pri[0];i++){
		f[i]=((f[i]-1)*inv[pri[i]]%mod*(pri[i]-1)+1)%mod;
		ans=ans*f[i]%mod;
	}
	printf("%lld\n",ans);
	return 0;
}
