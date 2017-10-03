#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
#define mod 2147483648LL
#define lowbit(x) ((x)&(-x))
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,w,K,H[N];
ll c[N][11],tr[N],ans;
struct data{
	int x,y;
	friend bool operator <(data a,data b){
		return a.y < b.y || (a.y == b.y && a.x < b.x);
	}
}a[100005];
int h[N],l[N];
int now[N];

int find(int x){
	int l = 1,r = 2*w,mid;
	while(l <= r){
		mid = (l+r)>>1;
		if(H[mid] < x) l = mid+1;
		else if(H[mid] > x) r = mid-1;
		else return mid;
	}
	return 0;
}

void getc(){
	c[0][0] = 1;
	for(int i = 1;i <= w;++i){
		c[i][0] = 1;
		for(int j = 1;j <= min(K,i);++j)
			c[i][j] = (c[i-1][j]+c[i-1][j-1])%mod;
	}
}

void update(int x,int y){
	for(;x <= 2*w;x += lowbit(x))
		tr[x] = (tr[x]+y)%mod;
}

ll ask(int x){
	ll s = 0;
	for(;x > 0;x -= lowbit(x))
		s = (s+tr[x])%mod;
	return s;
}

int main(){
	m = read(); n = read(); w = read();
	for(int i = 1;i <= w;++i){
		a[i].x = read(); a[i].y = read();
		H[2*i-1] = a[i].x;
		H[2*i] = a[i].y;
	}
	K = read();
	getc();
	sort(H+1,H+2*w+1);
	for(int i = 1;i <= w;++i){
		h[find(a[i].y)]++;
		l[find(a[i].x)]++;
	}
	sort(a+1,a+w+1);
	int lf;
	for(int i = 1;i <= w;++i){
		if(i > 1 && a[i].y == a[i-1].y){
			lf++;
			ll t1 = ask(find(a[i].x)-1)-ask(find(a[i-1].x));
			ll t2 = c[lf][K]*c[h[find(a[i].y)]-lf][K];
			ans += t1*t2;
			ans %= mod;
		}
		else lf = 0;
		int d = find(a[i].x);
		now[d]++;
		int change = (c[now[d]][K]*c[l[d]-now[d]][K]-c[now[d]-1][K]*c[l[d]-now[d]+1][K])%mod;
		update(d,change);
	}
	if(ans < 0) ans += mod;
	printf("%lld\n", ans);
	return 0;
}