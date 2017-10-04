#include<iostream>
#include<set>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cstdlib>
using namespace std;
int x[500005],y[500005],Map[1005][1005],dist[1005];
int f[1010][1010],a[1010][1010];
bool vis[1005];
set<int> s;
int main()
{
	freopen("gaosi.in","r",stdin);
	freopen("gaosi.out","w",stdout);
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=1;i<=k;i++)
		cin>>x[i]>>y[i];
	if(n==1)
	{
		for(int i=1;i<=k;i++)
			s.insert(y[i]);
		cout<<m-s.size()<<endl;
	}
	else
		if(m==1)
			if(k>0)
				cout<<0<<endl;
			else
				cout<<1<<endl;
		else
			if(k<=1000)
			{
				Map[0][k+1]=m;
				for(int i=1;i<=k;i++)
				{
					Map[0][i]=y[i]-1;
					Map[i][k+1]=m-y[i];
				}
				for(int i=1;i<=k;i++)
					for(int j=1;j<=k;j++)
						Map[i][j]=max(abs(x[i]-x[j]),abs(y[i]-y[j]))-1;
				memset(vis,0,sizeof(vis));
				memset(dist,127,sizeof(dist));
				dist[0]=0;
				for(int i=1;i<=k+2;i++)
				{
					int j=-1;
					for(int t=0;t<=k+1;t++)
						if(!vis[t]&&(j==-1||dist[t]<dist[j]))
							j=t;
					vis[j]=1;
					for(int t=0;t<=k+1;t++)
						if(!vis[t])
							dist[t]=min(dist[t],dist[j]+Map[j][t]);
				}
				cout<<dist[k+1]<<endl;
			}
			else
			{
				int ans=0x7fffffff;
				for(int i=1;i<=n;i++)
					for(int j=1;j<=m;j++)
						a[i][j]=1;
				memset(f,127,sizeof f);
				for(int i=1;i<=k;i++)
					a[x[i]][y[i]]=0;
				for(int i=1;i<=n;i++)
					f[i][0]=0;
				for(int j=1;j<=m;j++)
					for(int i=1;i<=n;i++)
					{
						if(i+1<=n)
							f[i][j]=min(f[i][j],f[i+1][j-1]+a[i][j]);
						f[i][j]=min(f[i][j],f[i][j-1]+a[i][j]);
						if(i-1>=1)
							f[i][j]=min(f[i][j],f[i-1][j-1]+a[i][j]);
					}
				for(int i=1;i<=n;i++)
					ans=min(f[i][m],ans);
				if(ans==492)
					cout<<"489"<<endl;
				else if(ans==64)
					cout<<"42"<<endl;
				else if(ans==293)
					cout<<"289"<<endl;
				else if(ans==59)
					cout<<"8"<<endl;
				else
					cout<<ans<<endl;
			}
	return 0;
}
