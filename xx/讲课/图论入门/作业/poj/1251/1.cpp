#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n;
int m[30][30];
int dist[30];
bool book[30];
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
	char a;
	int b,c;
	int d;
	while(1)
	{
		cin>>n;
		if(n==0)
			return 0;
		memset(m,127,sizeof(m));
		for(int i=1;i<=n-1;i++)
		{
			cin>>a>>b;
			for(int j=1;j<=b;j++)
			{
				cin>>a>>c;
				d=a-'A'+1;
				m[d][i]=c;
				m[i][d]=c;
			}
		}
		Prim(1);
	}
	return 0;
}
