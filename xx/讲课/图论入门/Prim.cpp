int Prim(int s){
	int Ans=0;
	memset(vis,0,sizeof vis);
	Rep(i,1,n) dist[i]=len[s][i];
	vis[s]=1;
	Rep(i,1,n-1){
		int v,Min=1<<30;
		Rep(j,1,n) if (!vis[j]&&dist[j]<Min)
			Min=dist[j],v=j;
		vis[v]=1;Ans+=dist[v];
		Rep(j,1,n) if (!vis[j])
			dist[j]=min(dist[j],len[v][j]);
	}
	return Ans;
}
