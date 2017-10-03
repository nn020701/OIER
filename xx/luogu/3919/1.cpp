#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define M 20000005
#define N 1000005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

int n,m,cnt;
int root[N];
int x[N];
struct node{
	int lson,rson;
	int v;
}num[M];

void build(int &root,int l,int r){
	if(!root) root = ++cnt;
	if(l == r){
		num[root].v = x[l];
		return;
	}
	int mid = (l+r)>>1;
	build(num[root].lson,l,mid);
	build(num[root].rson,mid+1,r);
}

void modify(int &root1,int root2,int l,int r,int x,int v){
	root1 = ++cnt;
	num[root1] = num[root2];
	if(l == r){
		num[root1].v = v;
		return;
	}
	int mid = (l+r)>>1;
	if(x <= mid) modify(num[root1].lson,num[root2].lson,l,mid,x,v);
	else modify(num[root1].rson,num[root2].rson,mid+1,r,x,v);
}

int query(int root,int l,int r,int x){
	if(l == r)
		return num[root].v;
	int mid = (l+r)>>1;
	if(x <= mid) return query(num[root].lson,l,mid,x);
	return query(num[root].rson,mid+1,r,x);
}

int main(){
	n = read(); m = read();
	for(int i = 1;i <= n;i++)
		x[i] = read();
	build(root[0],1,n);
	for(int i = 1;i <= m;i++){
		int k = read(),opt = read();
		if(opt == 1){
			int x = read(),y = read();
			modify(root[i],root[k],1,n,x,y);
		}
		else{
			int x = read();
			root[i] = root[k];
			printf("%d\n",query(root[i],1,n,x));
		}
	}
	return 0;
}