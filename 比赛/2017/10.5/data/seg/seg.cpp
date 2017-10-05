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
int a[N],n,q,fl,x,y;
struct node{bool a[32][2];}t[N*4];
inline node merge(const node &a,const node &b){
	static node c;
	for (int i=0;i<32;i++)
		c.a[i][0]=b.a[i][a.a[i][0]],
		c.a[i][1]=b.a[i][a.a[i][1]];
	return c; 
}
void build(int k,int l,int r){
	if (l==r){
		for (int i=0;i<32;i++)
			t[k].a[i][0]=1,t[k].a[i][1]=((a[l]>>i)&1)^1;
		return;
	}
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
	t[k]=merge(t[k*2],t[k*2+1]);
}
void change(int k,int l,int r,int x,int v){
	if (l==r){
		a[l]=v;
		for (int i=0;i<32;i++)
			t[k].a[i][0]=1,t[k].a[i][1]=((v>>i)&1)^1;
		return;
	}
	int mid=(l+r)/2;
	if (x<=mid) change(k*2,l,mid,x,v);
	else change(k*2+1,mid+1,r,x,v);
	t[k]=merge(t[k*2],t[k*2+1]);
}
node ask(int k,int l,int r,int x,int y){
	if (l==x&&r==y) return t[k];
	int mid=(l+r)/2;
	if (y<=mid) return ask(k*2,l,mid,x,y);
	if (x>mid) return ask(k*2+1,mid+1,r,x,y);
	return merge(ask(k*2,l,mid,x,mid),ask(k*2+1,mid+1,r,mid+1,y)); 
}
signed main(){
	freopen("seg.in","r",stdin);
	freopen("seg.out","w",stdout);
	n=read(); q=read();
	int LZH=0-1;
	for (int i=1;i<=n;i++) a[i]=read();
	build(1,1,n);
	while (q--){
		fl=read(); x=read(); y=read();
		if (fl==1) change(1,1,n,x,y);
		else if (x==y) write(a[x]),puts("");
		else{
			int ans=0;
			node lzh=ask(1,1,n,x+1,y);
			for (int i=0;i<32;i++)
				ans+=(1u<<i)*lzh.a[i][(a[x]>>i)&1];
			write(ans),puts("");
		}
	}
} 
