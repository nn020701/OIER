#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int m[300][300];
int dist[300];
bool book[300];
void Prim(int s)
{
	int Ans=0;
	memset(book,0,sizeof(book));
	for(int i=1;i<=n;i++)
		dist[i]=m[s][i];
	book[s]=1;
	for(int i=1;i<=n-1;i++)
	{
		int v,Min=1<<30;
		for(int j=1;j<=n;j++)
			if(!book[j]&&dist[j]<Min)
			{
				Min=dist[j];
				v=j;
			}
		book[v]=1;
		Ans+=dist[v];
		for(int j=1;j<=n;j++)
			if(!book[j])
				dist[j]=min(dist[j],m[v][j]);
	}
	cout<<Ans<<endl;
}
int main()
{
	int a,b,c,d;
	while(1)
	{
		scanf("%d",&n);
		if(n==0)
			return 0;
		memset(m,127,sizeof(m));
		for(int i=1;i<=(n-1)*n/2;i++)
		{
			scanf("%d%d%d%d",&a,&b,&c,&d);
			if(d==1)
			{
				m[a][b]=0;
				m[b][a]=0;
			}
			else
			{
				m[a][b]=c;
				m[b][a]=c;
			}
		}
		Prim(1);
	}
	return 0;
}
