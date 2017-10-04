#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define ll long long
using namespace std;
inline ll read() {
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const ll MOD=1000000007;
struct node{
	ll l,r,lsum,rsum,sum;
}tree[400010];
ll n,m;
ll a[100010];

void build(ll l,ll r,ll num){
	tree[num].l=l;tree[num].r=r;
	tree[num].lsum=0; tree[num].rsum=0;
	tree[num].sum=0;
	if(l==r) return;
	ll mid=(l+r)>>1;
	build(l,mid,num*2);
	build(mid+1,r,num*2+1);
}
void update(ll num){
	ll l=tree[num].l,r=tree[num].r;
	if(l==r) return;
	ll mid=(l+r)>>1;
	tree[num].lsum=tree[num*2].lsum+tree[num*2+1].lsum+tree[num*2+1].sum*(mid-l+1);
	tree[num].rsum=tree[num*2].rsum+tree[num*2+1].rsum+tree[num*2].sum*(r-mid);
}
void add(ll num,ll x){
	tree[num].sum++;
	ll l=tree[num].l,r=tree[num].r;
	if(l==r) return;
	ll mid=(l+r)>>1;
	if(x<=mid) add(num*2,x);
	else add(num*2+1,x);
	update(num);
}
ll query(ll num,ll x){
	if(tree[num].l==tree[num].r) return 0;
	ll mid=(tree[num].l+tree[num].r)>>1;
	if(x<=mid)
		return query(num*2,x)+tree[num*2+1].lsum+tree[num*2+1].sum*(mid-x+1);
	else
		return query(num*2+1,x)+tree[num*2].rsum+tree[num*2].sum*(x-mid);
}

int main(){
	freopen("dist.in","r",stdin);
	freopen("dist.out","w",stdout);
	n=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
		if(m<a[i]) m=a[i];
	}
	build(1,m,1);
	for(ll i=1;i<=n;i++){
		printf("%lld ",query(1,a[i])%MOD);
		add(1,a[i]);
	}
	return 0;
}
