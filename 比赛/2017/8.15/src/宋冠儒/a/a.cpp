#include<bits/stdc++.h>
using namespace std;
struct data{
	int zs,ys;
}sum[1010][1010];
int n,W,mx;
int a[1010][1010];
 bool solve(int size)
{
	for (int i=size;i<=n;++i)
	{
		for (int j=1;j<=n-size+1;++j) 
		{
			int ans;
			ans=sum[i][j].ys+sum[i][j+size-1].zs-sum[i-size][j-1].zs-sum[i-size][j+size].ys;
			if (size%2==1) 
			{
				int mid1=size/2+1;
				ans-=a[i-mid1+1][j+mid1-1];
			}
			if (ans<=W) return true;
		}
	}
	return false;
}
 int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	scanf("%d%d",&n,&W);
	mx=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j) 
		{
			scanf("%d",&a[i][j]);
		}
	for (int i=1;i<=n;++i) sum[1][i].zs=a[1][i],sum[1][i].ys=a[1][i];
	for (int i=2;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			sum[i][j].zs=a[i][j]+sum[i-1][j-1].zs;
			sum[i][j].ys=a[i][j]+sum[i-1][j+1].ys;
		} 
	int l=1,r=n;
	while (l<=r)
	{
		int mid=(l+r)>>1;
		if (solve(mid)) mx=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",mx);
}
