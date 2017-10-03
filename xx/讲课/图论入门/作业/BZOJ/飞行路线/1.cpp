#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<queue>
#include<utility>
using namespace std;
#define LL long long 
const LL INF=1e9;
LL n,m,k,in1,in2,in3,f[10010][20],ans=INF;
bool used[10010];
vector<pair<LL,LL> > graph[10010];
queue<LL> q;
LL st;
LL ed;
void SPFA(LL s)
{
	for(LL i=1;i<=n;i++)
		for(LL j=0;j<=k;j++)
			f[i][j]=INF;
	f[s][0]=0;
	used[s]=true;
	q.push(s);
	while(!q.empty())
	{
		LL x=q.front(),len=graph[x].size();
		q.pop();
		used[x]=false;
		for(LL i=0;i<len;i++)
		{
			bool relaxed=false;
			LL t=graph[x][i].first,w=graph[x][i].second;
			for(LL j=0;j<=k;j++)
			{
				if(f[t][j]>f[x][j]+w)
				{
					f[t][j]=f[x][j]+w;
					relaxed=true;
				}
				if(j&&f[t][j]>f[x][j-1])
				{
					f[t][j]=f[x][j-1];
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
	scanf("%d%d",&st,&ed);
	for(LL i=1;i<=m;i++)
	{
		scanf("%d%d%d",&in1,&in2,&in3);
		graph[in1].push_back(make_pair(in2,in3));
		graph[in2].push_back(make_pair(in1,in3));
	}
	SPFA(st);
	for(LL i=0;i<=k;i++)
			ans=min(ans,f[ed][i]);
	printf("%d\n",ans);
	return 0;
}
