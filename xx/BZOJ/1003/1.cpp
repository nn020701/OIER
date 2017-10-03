#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct data{                   //�ڽӾ����߳�
	int next,to,w;
}e[801];
int ne,head[21];                 //head�ڽӾ���αͷ��� 
int n,m,k;
bool flag[101][21];             //��i��0<i<=n����j��0<j<=m����ͷ�Ƿ񱨷� 
long long t[101][101],f[101];   //t������i��0<i<=n��������j(0<j<=n)����㵽�յ�����·�� 
void insert(int u,int v,int w)   //�����±� 
{
	ne++;
	e[ne].to=v;
	e[ne].w=w;
	e[ne].next=head[u];
	head[u]=ne;
}
int spfa(int a,int b)
{
	bool block[21];
	int dis[21],q[500],inq[21];
	memset(block,0,sizeof block);
	memset(dis,127,sizeof dis);
	memset(inq,0,sizeof inq);
	for(int i=a;i<=b;i++)
		for(int j=1;j<=m;j++)
			if(flag[i][j])
				block[j]=1;   //a����b��֮��j�ڵ��Ƿ񱨷� 
	q[0]=1;          //���� 
	inq[1]=1;        //��Ǹýڵ�������� 
	dis[1]=0;
	int t=0,w=1;     //��ͷ���β 
	while(t<w)          //SPFA 
	{
		int p=head[q[t]];
		while(p)
		{
			if(!block[e[p].to]&&dis[e[p].to]>dis[q[t]]+e[p].w)
			{
				dis[e[p].to]=dis[q[t]]+e[p].w;
				if(!inq[e[p].to])
				{
					q[w++]=e[p].to;
					inq[e[p].to]=1;
				}
			}
			p=e[p].next;
		}
		inq[q[t]]=0;
		t++;
	}
	return dis[m];
}
void dp()
{
	for(int i=1;i<=n;i++)
	{
		f[i]=(long long)t[1][i]*i;
		for(int j=0;j<i;j++)
			f[i]=min(f[i],f[j]+k+t[j+1][i]*(i-j));
	}
}
int main()
{
	int q;
	cin>>n>>m>>k>>q;
	for(int i=1;i<=q;i++)      //�ӱ� 
	{
		int x,y,z;
		cin>>x>>y>>z;
		insert(x,y,z);
		insert(y,x,z);
	}
	int d;
	cin>>d;
	for(int i=1;i<=d;i++)      //��¼���Ͻڵ� 
	{
		int x,y,z;
		cin>>x>>y>>z;
		for(int j=y;j<=z;j++)
			flag[j][x]=1;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			t[i][j]=spfa(i,j);
	dp();
	cout<<f[n]<<endl;
	return 0;
}
