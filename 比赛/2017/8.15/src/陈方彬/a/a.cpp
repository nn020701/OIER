#include<bits/stdc++.h>
#define Ll long long
using namespace std;
const Ll N=1e3+5;
Ll a[N][N],b[N][N],c[N][N];
Ll n,m;
Ll out(Ll x,Ll y,Ll k){
	Ll ans=b[x+k-1][y+k-1]-b[x-1][y-1];
	ans+=c[x+k-1][y]-c[x-1][y+k-1+1];
	if(k&1)ans-=a[x+k/2][y+k/2];
	return ans;
}
bool check(Ll k){
	for(Ll i=1;i<=n-k+1;i++)
		for(Ll j=1;j<=n-k+1;j++)
			if(out(i,j,k)<=m)return 1;
	return 0;
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(Ll i=1;i<=n;i++)
		for(Ll j=1;j<=n;j++)
			scanf("%lld",&a[i][j]);
	for(Ll i=1;i<=n;i++)
		for(Ll j=1;j<=n;j++)
			b[i][j]=b[i-1][j-1]+a[i][j];
	for(Ll i=1;i<=n;i++)
		for(Ll j=1;j<=n;j++)
			c[i][j]=c[i-1][j+1]+a[i][j];
//	while(1){
//		Ll x,y,z;
//		scanf("%lld%lld%lld",&x,&y,&z);
//		cout<<out(x,y,z)<<endl;
//	}
	Ll l=1,r=n,mid,ans=0;
	while(r>=l){
		mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;else r=mid-1;
	}
	printf("%lld",ans);
}

