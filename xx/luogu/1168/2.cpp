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

int n,cnt;
int d[N];
int p[N];
struct node{
	int l,r,sum;
}t[N*4];

int erfen(int x){
	int l = 1,r = n;
	int mid;
	while(l < r){
		mid = (l+r+1)>>1;
		if(d[mid] > x) r = mid-1;
		else l = mid;
	}
	return l;
}

void build(int l,int r,int num){
	t[num].l = l; t[num].r = r; t[num].sum = 0;
	if(l == r) return;
	int mid = (l+r)>>1;
	build(l,mid,num<<1);
	build(mid+1,r,num<<1|1);
	return;
}

void updata(int num){
	t[num].sum = t[num<<1].sum+t[num<<1|1].sum;
}

void add(int num,int x){
	if(t[num].l == t[num].r){
		t[num].sum++;
		return;
	}
	int mid = (t[num].l+t[num].r)>>1;
	if(x <= mid) add(num<<1,x);
	else add(num<<1|1,x);
	updata(num);
}

int query(int num,int x){
	if(t[num].l == t[num].r)
		return t[num].l;
	if(t[num<<1].sum < x) return query(num<<1|1,x-t[num<<1].sum);
	else return query(num<<1,x);
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		d[i] = p[i] = read();
	sort(d+1,d+n+1);
	cnt = 1;
	for(int i = 2;i <= n;i++)
		if(d[i] != d[i-1])
			d[++cnt] = d[i];
	for(int i = 1;i <= n;i++)
		p[i] = erfen(p[i]);
	build(1,cnt,1);
	printf("%d\n",d[p[1]]);
	add(1,p[1]);
	for(int k = 2;k <= (n+1)>>1;k++){
		add(1,p[k*2-2]);
		add(1,p[k*2-1]);
		int o = query(1,k);
		printf("%d\n",d[o]);
	}
	return 0;
}
