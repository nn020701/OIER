#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long LL;
typedef pair<int,int>PII;
const int MX=2e5+5;
const int MS=4e5+5;
const int INF=0x3f3f3f3f;
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
struct Edge{
	int u,v,nxt,cost,id;
	bool operator<(const Edge &P) const{
		return cost<P.cost;
	}
}E[MS],A[MS];
int _rear,Head[MX];
void edge_init(){
	_rear=0;
	memset(Head,-1,sizeof(Head));
}
void edge_add(int u,int v,int cost){
	E[_rear].u=u;
	E[_rear].v=v;
	E[_rear].cost=cost;
	E[_rear].nxt=Head[u];
	Head[u]=_rear++;
}
bool cmp(Edge a,Edge b){
	return a.id<b.id;
}
int n,m,P[MX];
LL mincost;
int find(int x){
	return P[x]==x?x:(P[x]=find(P[x]));
}
void MST_solve(){
	mincost=0;
	edge_init();
	sort(A+1,A+1+m);
	for(int i=1;i<=n;i++) P[i]=i;
	for(int i=1;i<=m;i++){
		int p1=find(A[i].u),p2=find(A[i].v);
		if(p1!=p2){
			P[p1]=p2;
			mincost+=A[i].cost;
			edge_add(A[i].u,A[i].v,A[i].cost);
			edge_add(A[i].v,A[i].u,A[i].cost);
		}
	}
}
int MAX[MX<<2],TA[MX];
void push_up(int rt){
	MAX[rt]=max(MAX[rt<<1],MAX[rt<<1|1]);
}
void build(int l,int r,int rt){
	if(l==r){
		MAX[rt]=TA[l];
		return;
	}
	int m=(l+r)>>1;
	build(lson);
	build(rson);
	push_up(rt);
}
int query(int L,int R,int l,int r,int rt){
	if(L<=l&&r<=R){
		return MAX[rt];
	}
	int m=(l+r)>>1,ret=-INF;
	if(L<=m) ret=max(ret,query(L,R,lson));
	if(R>m) ret=max(ret,query(L,R,rson));
	return ret;
}
int fa[MX],top[MX],siz[MX],son[MX],dep[MX],id[MX],rear;
void DFS1(int u,int f,int d){
	fa[u]=f;
	dep[u]=d;
	son[u]=0;
	siz[u]=1;
	for(int i=Head[u];~i;i=E[i].nxt){
		int v=E[i].v;
		if(v==f) continue;
		DFS1(v,u,d+1);
		siz[u]+=siz[v];
		if(siz[son[u]]<siz[v]){
			son[u],v;
		}
	}
}
void DFS2(int u,int tp){
	top[u]=tp;
	id[u]=++rear;
	if(son[u]) DFS2(son[u],tp);
	for(int i=Head[u];~i;i=E[i].nxt){
		int v=E[i].v;
		if(v==fa[u]||v==son[u]) continue;
		DFS2(v,v);
	}
}
void HLD_presolve(){
	rear=0;
	DFS1(1,0,1);
	DFS2(1,1);
	for(int i=0;i<2*(rear-1);i+=2){
		int u=E[i].u,v=E[i].v;
		if(dep[u]<dep[v]) swap(u,v);
		TA[id[u]]=E[i].cost;
	}
	TA[1]=-INF;
	build(1,rear,1);
}
int HLD_query(int u,int v){
	int tp1=top[u],tp2=top[v],ans=-INF;
	while(tp1!=tp2){
		if(dep[tp1]<dep[tp2]){
			swap(u,v);
			swap(tp1,tp2);
		}
		ans=max(ans,query(id[tp1],id[u],1,rear,1));
		u=fa[tp1];
		tp1=top[u];
	}
	if(u==v) return ans;
	if(dep[u]>dep[v]) swap(u,v);
	ans=max(ans,query(id[son[u]],id[v],1,rear,1));
	return ans;
}
int main(){
	while(~scanf("%d%d",&n,&m)){
		for(int i=1;i<=m;i++){
			A[i].id=i;
			scanf("%d%d%d",&A[i].u,&A[i].v,&A[i].cost);
		}
		MST_solve();
		HLD_presolve();
		sort(A+1,A+1+m,cmp);
		for(int i=1;i<=m;i++){
			int u=A[i].u,v=A[i].v,cost=A[i].cost;
			printf("%I64d\n",mincost+cost-HLD_query(u,v));
		}
	}
	return 0;
}
