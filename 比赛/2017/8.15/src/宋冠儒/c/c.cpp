#include<bits/stdc++.h>
using namespace std;
bool f[10010][10010],a[10010];
int ans,n,m;
 int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i) a[i]=true;
	for (int i=1;i<=m;++i)
	{
		int x,l,k;
		scanf("%d%d%d",&x,&l,&k);
		for (int j=x-k;j<=x+k;++j) 
			if (f[j][l]) 
			{
				a[j]=true;
			}
		    else
		    {
		    	f[j][l]=true;
		    	a[j]=false;
			}
	}
	for (int i=1;i<=n;++i) ans+=a[i];
	printf("%d\n",ans);
}
