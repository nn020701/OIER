#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <bits/stdc++.h>
#include <stack>

using namespace std;

#define For(i,j,n) for(int i=j;i<=n;i++)
#define mst(ss,b) memset(ss,b,sizeof(ss));

typedef long long LL;

template<class T> void read(T&num) {
	char CH; bool F=false;
	for(CH=getchar();CH<'0'||CH>'9';F= CH=='-',CH=getchar());
	for(num=0;CH>='0'&&CH<='9';num=num*10+CH-'0',CH=getchar());
	F && (num=-num);
}
int stk[70], tp;
template<class T> inline void print(T p) {
	if(!p) { puts("0"); return; }
	while(p) stk[++ tp] = p%10, p/=10;
	while(tp) putchar(stk[tp--] + '0');
	putchar('\n');
}

const LL mod=1e9+7;
const double PI=acos(-1.0);
const int inf=1e9;
const int N=2e5+10;
const int maxn=500+10;
const double eps=1e-14;

int vis[N],a[N],head[N],cnt,ans,siz,son[N],n,k;
LL ansdis=0;

struct Edge
{
	int from,to,next,val;
}edge[2*N];
inline void add_edge(int s,int e)
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
		if(fr==fa)continue;
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
	return ;
}
void dfs1(int cur,int fa,LL dis)
{
	if(vis[cur])ansdis=ansdis+dis;
	for(int i=head[cur];i!=-1;i=edge[i].next)
	{
		int fr=edge[i].to;
		if(fr==fa)continue;
		dfs1(fr,cur,dis+1);
	}
	return ;
}
inline void Init()
{
	mst(head,-1);
	cnt=0;
	siz=inf;
}
int main()
{
		read(n);read(k);
		Init();
		For(i,1,2*k)read(a[i]),vis[a[i]]=1;
		For(i,1,n-1)
		{
			int u,v;
			read(u);read(v);
			add_edge(u,v);
			add_edge(v,u);
		}
		dfs(1,0);
		dfs1(ans,0,0);
		cout<<ansdis<<endl;
		return 0;
}