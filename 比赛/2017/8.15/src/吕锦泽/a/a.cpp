#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 1005
#define rep(i,j,k) for (ll i=j;i<=k;++i)
#define per(i,j,k) for (ll i=j;i>=k;--i)
using namespace std;
inline ll read(){
	char ch=getchar(); ll x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll n,m,ans,a[N][N],sum1[N][N],sum2[N][N]; 
bool check(ll x){
	if (!x) return 1;
	rep(i,2,2*n) rep(j,1,n-x+1){
		if (i+j-1<=n||i+j-1+x-1>2*n) continue;
		if (x&1){
			ll px=j+(x+1)/2-1,py=i+j-1+(x+1)/2-1;
			ll t1=py+px-1,t2=j;
			if (sum1[i][j+x-1]-sum1[i][j-1]+sum2[t1][t2+x-1]-sum2[t1][t2-1]-a[px][py]<=m) return 1;
		}else{
			ll px=j+x/2-1,py=i+j-1+x/2-1;
			ll t1=px+py,t2=j;
			if (sum1[i][j+x-1]-sum1[i][j-1]+sum2[t1][t2+x-1]-sum2[t1][t2-1]<=m) return 1;
		}
	}
	return 0;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read(); m=read();
	rep(i,1,n) rep(j,1,n) a[i][j+n]=read();
	rep(i,1,2*n) rep(j,1,n) sum1[i][j]=sum1[i][j-1]+a[j][i+j-1];
	rep(i,n,3*n) rep(j,1,n) sum2[i][j]=sum2[i][j-1]+a[j][i-j+1];
	ll l=0,r=n;
	while (l<=r){
		ll mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%lld",ans);
}
