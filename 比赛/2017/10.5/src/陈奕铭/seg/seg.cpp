#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm> 
#define N 500005
#define int unsigned
using namespace std;
const int L=200000;
char LZH[L];
char *S,*T;
inline char gc(){
	if (S==T){
		T=(S=LZH)+fread(LZH,1,L,stdin);
		if (S==T) return EOF;
	}
	return *S++;
}
inline int read(){
	int x=0;
	char c=gc();
	for (;c<'0'||c>'9';c=gc());
	for (;c>='0'&&c<='9';c=gc())
		x=(x<<1)+(x<<3)-48+c;
	return x;
}
inline void write(int x){
	static int a[12],top;
	top=0;
	for (;x;a[++top]=x%10,x/=10);
	for (;top;top--) putchar('0'+a[top]);
}

int a[N],n,q,fl,x,y,mx;
struct node{
	int t0,t1;
}t[1049000],ans;

inline node merge(const node &a,const node &b){
	static node c;
	c.t0 = (a.t0 & b.t1) | ((~a.t0) & b.t0);
	c.t1 = (a.t1 & b.t1) | ((~a.t1) & b.t0);
	return c;
}

void build(int k,int l,int r){
	mx = max(mx,k);
	if(l == r){
		t[k].t0 = (~0);
		t[k].t1 = (~a[l]);
		return;
	}
	int mid = (l+r)>>1;
	build(k<<1,l,mid);
	build(k<<1|1,mid+1,r);
	t[k] = merge(t[k*2],t[k*2+1]);
}

void change(int k,int l,int r,int x,int v){
	if(l == r){
		a[l] = v;
		t[k].t0 = (~0);
		t[k].t1 = (~v);
		return;
 	}
 	int mid = (l+r)>>1;
 	if(x <= mid) change(k<<1,l,mid,x,v);
 	else change(k<<1|1,mid+1,r,x,v);
 	t[k] = merge(t[k<<1],t[k<<1|1]);
}

void ask(int k,int l,int r,int x,int y){
	if(l == x && r == y){
		ans = merge(ans,t[k]);
		return;
	}
	int mid = (l+r)>>1;
	if(y <= mid) ask(k<<1,l,mid,x,y);
	else if(x > mid) ask(k<<1|1,mid+1,r,x,y);
	else ask(k<<1,l,mid,x,mid),ask(k<<1|1,mid+1,r,mid+1,y);
}

signed main(){
	freopen("seg.in","r",stdin);
	freopen("seg.out","w",stdout);
	n = read(); q = read();
	for(int i = 1;i <= n;i++)
		a[i] = read();
	build(1,1,n);
	while(q--){
		fl = read(); x = read(); y = read();
		if(fl == 1) change(1,1,n,x,y);
		else if(x == y)
			write(a[x]),puts("");
		else{
			ans.t0 = 0; ans.t1 = ~0;
			ask(1,1,n,x+1,y);
			write((a[x]&ans.t1)|((~a[x])&ans.t0)),puts("");
		}
	}
	return 0;
}