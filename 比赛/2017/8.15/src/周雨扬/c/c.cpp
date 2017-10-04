#include<bits/stdc++.h>
#define N 100005
#define M 4000005
using namespace std;
int ls[M],rs[M],one[M],zero[M],sz;
int sum[N*4],tag[N*4],rt[N];
int n,q;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	for (;ch<'0'||ch>'9';ch=getchar())
		if (ch=='-') f=-1;
	for (;ch>='0'&&ch<='9';ch=getchar())
		x=x*10-48+ch;
	return x*f;
}
void build(int k,int l,int r){
	sum[k]=r-l+1; tag[k]=2;
	if (l==r) return;
	int mid=(l+r)/2;
	build(k*2,l,mid);
	build(k*2+1,mid+1,r);
}
void pushdown(int k,int l,int r){
	if (!tag[k]){
		tag[k*2]=tag[k*2+1]=0;
		sum[k*2]=sum[k*2+1]=0;
		tag[k]=2;
	}
	int mid=(l+r)/2;
	if (tag[k]==1){
		tag[k*2]=tag[k*2+1]=1;
		sum[k*2]=mid-l+1;
		sum[k*2+1]=r-mid;
		tag[k]=2;
	}
}
void laugh(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		tag[k]=sum[k]=0;
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)/2;
	if (y<=mid) laugh(k*2,l,mid,x,y);
	else if (x>mid) laugh(k*2+1,mid+1,r,x,y);
	else laugh(k*2,l,mid,x,mid),laugh(k*2+1,mid+1,r,mid+1,y);
	sum[k]=sum[k*2]+sum[k*2+1];
}
void sit(int k,int l,int r,int x,int y){
	if (l==x&&r==y){
		tag[k]=1;
		sum[k]=r-l+1;
		return;
	}
	pushdown(k,l,r);
	int mid=(l+r)/2;
	if (y<=mid) sit(k*2,l,mid,x,y);
	else if (x>mid) sit(k*2+1,mid+1,r,x,y);
	else sit(k*2,l,mid,x,mid),sit(k*2+1,mid+1,r,mid+1,y);
	sum[k]=sum[k*2]+sum[k*2+1];
}
void work(int &k,int l,int r,int x,int y){
	if (!k) k=++sz,zero[k]=1,one[k]=0;
	if (l==x&&r==y){
		if (zero[k]&&!one[k]){
			one[k]=1; zero[k]=0;
			laugh(1,1,n,x,y);
			return;
		}
	}
	if (!zero[k]&&one[k]){
		sit(1,1,n,x,y);
		return;
	}
	int mid=(l+r)/2;
	if (y<=mid) work(ls[k],l,mid,x,y);
	else if (x>mid) work(rs[k],mid+1,r,x,y);
	else work(ls[k],l,mid,x,mid),work(rs[k],mid+1,r,mid+1,y);
	zero[k]=zero[ls[k]]|zero[rs[k]];
	one[k]=one[ls[k]]|one[rs[k]];
}
int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	n=read(); q=read();
	zero[0]=one[0]=1;
	build(1,1,n);
	while (q--){
		int x,fl,d,l,r;
		x=read(); fl=read(); d=read();
		l=max(1,x-d);
		r=min(n,x+d);
		work(rt[fl],1,n,l,r);
	}
	printf("%d",sum[1]);
}
