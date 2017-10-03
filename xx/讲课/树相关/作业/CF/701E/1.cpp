#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 200050
#define INF 1e9
template<class T> void read(T&num) {
	char CH; bool F=false;
	for(CH=getchar();CH<'0'||CH>'9';F= CH=='-',CH=getchar());
	for(num=0;CH>='0'&&CH<='9';num=num*10+CH-'0',CH=getchar());
	F && (num=-num);
}
int vis[N],a[N],head[N],cnt,ans,siz,son[N],n,k;
long long ansdis=0;
struct Edge{
	int from,to,next;
}edge[2*N];
inline void add(int s,int e)
{
	edge[cnt].from=s;
	edge[cnt].to=e;
	edge[cnt].next=head[s];
	head[s]=cnt++;
}
void dfs(int cur,int fa)
{
	son[cur]=vis[cur];
	int temp=0;
	for(int i=head[cur];i!=-1;i=edge[i].next)
	{
		int fr=edge[i].to;
		if(fr==fa)
			continue;
		dfs(fr,cur);
		son[cur]+=son[fr];
		temp=max(temp,son[fr]);
	}
	temp=max(temp,2*k-son[cur]);
	if(temp<siz||temp==siz&&cur<ans)
	{
		siz=temp;
		ans=cur;
	}
	return;
}
void dfs1(int cur,int fa,long long dis)
{
	if(vis[cur])
		ansdis=ansdis+dis;
	for(int i=head[cur];i!=-1;i=edge[i].next)
	{
		int fr=edge[i].to;
		if(fr==fa)
			continue;
		dfs1(fr,cur,dis+1);
	}
	return ;
}
inline void Init()
{
	for(int i=1;i<=n;i++)
		head[i]=-1;
	cnt=0;
	siz=INF;
}
int main()
{
	int u,v;
	read(n);
	read(k);
	for(int i=1;i<=2*k;i++)
	{
		read(a[i]);
		vis[a[i]]=1;
	}
	for(int i=1;i<=n-1;i++)
	{
		read(u);
		read(v);
		add(u,v);
		add(v,u);
	}
	dfs(1,0);
	dfs1(ans,0,0);
	cout<<ansdis<<endl;
	return 0;
}
