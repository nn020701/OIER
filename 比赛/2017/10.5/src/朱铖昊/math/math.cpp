#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000005,mod=1e8+7;
int ny[N],t,m,k;
ll n;
inline int ksm(int x,ll y)
{
	int ans=1;
	while (y)
	{
		if (y&1)
			ans=((ll)ans*x)%mod;
		x=((ll)x*x)%mod;
		y/=2;
	}
	return ans;
}
int main()
{
	freopen("math.in","r",stdin);
	freopen("math.out","w",stdout);
	scanf("%d",&t);
	for (int i=1;i<=1000000;++i)
		ny[i]=ksm(i,mod-2);
	while (t--)
	{
		scanf("%lld%d%d",&n,&m,&k);
		if (m==1)
		{
			printf("%d\n",ksm(2,n));
			continue;
		}
		if (m==2)
		{
			printf("%d\n",ksm(2,n-1));
			continue;
		}
		int ans=0,sum=1;
		if (k==0)
			ans=1;
		for (int i=1;i<=n;++i)
		{
			sum=(ll)sum*(n-i+1)%mod;
			sum=(ll)sum*ny[i]%mod;
			if (i%m==k)
				(ans+=sum)%=mod;
		}
		printf("%d\n",ans);
	}
	return 0;
}
