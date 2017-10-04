#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
#define N 200005
#define rep(i,j,k) for (ll i=j;i<=k;++i)
#define per(i,j,k) for (ll i=j;i>=k;--i)
using namespace std;
inline ll read(){
	char ch=getchar(); ll x=0,f=1;
	while (ch<'0'||ch>'9') { if (ch=='-') f=-1; ch=getchar(); }
	while (ch>='0'&&ch<='9') { x=x*10+ch-'0'; ch=getchar(); }
	return x*f;
}
ll left[N<<2],right[N<<2],rev[N<<2],maxn[N<<2],fa[N<<2],val[N<<2];
ll n,m,num,last;
bool isroot(ll x){
	return left[fa[x]]!=x&&right[fa[x]]!=x;
}
void updata(ll x){
	maxn[x]=x;
	if (val[maxn[left[x]]]>val[maxn[x]]) maxn[x]=maxn[left[x]];
	if (val[maxn[right[x]]]>val[maxn[x]]) maxn[x]=maxn[right[x]];
}
void pushdown(ll x){
	if (rev[x]){
		rev[left[x]]^=1; rev[right[x]]^=1;
		rev[x]^=1; swap(left[x],right[x]); 
	}
}
void rotate(ll x){
	ll y=fa[x],z=fa[y],flag=left[y]==x;
	if (!isroot(y)) if (left[z]==y) left[z]=x; else right[z]=x;
	fa[x]=z; fa[y]=x;
	if (flag) fa[left[y]=right[x]]=right[x]=y;
	else fa[right[y]=left[x]]=left[x]=y;
	updata(y); updata(x);
}
void down(ll x) { if (!isroot(x)) down(fa[x]); pushdown(x); }
void splay(ll x){
	down(x);
	while (!isroot(x)){
		ll y=fa[x],z=fa[y];
		if (!isroot(y)) 
			if (left[z]==y^left[y]==x) rotate(x);
			else rotate(y);
		rotate(x);
	}
}
ll access(ll x){
	ll y;
	for (y=0;x;y=x,x=fa[x]){
		splay(x); right[x]=y; updata(x);
	}
	return y;
}
void makeroot(ll x){
	access(x); splay(x); rev[x]^=1;
}
void link(ll x,ll y){
	makeroot(x); fa[x]=y;
}
ll query(ll x,ll y){
	makeroot(x); access(y); splay(y);
	return val[maxn[y]];
}
int main(){
	freopen("tree.in","r",stdin);
	freopen("tree.out","w",stdout);
	n=read(); m=read(); 
	rep(i,1,n-1){
		ll u=read(),v=read(),w=read();
		maxn[i+n+m]=i+n+m; val[i+n+m]=w;
		link(u,i+n+m); link(v,i+n+m);
	}
	rep(i,1,m){
		ll opt=read();
		if (opt==1){
			ll a=read()^last,u=read()^last,v=read()^last,lca;
			makeroot(a); access(u); lca=access(v);
			last=query(a,lca); printf("%lld\n",last);
		}else{
			++num;
			ll a=read()^last,b=read()^last;
			maxn[num+n*2+m]=num+n*2+m; val[num+n*2+m]=b;
			link(n+num,n*2+m+num); link(a,n*2+m+num);
		}
	}
}
