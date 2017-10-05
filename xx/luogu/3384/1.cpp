#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
#define ll long long 
using namespace std;
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

ll n,m,r,p;
ll a[N];
ll head[N],nxt[N*2],to[N*2],cnt;
ll f[N],dep[N],son[N],size[N],pre[N],top[N],tree[N],tot;
struct node{
	ll l,r,sum;
	ll flag;
}tr[N*4];

void insert(ll x,ll y){
	to[++cnt] = y; nxt[cnt] = head[x]; head[x] = cnt;
	to[++cnt] = x; nxt[cnt] = head[y]; head[y] = cnt;
}

void dfs1(ll x,ll fa){
	f[x] = fa; size[x] = 1;
	for(ll i = head[x];i;i = nxt[i])
		if(to[i] != fa){
			dep[to[i]] = dep[x]+1;
			dfs1(to[i],x);
			size[x] += size[to[i]];
			if(son[x] == 0 || size[to[i]] > size[son[x]])
				son[x] = to[i];
		}
}

void dfs2(ll x,ll fa){
	top[x] = fa; tree[x] = ++tot; pre[tot] = x;
	if(!son[x]) return;
	dfs2(son[x],fa);
	for(ll i = head[x];i;i = nxt[i])
		if(to[i] != f[x] && to[i] != son[x])
			dfs2(to[i],to[i]);
}

inline void pushup(ll num){
	tr[num].sum = (tr[num<<1].sum+tr[num<<1|1].sum)%p;
}

void build(ll num,ll l,ll r){
	tr[num].l = l; tr[num].r = r;
	tr[num].sum = 0; tr[num].flag = 0;
	if(l == r){
		tr[num].sum = a[pre[l]]%p;
		return;
	}
	ll mid = (l+r)>>1;
	build(num<<1,l,mid);
	build(num<<1|1,mid+1,r);
	pushup(num);
}

inline void pushdown(ll num){
	ll l = num<<1,r = num<<1|1;
	if(tr[num].flag != 0){
		(tr[l].sum += tr[num].flag*(tr[l].r-tr[l].l+1)) %= p;
		(tr[r].sum += tr[num].flag*(tr[r].r-tr[r].l+1)) %= p;
		(tr[l].flag += tr[num].flag) %= p;
		(tr[r].flag += tr[num].flag) %= p;
		tr[num].flag = 0;
	}
}

void add(ll num,ll x,ll y,ll z){
	if(x <= tr[num].l && tr[num].r <= y){
		(tr[num].sum += (tr[num].r-tr[num].l+1)*z) %= p;
		(tr[num].flag += z) %= p;
		return;
	}
	ll mid = (tr[num].l+tr[num].r)>>1;
	pushdown(num);
	if(x <= mid)
		add(num<<1,x,y,z);
	if(y > mid)
		add(num<<1|1,x,y,z);
	pushup(num);
}

ll ask_sum(ll num,ll x,ll y){
	if(x <= tr[num].l && tr[num].r <= y)
		return tr[num].sum;
	pushdown(num);
	ll mid = (tr[num].l+tr[num].r)>>1;
	ll ans = 0;
	if(x <= mid)
		(ans += ask_sum(num<<1,x,y)) %= p;
	if(y > mid)
		(ans += ask_sum(num<<1|1,x,y)) %= p;
	pushup(num);
	return ans;
}

inline void add1(ll x,ll y,ll z){
	ll f1 = top[x],f2 = top[y];
	while(f1 != f2){
		if(dep[f1] < dep[f2]){
			swap(f1,f2);
			swap(x,y);
		}
		add(1,tree[f1],tree[x],z);
		x = f[f1]; f1 = top[x];
	}
	if(dep[x] > dep[y])
		add(1,tree[y],tree[x],z);
	else add(1,tree[x],tree[y],z);
}

inline ll query1(ll x,ll y){
	ll f1 = top[x],f2 = top[y],ans = 0;
	while(f1 != f2){
		if(dep[f1] < dep[f2]){
			swap(f1,f2);
			swap(x,y);
		}
		(ans += ask_sum(1,tree[f1],tree[x])) %= p;
		x = f[f1]; f1 = top[x];
	}
	(ans += (dep[x] > dep[y])?ask_sum(1,tree[y],tree[x]):ask_sum(1,tree[x],tree[y])) %= p;
	return ans;
}

inline ll query2(ll x){
	return ask_sum(1,tree[x],tree[x]+size[x]-1);
}

inline void add2(ll x,ll z){
	add(1,tree[x],tree[x]+size[x]-1,z);
}

signed main(){
	n = read(); m = read(); r = read(); p = read();
	for(ll i = 1;i <= n;i++)
		a[i] = read();
	for(ll i = 1;i < n;i++){
		ll x = read(),y = read();
		insert(x,y);
	}
	dep[r] = 1;
	dfs1(r,0);
	dfs2(r,r);
	build(1,1,n);
	// for(int i = 1;i <= n;i++)
	// 	printf("%lld %lld %lld %lld %lld\n", f[i],tree[i],size[i],son[i],dep[i]);
	// printf("#: ");
	// for(int i = 1;i <= n;i++)
	// 	printf("%lld ",query1(i,i));
	// puts("");	
	for(ll i = 1;i <= m;i++){
		ll opt = read();
		if(opt == 1){
			ll x = read(),y = read(),z = read();
			add1(x,y,z);
		}
		else if(opt == 2){
			ll x = read(),y = read();
			printf("%lld\n",query1(x,y));
		}
		else if(opt == 3){
			ll x = read(),z = read();
			add2(x,z);
		}
		else{
			ll x = read();
			printf("%lld\n",query2(x));
		}
		// printf("#: ");
		// for(int i = 1;i <= n;i++)
		// 	printf("%lld ",query1(i,i));
		// puts("");
	}
	return 0;
}