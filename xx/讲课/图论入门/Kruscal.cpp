struct Edge{
	int u,v,w;
	bool operator <(const Edge&x)const{return w<x.w;}
}a[maxm];
int find(int x){return x==fa[x]?x:fa[x]=find(fa[x]);}
void Kruscal(){
	int Ans=0;
	sort(a+1,a+m+1);
	Rep(i,1,n) fa[i]=i;
	Rep(i,1,m){
		int u=find(a[i].u),v=find(a[i].v);
		if (u!=v){Ans+=a[i].w;fa[u]=v;}
	}
}
