#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define MAX 300050
int n,q,x;
int fa[MAX];
int size[MAX];
int ans[MAX];
vector<int> G[MAX];
void dfs(int u)
{
	size[u]=1;
	ans[u]=u;
	for(int i=0;i<G[u].size();i++)
	{
		int v=G[u][i];
		dfs(v);
		size[u]+=size[v];
	}
	for(int i=0;i<G[u].size();i++)
		if(size[G[u][i]]*2>size[u])
			ans[u]=ans[G[u][i]];
	while((size[u]-size[ans[u]])*2>size[u])
			ans[u]=fa[ans[u]];
}
int main()
{
	int u,v;
	scanf("%d%d",&n,&q);
	for(int i=2;i<=n;i++)
	{
		scanf("%d",&fa[i]);
		G[fa[i]].push_back(i);
	}
	dfs(1);
	for(int i=1;i<=q;i++)
	{
		scanf("%d",&x);
		printf("%d\n",ans[x]);
	}
	return 0;
}
