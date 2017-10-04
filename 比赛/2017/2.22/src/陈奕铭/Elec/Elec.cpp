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
int n;
struct node{
	int v,w;
};
struct data{
	int w,n;
}dist[310];
vector<node> e[310];
bool vis[310];
void add(int u,int v,int w){
	node e1;
	e1.v=v;
	e1.w=w;
	e[u].push_back(e1);
}
void bfs(int x){
	vis[x]=true;
	for(int i=0;i<e[x].size();i++){
		if(!vis[e[x][i].v]){
			dist[e[x][i].v].w=dist[x].w+e[x][i].w;
			bfs(e[x][i].v);
		}
	}
}
bool cmp(const data &a,const data &b){
	if(a.w==b.w)
		return a.n<b.n;
	return a.w>b.w;
}
int main(){
	freopen("elec.in","r",stdin);
	freopen("elec.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		int a,b,c;
		a=read();b=read();c=read();
		add(a,b,-c);
		add(b,a,c);
	}
	for(int i=1;i<=n;i++){
		dist[i].n=i;
	}
	dist[1].w=0;
	bfs(1);
	sort(dist+1,dist+n+1,cmp);
	int q;
	q=dist[1].w;
	printf("%d",dist[1].n);
	for(int i=2;i<=n;i++){
		if(!vis[dist[i].n])
			continue;
		if(dist[i].w==q)
			printf(" %d",dist[i].n);
		else{
			printf("\n%d",dist[i].n);
			q=dist[i].w;
		}
	}
	return 0;
}
