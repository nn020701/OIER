#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll int
#define N 305
#define rep(i,j,k) for (ll i=j;i<=k;++i)
#define per(i,j,k) for (ll i=j;i>=k;--i)
using namespace std;
inline ll read(){
	char ch=getchar(); ll x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll n,m,ans,b[10],sum[N][N][10];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read(); m=read();
	rep(i,1,n) rep(j,1,m){
		rep(k,0,9) sum[i][j][k]=sum[i][j-1][k]+sum[i-1][j][k]-sum[i-1][j-1][k];
		++sum[i][j][read()];
	}
	rep(i,1,n) rep(j,1,m) rep(x,i,n) rep(y,j,m){
		if ((x-i+1)*(y-j+1)<ans) continue;
		ll num=0,flag=0;
		rep(k,0,9) b[k]=sum[x][y][k]-sum[i-1][j][k]-sum[i][j-1][k]+sum[i-1][j-1][k];
		rep(k,0,9) { if (b[k]&1) ++num; if (k&&b[k]&&!(b[k]&1)) flag=1; }
		if (flag&&num<=1) ans=(x-i+1)*(y-j+1);
	}
	printf("%d",ans);
}
