#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int a[N][N],f[N][N],g[N][N],n,m,ans,sum;
inline void read(int &x)
{
	x=0;
	char c=getchar();
	while (c>'9'||c<'0')
		c=getchar();
	while (c>='0'&&c<='9')
	{
		x=x*10+c-'0';
		c=getchar();
	}
}
int main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	read(n);
	read(m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			read(a[i][j]);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			f[i][j]=a[i][j]+f[i-1][j-1];
			g[i][j]=a[i][j]+g[i-1][j+1];
		}
	ans=2;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			while (i>=ans/2&&j>=ans/2&&i+ans/2<=n&&j+ans/2<=n
				&&f[i+ans/2][j+ans/2]-f[i-ans/2][j-ans/2]+g[i+ans/2][j-ans/2+1]-g[i-ans/2][j+ans/2+1]<=m)
				ans+=2;
		}
	ans-=2;
	sum=1;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
		{
			while (i>=(sum+1)/2&&j>=(sum+1)/2&&i+(sum-1)/2<=n&&j+(sum-1)/2<=n
			&&f[i+(sum-1)/2][j+(sum-1)/2]-f[i-(sum+1)/2][j-(sum+1)/2]+g[i+(sum-1)/2][j-(sum+1)/2+1]-g[i-(sum+1)/2][j+(sum-1)/2+1]-a[i][j]<=m)
				sum+=2;
		}
	sum-=2;
	ans=max(ans,sum);
	printf("%d",ans);
	return 0;
}
