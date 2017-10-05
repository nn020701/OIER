#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000005;
char c[N];
int h[N],s[N],ans,C[3005][205],a[N][26],n,m,x,cnt,sum,k;
const int mod=1e9+7;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d%d",&n,&m);
	C[0][0]=1;
	for (int i=1;i<=n-2;++i)
	{
		C[i][0]=1;
		for (int j=1;j<=200;++j)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	for (int i=1;i<=n;++i)
	{
		scanf("%s",c);
		x=0;
		for (unsigned j=0;j<strlen(c);++j)
		{
			if (!a[x][c[j]-'a'])
			{
				a[x][c[j]-'a']=++cnt;
				h[cnt]=h[x]+1;
			}
			++s[a[x][c[j]-'a']];
			x=a[x][c[j]-'a'];
		}
	}
	for (int i=1;i<=cnt;++i)
	{
		sum=s[i]*s[i];
		for (int j=0;j<25;++j)
			sum-=s[a[i][j]]*s[a[i][j]];
		sum/=2;
		ans=((ll)ans+(ll)sum*h[i]%mod)%mod;
	}
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&k);
		printf("%lld\n",(ll)ans*C[n-2][k]%mod);
	}
	return 0;
}