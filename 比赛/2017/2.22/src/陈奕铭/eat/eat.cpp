#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct node{
	int v,w;
};
vector<node> e[110];
int n,m;
int Mi=999999999;
int dist[210];
int vis[210];
int p[210];
int q[210],top_q;
int top;
int ans;
void add(int u,int v,int w){
	node e1;
	e1.v=v;
	e1.w=w;
	e[u].push_back(e1);
}
void dfs(int x,int ed){
	if(x==ed){
		for(int i=1;i<=top;i++)
			q[i]=p[i];
		top_q=top;
		return;
	}
	for(int i=0;i<e[x].size();i++){
		if(dist[x]+e[x][i].w<dist[e[x][i].v]){
			dist[e[x][i].v]=dist[x]+e[x][i].w;
			p[++top]=e[x][i].v;
			dfs(p[top],ed);
			top--;
		}
	}
}
void dij(int st,int ed){
	vis[st]=true;
	for(int t=1;t<=n;t++){
		int Min=999999999;
		int l=0;
		for(int i=1;i<=n;i++){
			if(Min>dist[i]&&(!vis[i])){
				Min=dist[i];
				l=i;
			}
		}
		vis[l]=true;
		if(l==ed) return;
		for(int i=0;i<e[l].size();i++)
			if((!vis[i])&&dist[e[l][i].v]>dist[l]+e[l][i].w)
				dist[e[l][i].v]=dist[l]+e[l][i].w;
	}
}
void solve(int a,int b,int c){
	ans=0;
	memset(vis,0,sizeof vis);
	memset(dist,0x7f,sizeof dist);
	dist[a]=0;
	p[++top]=a;
	dfs(a,b);
	top--;
	ans=dist[b];
//	cout<<top_q<<endl;
	for(int i=1;i<=top_q;i++){
		dist[q[i]]=0;
//		cout<<q[i]<<endl;
	} 
	dij(a,c);
	ans+=dist[c];
	if(ans<Mi)
		Mi=ans;
}
int main(){
	freopen("eat.in","r",stdin);
	freopen("eat.out","w",stdout);
	n=read();
	m=read();
	int a,b,c;
	int x,y,z;
	for(int i=1;i<=m;i++){
		x=read();y=read();z=read();
		add(x,y,z);
		add(y,x,z);
	}
	a=read();b=read();c=read();
	solve(a,b,c);
	solve(b,c,a);
	solve(c,a,b);
	printf("%d\n",Mi);
	return 0;
}
