#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

int root[N],cnt;
struct node{
	int lson,rson,sum;
}t[N<<5];
int a[N],d[N],tot;

int erfen(int x){
	int l = 1,r = tot;
	int mid;
	while(l <= r){
		mid = (l+r)>>1;
		if(d[mid] > x) r = mid-1;
		else l = mid+1;
	}
	return r;
}

void build(int &root,int l,int r){
	root = ++cnt;
	t[root].sum = 0;
	if(l == r) return;
	int mid = (l+r)>>1;
	build(t[root].lson,l,mid);
	build(t[root].rson,mid+1,r);
}

void add(int &root1,int root2,int l,int r,int x){
	root1 = ++cnt;
	t[root1] = t[root2];
	t[root1].sum++;
	if(l == r) return;
	int mid = (l+r)>>1;
	if(mid < x) add(t[root1].rson,t[root2].rson,mid+1,r,x);
	else add(t[root1].lson,t[root2].lson,l,mid,x);
}

int query(int p,int q,int l,int r,int x){
	if(l == r) return l;
	int mid = (l+r)>>1;
	int ans = t[t[q].lson].sum-t[t[p].lson].sum;
	if(ans < x) return query(t[p].rson,t[q].rson,mid+1,r,x-ans);
	else return query(t[p].lson,t[q].lson,l,mid,x);
}

int main(){
	int T = read();
	for(int t = 1;t <= T;t++){
		int n = read(),m = read();
		cnt = 0; tot = 1;
		for(int i = 1;i <= n;i++)
			d[i] = a[i] = read();
		sort(d+1,d+n+1);
		for(int i = 2;i <= n;i++)
			if(d[i] != d[i-1])
				d[++tot] = d[i];
		for(int i = 1;i <= n;i++)
			a[i] = erfen(a[i]);
		build(root[0],1,tot);
		for(int i = 1;i <= n;i++)
			add(root[i],root[i-1],1,tot,a[i]);
		while(m--){
			int l = read(),r = read(),x = read();
			printf("%d\n",d[query(root[l-1],root[r],1,tot,x)]);
		}
	}
	return 0;
}
