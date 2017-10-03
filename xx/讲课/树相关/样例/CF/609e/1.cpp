#include<map>
#include<set>
#include<cmath>
#include<ctime>
#include<stack>
#include<queue>
#include<cstdio>
#include<cctype>
#include<string>
#include<vector>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<functional>
#define fuck(x) cout<<"["<<x<<"]"
#define FIN freopen("input.txt","r",stdin)
#define FOUT freopen("output.txt","w+",stdout)
using namespace std;
typedef long long LL;
typedef pair<int, int>PII;
const int MX=2e5+5;
const int MS=4e5+5;
const int M=25;
const int INF=0x3f3f3f3f;
struct Edge{
	int u,v,nxt,cost,id;
	bool operator<(const Edge &P) const{
		return cost<P.cost;
	}
}E[MS],A[MX];
int rear,Head[MX];
void edge_init(){
	rear=0;
	memset(Head,-1,sizeof Head);
}
void edge_add(int u,int v,int cost){
	E[rear].u=u;
	E[rear].v=v;
	E[rear].cost=cost;
	E[rear].nxt=Head[u];
	Head[u]=rear++;
}
LL mincost,ans[MX];
int n,m,P[MX];
int find(int x){
	if(P[x]==x)
		return x;
	P[x]=find(P[x]);
	return P[x];
}
void MST(){
	mincost=0;
	for(int i=1;i<=n;i++) P[i]=i;
	for(int i=1;i<=m;i++){
		int p1=find(A[i].u),p2=find(A[i].v);
		if(p1!=p2){
			P[p1]=p2;
			edge_add(A[i].u,A[i].v,A[i].cost);
			edge_add(A[i].v,A[i].u,A[i].cost);
			mincost+=A[i].cost;
		}
	}
}
int dep[MX],fa[MX][M],MAX[MX][M];
void DFS(int u,int _dep,int _fa){
	dep[u]=_dep;
	fa[u][0]=_fa;
	for(int i=Head[u];~i;i=E[i].nxt){
		int v=E[i].v;
		if(v==_fa){
			MAX[u][0]=E[i].cost;
			continue;
		}
		DFS(v,_dep+1,u);
	}
}
void presolve(){
	DFS(1,0,1);
	for(int i=1;i<M;i++){
		for(int j=1;j<=n;j++){
			fa[i][j]=fa[fa[j][i-1]][i-1];
			MAX[j][i]=max(MAX[j][i-1],MAX[fa[j][i-1]][i-1]);
		}
	}
}
int LCA(int u,int v){
	int ret=0;
	while(dep[u]!=dep[v]){
		if(dep[u]<dep[v]) swap(u,v);
		int d=dep[u]-dep[v];
		for(int i=0;i<M;i++){
			if(d>>i&1){
				ret=max(ret,MAX[u][i]);
				u=fa[u][i];
			}
		}
	}
	if(u==v) return ret;
	for(int i=M-1;i>=0;i--){
		if(fa[u][i]!=fa[v][i]){
			ret=max(ret,MAX[u][i]);
			ret=max(ret,MAX[v][i]);
			u=fa[u][i];
			v=fa[v][i];
		}
	}
	return max(ret,max(MAX[u][0],MAX[v][0]));
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		edge_init();
		for(int i=1;i<=m;i++){
			A[i].id=i;
			scanf("%d%d%d",&A[i].u,&A[i].v,&A[i].cost);
		}
		sort(A+1,A+1+m);
		MST();
		presolve();
		for(int i=1;i<=m;i++)
			ans[A[i].id]=mincost-LCA(A[i].u,A[i].v)+A[i].cost;
		for(int i=1;i<=m;i++)
			printf("%I64d\n",ans[i]);
	}
	return 0;
}