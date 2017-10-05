#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1000005;
char c[N];
//map<int,int>a[N];
int s[N],ans,C[3005][205],n,m,x,cnt,sum,k,a[N][26];
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
		unsigned kkk=strlen(c);
		for (unsigned j=0;j<kkk;++j)
		{
			int k=a[x][c[j]-'a'];
			if (!k)
			{
				a[x][c[j]-'a']=++cnt;
				++s[cnt];
				x=cnt;
			}
			else
			{
				++s[k];
				x=k;
			}
		}
	}
	//map<int,int>::iterator it;
	for (int i=1;i<=cnt;++i)
		(ans+=(ll)s[i]*(s[i]-1)/2%mod)%=mod;
		/*sum=s[i]*s[i];
		for (it=a[i].begin();it!=a[i].end();it++)
			sum-=s[it->second]*s[it->second];
		sum/=2;
		ans=((ll)ans+(ll)sum*h[i]%mod)%mod;*/
	for (int i=1;i<=m;++i)
	{
		scanf("%d",&k);
		printf("%lld\n",(ll)ans*C[n-2][k]%mod);
	}
	return 0;
}
