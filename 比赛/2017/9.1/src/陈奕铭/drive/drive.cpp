#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 500005
#define mod 1000000007
#define gc getchar
#define lowbit(x) (x&(-x))
/*
const ll L=200005;
char LZH[L],*S=LZH,*T=LZH;
inline char gc(){
	if (S==T){
		T=(S=LZH)+fread(LZH,1,L,stdin);
		if (S==T) return EOF;
	}
	return *S++;
}*/
inline ll read(){
	ll x=0,f=1;
	char c=gc();
	for (;c<'0'||c>'9';c=gc())
		if (c=='-') f=-1;
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)+c-48;
	return x*f;
}

ll tree[N],w[N];
ll n,d[N],a[N],cnt,ans;
ll Scarlet1[N],Scarlet2[N];
ll Remilia1[N],Remilia2[N];
ll left[N],right[N];

ll erfen(ll x){
	ll l = 1,r = cnt;
	ll mid;
	while(l <= r){
		mid = (l+r)>>1;
		if(d[mid] > x) r = mid-1;
		else l = mid+1;
	}
	return r;
}

inline void add(int x,int v){
	for(int i = x;i <= cnt;i += lowbit(i))
		tree[i] = (tree[i]+v)%mod;
}

inline int query(int x){
	ll ans = 0;
	for(int i = x;i;i -= lowbit(i))
		ans = (ans+tree[i])%mod;
	return ans;
}


int main(){
	freopen("drive.in","r",stdin);
	freopen("drive.out","w",stdout);
	n = read();
	for(ll i = 1;i <= n;i++)
		d[i] = a[i] = read();
	sort(d+1,d+n+1); cnt = 1;
	for(ll i = 2;i <= n;i++)
		if(d[i] > d[i-1])
			d[++cnt] = d[i];
	for(ll i = 1;i <= n;i++)
		a[i] = erfen(a[i]);
	//数据处理结束
	memset(tree,0,sizeof tree);
	for(int i = 1;i <= n;i++){
		Scarlet1[i] = query(a[i]-1);
		Scarlet2[i] = Scarlet1[i]+w[a[i]];
		add(a[i],1); w[a[i]]++;
	}
	for(int i = n;i >= 1;i--){
		int x = query(a[i]-1);
		Remilia1[i] = x-Scarlet1[i];
		Remilia2[i] = x+w[a[i]]-1-Scarlet2[i];
	}
	memset(tree,0,sizeof tree);
	for(int i = 1;i <= n;i++){
		left[i] = Scarlet1[i]*(Scarlet1[i]-1)/2;
		(left[i] -= query(a[i]-1)) %= mod;
		add(a[i],Scarlet2[i]);
	}
	memset(tree,0,sizeof tree);
	for(int i = n;i >= 1;i--){
		right[i] = Remilia1[i]*(Remilia1[i]-1)/2;
		(right[i] -= query(a[i]-1)) %= mod;
		add(a[i],Remilia2[i]);
	}
	for(ll i = 1;i <= n;i++)
		ans = (ans+left[i]*right[i])%mod;
	printf("%lld\n",ans);
	return 0;
}