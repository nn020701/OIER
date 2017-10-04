#include<cstdio>
#include<memory.h>
#include<algorithm>
#include<vector>
#define maxn 400050
#define ll long long
#define For(i,j,k)  for(ll i=j;i<=k;++i)
#define FOr(i,j,k)  for(ll i=j;i>=k;--i)
using namespace std;
inline ll read(){   ll x=0,f=1;char ch=getchar();   while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}  while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}  return x*f; }
inline void wrote(ll x){    if (x<0) putchar('-'),x=-x; if (x>=10) wrote(x/10);   putchar(x%10+'0');  }
inline void writeln(ll x){ wrote(x);   puts("");   }
vector<ll> f[100010],g[100010];
ll sz[maxn],c[maxn],x[maxn],l[maxn],a[maxn],k[maxn],answ,n,Q;
void build(ll l,ll r,ll p){
	sz[p]=r-l+1;
	if (l==r)	return;
	ll mid=(l+r)>>1;
	build(l,mid,p<<1);	build(mid+1,r,p<<1|1);
}
void change(ll l,ll r,ll s,ll t,ll v,ll p){
	if (!sz[p])	return;
	if (l==s&&r==t){
		if (l==r){
			a[l]=v;	sz[p]=0;	return;
		}ll mid=(l+r)>>1;
		if (sz[p<<1])	change(l,mid,l,mid,v,p<<1);
		if (sz[p<<1|1])	change(mid+1,t,mid+1,t,v,p<<1|1);
		sz[p]=sz[p<<1]+sz[p<<1|1];
		return;
	}ll mid=(l+r)>>1;
	if (t<=mid)	change(l,mid,s,t,v,p<<1);
	else if (s>mid)	change(mid+1,r,s,t,v,p<<1|1);
	else change(l,mid,s,mid,v,p<<1),change(mid+1,r,mid+1,t,v,p<<1|1);
	sz[p]=sz[p<<1]+sz[p<<1|1];
}
void add(ll x,ll k){	for(;x<=n;x+=x&-x)	c[x]+=k;	}
void clear(ll x){	for(;x<=n;x+=x&-x)	c[x]=0;	}
ll ask(ll x){
	ll ans=0;
	for(;x;x-=x&-x)	ans+=c[x];
	return ans;
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read();	Q=read();
	For(i,1,Q)	x[i]=read(),l[i]=read(),k[i]=read();
	build(1,n,1);
	FOr(i,Q,1)	change(1,n,max(1LL,x[i]-k[i]),min(x[i]+k[i],n),l[i],1);
	For(i,1,n)	if (a[i])	g[a[i]].push_back(i);	else	answ++;
	For(i,1,Q)	f[l[i]].push_back(i);
	For(L,1,1e5){
		for(ll j=0;j<f[L].size();j++){
			ll i=f[L][j];
			add(max(1LL,x[i]-k[i]),1LL),add(min(x[i]+k[i],n)+1,-1LL);
		}
		for(ll j=0;j<g[L].size();j++)	answ+=ask(g[L][j])!=1;
		for(ll j=0;j<f[L].size();j++){
			ll i=f[L][j];
			clear(max(1LL,x[i]-k[i])),clear(min(x[i]+k[i],n)+1);
		}
	}
	writeln(answ);
}
/*
10 7
3 11 0
3 11 2
5 12 1
8 13 2
7 11 2
10 12 1
9 12 0
*/



