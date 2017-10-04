#include<bits/stdc++.h>
using namespace std;
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
const int N=400;
vector<int>a[N],f[N];
int g[1024],n,m,ans,x,y;
inline bool pd(int a,int b,int c,int d,int e)
{
	return f[b][d]+f[a][c]-f[a][d]-f[b][c]!=e;
}
int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	read(n);
	read(m);
	if (n<=m)
	{
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
			{
				read(x);
				if (j==1)
					a[i].push_back(0);
				a[i].push_back(x);
			}
	}
	else
	{
		for (int i=1;i<=n;++i)
			for (int j=1;j<=m;++j)
			{
				read(x);
				if (i==1)
					a[j].push_back(0);
				a[j][i]=x;
			}
		swap(n,m);
	}
	for (int i=0;i<=m;++i)
	{
		a[0].push_back(0);
		f[0].push_back(0);
	}
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
		{
			if (j==1)
				f[i].push_back(0);
			f[i].push_back(f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j]);
			a[i][j]=a[i-1][j]^a[i][j-1]^a[i-1][j-1]^(1<<a[i][j]);
		}
	for (int i=1;i<=n;++i)	
		for (int j=i;j<=n;++j)
		{
			memset(g,0,sizeof(g));
			for (int k=1;k<=m;++k)
			{
				x=a[i-1][k]^a[j][k];
				if (g[x]||!x)
				{
					if (pd(i-1,j,g[x],k,0))
						ans=max(ans,(j-i+1)*(k-g[x]));
				}
				else
					g[x]=k;
				for (int l=0;l<=9;++l)
				{
					y=x^(1<<l);
					if (g[y]||!y)
					{
						if (pd(i-1,j,g[y],k,l))
							ans=max(ans,(j-i+1)*(k-g[y]));
					}
				}
			}
		}
	printf("%d",ans);
	return 0;
}
