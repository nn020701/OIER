#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<cstdlib>
#define ls x*2
#define rs x*2+1
#define N 200200 
using namespace std;

inline int read(){
	int x=0;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar());
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=x*10-48+ch;
	return x;
}

inline void write(int x){
	static int a[12],top;
	top=0;
	for (;x;x/=10)
		a[++top]=x%10;
	for (;top;--top)
		putchar('0'+a[top]);
	puts("");
}

// I / O ÓÅ »¯ 

struct node{
	int l,r,tag,lc,rc,sum;
}t[N*4];

int n,cnt,m,x,y,z,ans,rev=0,mov=0,co[N];
char ch;

inline void get(int &a){
	if (rev) a=n-a+2;
	a-=mov;
	for (;a>n;a-=n);
	for (;a<1;a+=n);
}

inline void pushup(int x){
	t[x].lc=t[ls].lc;
	t[x].rc=t[rs].rc;
	t[x].sum=t[ls].sum+t[rs].sum;
	if (t[ls].rc==t[rs].lc) t[x].sum--;
}

inline void pushdown(int x){
	if (!t[x].tag) return;
	t[ls].tag=t[rs].tag=t[x].tag;
	t[ls].lc=t[ls].rc=t[rs].lc=t[rs].rc=t[x].tag;
	t[ls].sum=t[rs].sum=1;
	t[x].tag=0;
}

inline node merge(node a,node b){
	node tmp;
	tmp.sum=a.sum+b.sum;
	tmp.lc=a.lc; tmp.rc=b.rc;
	if (a.rc==b.lc) tmp.sum--;
	return tmp;
}

void build(int x,int l,int r){
	t[x].l=l; t[x].r=r;
	t[x].tag=0;
	if (l==r){
		t[x].lc=t[x].rc=t[x].tag=co[l];
		t[x].sum=1;
		return;
	}
	int mid=(l+r)/2;
	build(ls,l,mid);
	build(rs,mid+1,r);
	pushup(x);
}

int color(int x,int y){
	int l=t[x].l,r=t[x].r,mid=(l+r)/2;
	if (l==r) return t[x].lc;
	pushdown(x);
	if (y<=mid) return color(ls,y);
	return color(rs,y);
}

void change(int x,int p,int q,int v){
	int l=t[x].l,r=t[x].r,mid=(l+r)/2;
	if (l==p&&r==q){
		t[x].lc=t[x].rc=t[x].tag=v;
		t[x].sum=1;
		return;
	}
	pushdown(x);
	if (q<=mid) change(ls,p,q,v);
	else if (p>mid) change(rs,p,q,v);
	else change(ls,p,mid,v),change(rs,mid+1,q,v);
	pushup(x);
}

node ask(int x,int p,int q){
	int l=t[x].l,r=t[x].r,mid=(l+r)/2;
	if (l==p&&r==q) return t[x];
	pushdown(x);
	if (q<=mid) return ask(ls,p,q);
	if (p>mid) return ask(rs,p,q);
	return merge(ask(ls,p,mid),ask(rs,mid+1,q));
}

int main(){
	freopen("necklace.in","r",stdin);
	freopen("necklace.out","w",stdout);
	n=read(); read();
	for (int i=1;i<=n;i++) co[i]=read();
	build(1,1,n);
	m=read();
	while (m--){
		ch=getchar();
		while (ch!='R'&&ch!='F'&&ch!='S'&&ch!='P'&&ch!='C')
			ch=getchar();
		if (ch=='R'){
			x=read();
			if (rev) mov-=x; else mov+=x;
			for (;mov>n;mov-=n);
			for (;mov<0;mov+=n);
		}
		if (ch=='F') rev^=1;
		if (ch=='S'){
			x=read(); y=read();
			get(x); get(y);
			int xx=color(1,x),yy=color(1,y);
			change(1,x,x,yy);
			change(1,y,y,xx);
		}
		if (ch=='P'){
			x=read(); y=read(); z=read();
			get(x); get(y);
			if (rev) swap(x,y);
			if (x>y) change(1,x,n,z),change(1,1,y,z);
			else change(1,x,y,z);
		}
		if (ch=='C'){
			ch=getchar(); 
			if (ch=='S'){
				x=read(); y=read();
				get(x); get(y);
				if (rev) swap(x,y);
				if (x<=y){
					ans=ask(1,x,y).sum;
					if (x==1&&y==n&&ans>1&&t[1].lc==t[1].rc) ans--;
				}
				else{
					ans=ask(1,x,n).sum+ask(1,1,y).sum;
					if (t[1].lc==t[1].rc) ans--;
					if (x==y+1&&color(1,x)==color(1,y)&&ans>1) ans--;
				}
			}
			else{
				ans=t[1].sum;
				if (ans>1&&t[1].lc==t[1].rc) ans--;
			}
			write(ans);
		}
	}
}
