void Dijkstra(int s){
	memset(vis,0,sizeof vis);
	Rep(i,1,n) dist[i]=len[s][i];
	vis[s]=1;
	Rep(i,1,n-1){
		int v,Min=1<<30;
		Rep(j,1,n) if (!vis[j]&&dist[j]<Min)   //ѡ��V-U��dist��С�Ķ���
			Min=dist[j],v=j;
		vis[v]=1;                              //����������U��
		Rep(j,1,n) if (!vis[j])                //�������ڶ����dist
			dist[j]=min(dist[j],dist[v]+len[v][j]);
	}
}
