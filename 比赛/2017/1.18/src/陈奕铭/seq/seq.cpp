#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define LL long long
int n;
LL a[100010];
LL f[100010][4];
LL h[100010];
int main()
{
	freopen("seq.in","r",stdin);
	freopen("seq.out","w",stdout);
	scanf("%d",&n);
	bool flag=false;
	LL Max=-1000000010;
	int v=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		if(a[i]>0)
			flag=true;
	}
	h[1]=a[1];
	Max=a[1];
	f[1][1]=a[1];
	for(int i=2;i<=n;i++)
	{
		if(flag)
		{
			h[i]=h[i-1]+a[i];
			if(h[i]<0)
				h[i]=0;
		}
		if(!flag)
		{
			Max=max(Max,a[i]);
			h[i]=Max;
		}
		f[i][1]=max(f[i-1][1],h[i]);
		f[i][2]=f[i-1][1]+a[i];
		if(i>=3)
			f[i][2]=max(f[i-1][1]+a[i],f[i-1][2]+a[i]);
		f[i][3]=f[i][2];
		if(i>=3)
			f[i][3]=max(f[i-1][3],f[i][2]);
	}
	printf("%lld\n",f[n][3]);
	return 0;
}
