#include<bits/stdc++.h>
using namespace std;
int a[310][310],num[10];
int n,m,mx;
 int main()
{
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j) scanf("%d",&a[i][j]);
	mx=0;
	for (int i=1;i<=n;++i)
		for (int j=1;j<=m;++j)
			for (int k=i;k<=n;++k)
				for (int p=j;p<=m;++p)
				{
					int ji=0;
					bool flag=false;
					memset(num,0,sizeof(num));
					int size=(k-i+1)*(p-j+1);
					if (size<=mx) continue;
					for (int s=i;s<=k;++s) 
						for (int d=j;d<=p;++d) num[a[s][d]]++;
					for (int f=0;f<=9;++f) 
					{
						if (num[f]%2==1) ji++;
						if (f!=0&&num[f]>0) flag=true;
					}
					if (flag&&ji<=1) mx=max(mx,size);
				}
	printf("%d\n",mx);
}
