#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read()
{
	char ch=getchar();
	int f=1,x=0;
	while(!(ch>='0'&&ch<='9')){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+(ch-'0');ch=getchar();}
	return x*f;
}
int q,n,cnt;
int deep[500010],head[500010],fa[500010][20]; //head类似于头指针 
bool vis[500010];
struct data{      //邻接表 
	int to,next; 
}e[1000010];
void ins(int u,int v)  //加边入邻接表 
{
	e[++cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
void insert(int u,int v)
{
	ins(u,v);
	ins(v,u);
}
void dfs(int x)    //构造倍增表 
{
	vis[x]=1;
	for(int i=1;i<=18;i++)
	{
		if(deep[x]<(1<<i)) break;
		fa[x][i]=fa[fa[x][i-1]][i-1];
	}
	for(int i=head[x];i;i=e[i].next)
	{
		if(vis[e[i].to]) continue;
		deep[e[i].to]=deep[x]+1;
		fa[e[i].to][0]=x;
		dfs(e[i].to);
	}
}
int lca(int x,int y)    //求lca 
{
	if(deep[x]<deep[y]) swap(x,y);
	int d=deep[x]-deep[y];
	for(int i=0;i<=18;i++)
		if((1<<i)&d) x=fa[x][i];
	for(int i=18;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			{
				x=fa[x][i];
				y=fa[y][i];
			}
	if(x==y)
		return x;
	else
		return fa[x][0];
}
int dis(int x,int y)
{
	int t=lca(x,y);
	return deep[x]+deep[y]-2*deep[t];
}
int cal(int x,int y,int z)
{
	int p1=lca(x,y),p2=lca(x,z),p3=lca(y,z),t;
	if(p1==p2)
		t=p3;
	else if(p2==p3)
		t=p1;
	else
		t=p2;
	int ans;
	ans=dis(x,t)+dis(y,t)+dis(z,t);
	printf("%d %d\n",t,ans);
}
int main()
{
	n=read();
	q=read();
	for(int i=1;i<n;i++)
	{
		int u,v;
		u=read();
		v=read();
		insert(u,v);
	}
	dfs(1);
	for(int i=1;i<=q;i++)
	{
		int x,y,z;
		x=read();
		y=read();
		z=read();
		cal(x,y,z);
	}
	return 0;
}
