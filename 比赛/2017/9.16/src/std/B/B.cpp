#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn=205;
int T,n,a[maxn],f[maxn][maxn][maxn];
inline int sqr(int x){return x*x;}
inline int dp(int l,int r,int k)
{
	if (l>r) return 0;
	int & ans=f[l][r][k];
	if (ans>=0) return ans;
	int p=r;
	while (p>l&&a[p-1]==a[r]) p--;
	ans=dp(l,p-1,0)+sqr(r-p+k+1);
	for (int i=p-1;i>=l;i--)
		if (a[i]==a[r]&&a[i+1]!=a[i])
			ans=max(ans,dp(i+1,p-1,0)+dp(l,i,r-p+1+k));
	return ans;
}
int main()
{
	freopen("B.in", "r", stdin);
	freopen("B.out", "w", stdout);
	scanf("%d",&T);
	for (int cas=1;cas<=T;cas++){
		scanf("%d",&n);
		for (int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		memset(f,-1,sizeof(f));
		printf("Case %d: %d\n",cas,dp(1,n,0));
	}
}
