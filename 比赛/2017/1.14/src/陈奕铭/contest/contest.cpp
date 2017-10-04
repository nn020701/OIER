#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int w[110][110];
int l[110][110];
int n,m;
int ans;
int main()
{
	freopen("contest.in","r",stdin);
	freopen("contest.out","w",stdout);
	cin>>n>>m;
	int a,b;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		w[a][b]=1;
		l[b][a]=1;
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(w[i][k]==1&&w[k][j]==1)
					w[i][j]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(l[i][k]==1&&l[k][j]==1)
					l[i][j]=1;
	int p;
	for(int i=1;i<=n;i++)
	{
		p=0;
		for(int j=1;j<=n;j++)
		{
			if(w[i][j]==1||l[i][j]==1)
				p++;
		}
		if(p==n-1)
			ans++;
	}
	cout<<ans;
	return 0;
}
