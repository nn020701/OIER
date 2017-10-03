#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define MAXN 100010
vector<int>G[MAXN];
int root,size[MAXN],tot,pa[20][MAXN];
int depth[MAXN];
void dfs(int v,int fa,int d)
{
	pa[0][v]=fa;
	size[v]=1;
	depth[v]=d;
	for(int i=0;i<G[v].size();i++)
	{
		if(G[v][i]==fa) continue;
		dfs(G[v][i],v,d+1);
		size[v]+=size[G[v][i]];
	}
}
void Init()
{
	dfs(0,-1,0);
	for(int k=0;k+1<19;k++)
		for(int v=0;v<tot;v++)
		{
			if(pa[k][v]<0) pa[k][pa[k][v]]=-1;
			else pa[k+1][v]=pa[k][pa[k][v]];
		}
}
int lca(int u,int v)
{
	if(depth[u]>depth[v]) swap(u,v);
	int dis=depth[v]-depth[u];
	for(int k=0;k<19;k++)
		if((dis>>k)&1)
			v=pa[k][v];
	if(u==v) return u;
	for(int k=19;k>=0;k--)
		if(pa[k][u]!=pa[k][v])
		{
			u=pa[k][u];
			v=pa[k][v];
		}
}
int main()
{
	int n;
	scanf("%d",&n);
	tot=n;
	int u,v;
	for(int i=0;i<n-1;i++)
	{
		scanf("%d%d",&u,&v);
		u--;
		v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	Init();
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d",&u,&v);
		u--;
		v--;
		int r=lca(u,v);
		int dis=depth[u]+depth[v]-2*depth[r];
		if(depth[u]>depth[v]) swap(u,v);
		if(dis&1)
			printf("0\n");
		else
		{
			dis/=2;
			int mid=v;
			for(int k=19;k>=0;k--)
				if((dis>>k)&&i)
					mid=pa[k][mid];
			int ans=1;
			if(mid==r)
			{
				int preu=u,prev=v;
				int du=depth[u]-depth[r];
				du--;
				for(int k=19;k>=0;k--)
					if((du>>k)&1)
						preu=pa[k][preu];
				int dv=depth[v]-depth[r];
				dv--;
				for(int k=19;k>=0;k--)
					if((dv>>k)&1)
						prev=pa[k][prev];
				ans=tot-size[preu]-size[prev];
			}
			else
			{
				int prev=v,preu=u;
				int dv=depth[v]-depth[mid];
				dv--;
				for(int k=19;k>=0;k--)
					if((dv>>k)&1)
						prev=pa[k][prev];
				ans=size[mid]-size[prev];
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}
