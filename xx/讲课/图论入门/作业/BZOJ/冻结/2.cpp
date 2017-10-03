#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
const int INF=1e9;
int n,m,k,in1,in2,in3,f[110][110],ans=INF;
bool used[110];
vector<pair<int,int> > graph[110];
queue<int> q;
void SPFA(int s)
{
	for(int i=1;i<=n;i++)
		for(int j=0;j<=k;j++)
			f[i][j]=INF;
	f[s][0]=0;
	used[s]=true;
	q.push(s);
	while(!q.empty())
	{
		int x=q.front(),len=graph[x].size();
		q.pop();
		used[x]=false;
		for(int i=0;i<len;i++)
		{
			bool relaxed=false;
			int t=graph[x][i].first,w=graph[x][i].second;
			for(int j=0;j<=k;j++)
			{
				if(f[t][j]>f[x][j]+w)
				{
					f[t][j]=f[x][j]+w;
					relaxed=true;
				}
				if(j&&f[t][j]>f[x][j-1]+w/2)
				{
					f[t][j]=f[x][j-1]+w/2;
					relaxed=true;
				}
			}
			if(relaxed&&!used[t])
			{
				used[t]=true;
				q.push(t);
			}
		}
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&in1,&in2,&in3);
		graph[in1].push_back(make_pair(in2,in3));
		graph[in2].push_back(make_pair(in1,in3));
	}
	SPFA(1);
	for(int i=0;i<=k;i++)
			ans=min(ans,f[n][i]);
	printf("%d\n",ans);
	return 0;
}
