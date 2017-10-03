#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 200005
#define M 10000005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,cnt;
int root[N];
struct node{
	int lson,rson,deep,f;
}t[M];

void build(int &root,int l,int r){
	if(!root) root = ++cnt;
	if(l == r){
		t[root].deep = 1;
		t[root].f = l;
		return;
	}
	int mid = (l+r)>>1;
	build(t[root].lson,l,mid);
	build(t[root].rson,mid+1,r);
}

void link(int &root1,int root2,int l,int r,int fa,int fb){
	root1 = ++cnt;
	t[root1] = t[root2];
	if(l == r){
		t[root1].f = fb;
		return;
	}
	int mid = (l+r)>>1;
	if(mid >= fa) link(t[root1].lson,t[root2].lson,l,mid,fa,fb);
	else link(t[root1].rson,t[root2].rson,mid+1,r,fa,fb);
}

int query(int root,int l,int r,int x){
	if(l == r) return root;
	int mid = (l+r)>>1;
	if(mid >= x) return query(t[root].lson,l,mid,x);
	else return query(t[root].rson,mid+1,r,x);
}

int find(int root,int x){
	int f = query(root,1,n,x);
	if(t[f].f == x) return f;
	return find(root,t[f].f);
}

void add(int root,int l,int r,int x){
	if(l == r){
		t[root].deep++;
		return;
	}
	int mid = (l+r)>>1;
	if(mid >= x) add(t[root].lson,l,mid,x);
	else add(t[root].rson,mid+1,r,x);
}

int main(){
	n = read(); m = read(); int ans = 0;
	build(root[0],1,n);
	for(int i = 1;i <= m;i++){
		int opt = read();
		if(opt == 1){
			int a = read()^ans,b = read()^ans;
			int fa = find(root[i-1],a);
			int fb = find(root[i-1],b);
			if(t[fa].f == t[fb].f) continue;
			if(t[fa].deep > t[fb].deep) swap(fa,fb);
			link(root[i],root[i-1],1,n,t[fa].f,t[fb].f);
			if(t[fb].deep == t[fb].deep) add(root[i],1,n,t[fb].f);
		}
		else if(opt == 2){
			int x = read()^ans;
			root[i] = root[x];
		}
		else{
			int a = read()^ans,b = read()^ans;
			root[i] = root[i-1];
			int fa = find(root[i],a);
			int fb = find(root[i],b);
			if(t[fa].f == t[fb].f) ans = 1;
			else ans = 0;
			printf("%d\n",ans);
		}
	}
	return 0;
}
