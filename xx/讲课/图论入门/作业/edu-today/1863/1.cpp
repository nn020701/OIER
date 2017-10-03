#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,m;
bool book[110];
int dist[110];
int w[110][110];
void Prim(int s)
{
	bool flag=false;
	int Ans=0;
	for(int i=1;i<=m;i++)
		dist[i]=w[s][i];
	book[s]=1;
	for(int i=1;i<=m-1;i++)
	{
		int v=0,Min=1<<30;
		for(int j=1;j<=m;j++)
			if(!book[j]&&dist[j]<Min)
			{
				v=j;
				Min=dist[j];
			}
		if(v==0)
			break;
		book[v]=1;
		Ans+=dist[v];
		for(int j=1;j<=m;j++)
			if(!book[j])
				dist[j]=min(dist[j],w[v][j]);
	}
	for(int i=1;i<=m;i++)
		if(!book[i])
		{
			flag=1;
			break;
		}
	if(flag)
		printf("?\n");
	else
		printf("%d\n",Ans);
}
int main()
{
	int a,b,c;
	while(1)
	{
		scanf("%d%d",&n,&m);
		if(n==0)
			return 0;
		memset(book,0,sizeof book);
		memset(w,127,sizeof w);
		for(int i=1;i<=n;i++)
		{
			scanf("%d%d%d",&a,&b,&c);
			w[a][b]=c;
			w[b][a]=c;
		}
		Prim(1);
	}
	return 0;
}
