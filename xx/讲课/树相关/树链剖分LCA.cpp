inline int dfs1(int node,int fa)
{
	sum_node3++;
	poot[node]=sum_node3;
	insertpersidenttree(1,p,tmp[node],poot[fa],poot[node]);
	int s=1,t=0,u=0,v=0;
	for (int i=first[node];i!=0;i=next[i])
		if (edge[i]!=fa)
		{
			t=dfs1(edge[i],node);
			s=s+t;
			if (t>v)
				u=i,v=t;
		}
	heavy[node]=u;
	return s;
}

inline void dfs2(int node,int fa,int dep,bool he)
{
	dfs_clock++;
	pointtree[node]=dfs_clock;
	l[node]=r[node]=dfs_clock;
	depth[node]=dep;
	father[node]=fa;
	if (he)
		top[node]=top[fa];
	else
		top[node]=node;
	if (heavy[node])
	{
		dfs2(edge[heavy[node]],node,dep,true);
		r[node]=r[edge[heavy[node]]];
	}
	for (int i=first[node];i!=0;i=next[i])
		if ((edge[i]!=fa) && (i!=heavy[node]))
		{
			dfs2(edge[i],node,dep+1,false);
			r[node]=r[edge[i]];
		}
	return;
}

inline int lca(int x,int y)
{
	while (top[x]!=top[y])
	{
		if (depth[x]>depth[y])
			swap(x,y);
		if (top[y]!=y)
			y=father[top[y]];
		else
			y=father[y];
	}
	if (pointtree[x]<pointtree[y])
		return x;
	else
		return y;
}
