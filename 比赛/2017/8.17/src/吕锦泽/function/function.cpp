#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 1000005
#define mod 1000000007
#define rep(i,j,k) for (ll i=j;i<=k;++i)
#define per(i,j,k) for (ll i=j;i>=k;--i)
using namespace std;
inline ll read(){
	char ch=getchar(); ll x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll T,n,k,ans;
ll phi(ll x){
	ll t=x,num=sqrt(x);
	for (ll i=2;i<=num;i++)
		if (x%i==0){
			t-=t/i;
			while (x%i==0) x/=i;
		}
	if (x>1) t-=t/x;
	return t;
}
int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	T=read();
	while (T--){
		n=read(); k=read();
		k=(k+1)>>1; ans=n;
		rep(i,1,k){
			ans=phi(ans);
			if (ans==1) break;
		}
		printf("%lld\n",ans%mod);
	}
}
