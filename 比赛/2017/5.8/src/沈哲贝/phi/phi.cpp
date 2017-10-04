#include<algorithm>
#include<memory.h>
#include<cstdio>
#include<cmath>
#define ll long long
#define For(i,x,y)	for(ll i=x;i<=y;++i)
#define FOr(i,x,y)	for(ll i=x;i>=y;--i)
#define maxn 1000010
const ll mod=1e9+7;
using namespace std;
inline ll read(){	ll x=0,f=1;char ch=getchar();	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}	return x*f;	}
inline void write(ll x){	if (x<0) putchar('-'),x=-x; if (x>=10) write(x/10);	putchar(x%10+'0');	}
void writeln(ll x){	write(x);	puts("");	}

ll ff[maxn],q[maxn],tot,inv[maxn],n,pri[maxn],f[maxn],sum[maxn],S[maxn],ans=1;
bool mark[maxn];

void init(){
	n=1e6;
	For(i,2,n){
		if (!mark[i])	pri[++pri[0]]=i;
		for(ll j=1;j<=pri[0]&&i*pri[j]<=n;++j){
			mark[i*pri[j]]=1;
			if (!(i%pri[j]))	break;
		}
	}
	inv[0]=inv[1]=sum[0]=sum[1]=1;
	For(i,2,n)	inv[i]=inv[mod%i]*(mod-mod/i)%mod,sum[i]=sum[i-1]*i%mod;
	For(i,1,pri[0])	ff[pri[i]]=i;
}

void work(ll x){
	ll t=sqrt(x);	tot=0;
	For(i,1,pri[0]){
		if (pri[i]>t)	break;
		if (!(x%pri[i])){
			q[++tot]=i;	S[tot]=0;
			while (!(x%pri[i]))	x/=pri[i],++S[tot];
		}
	}
	if (x>1)	q[++tot]=ff[x],S[tot]=1;
	For(i,1,tot){
		ll tmp=1,now=0;
		For(j,0,S[i])
		now=(now+tmp)%mod,tmp=tmp*pri[q[i]]%mod;
		f[q[i]]=f[q[i]]*now%mod;
	}
}

int main(){
	freopen("phi.in","r",stdin);
	freopen("phi.out","w",stdout);
	init();	n=read();
	For(i,1,pri[0])	f[i]=1;
	For(i,1,n)	work(read());
	For(i,1,pri[0])	f[i]=((f[i]-1)*inv[pri[i]]%mod*(pri[i]-1)+1)%mod,ans=ans*f[i]%mod;
	writeln(ans);
}
