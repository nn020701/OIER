#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
const int N=110000;
int n,m;
LL a[N];
LL sum1[N],sum2[N];
bool cmp(const int &a,const int &b)
{
	return a<b;
}
int main()
{
    freopen("cf.in","r",stdin);
    freopen("cf.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
    sort(a+1,a+1+n,cmp);
    sum1[0]=0;
    sum2[0]=0;
    for(int i=1;i<=n;i++)
    {
        sum1[i]=sum1[i-1]+a[i];
        sum2[i]=sum2[i-1]+a[i]*a[i];
    }
    LL ans=(LL)1e18;
    for(int i=m;i<=n;i++)
	{
        LL ret=m*(sum2[i]-sum2[i-m])-(long long)(sum1[i]-sum1[i-m])*(sum1[i]-sum1[i-m]);
        if(ret<ans)ans=ret;
    }
    printf("%lld\n",ans);
    return 0;
}
