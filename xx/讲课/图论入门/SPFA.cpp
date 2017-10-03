void SPFA(int s){
	memset(dist,0x3f,sizeof dist);
	memset(inq,0,sizeof inq);
	queue<int>Q;
	dist[s]=0;
	while (!Q.empty()){
		int u=Q.front();inq[u]=0;
		for (int i=head[u];i!=-1;i=next[i]){
			int v=to[i];
			if (dist[u]+len[i]<dist[v]){
				dist[v]=dist[u]+len[i];
				if (!inq[v]){Q.push(v);inq[v]=1;}
			}
		}
	}
}
