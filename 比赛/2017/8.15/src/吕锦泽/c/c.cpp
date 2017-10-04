#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll int
#define N 10005
#define rep(i,j,k) for (ll i=j;i<=k;++i)
#define per(i,j,k) for (ll i=j;i>=k;--i)
using namespace std;
inline ll read(){
	char ch=getchar(); ll x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll n,m,tot,ans,a[N],head[N];
struct edge{ ll to,next; }e[N*100];
void add(ll u,ll v){
	e[++tot]=(edge){v,head[u]}; head[u]=tot;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read(); m=read();
	rep(i,1,m){
		ll x=read(),y=read(),z=read();
		ll l=max(1,x-z),r=min(n,x+z);
		rep(j,l,r){
			ll flag=0;
			for (ll k=head[j],v=e[k].to;k;k=e[k].next,v=e[k].to)
				if (v==y) { flag=1; break; }
			if (flag) a[j]=0;
			else a[j]=1,add(j,y);
		}
	}
	rep(i,1,n) if (!a[i]) ++ans;
	printf("%d",ans);
}
