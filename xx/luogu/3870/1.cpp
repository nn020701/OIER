#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 100000
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

struct node{
	int l,r;
	int sum1,sum0;
	int lsum1,lsum0;
	int rsum1,rsum0;
	int max1,max0;
	bool rev;
	int flag;
}t[N*4];
int n,m,a[N];

void updata(int num){
	int lson = num<<1,rson = num<<1|1;
	t[num].sum0 = t[lson].sum0+t[rson].sum0;
	t[num].sum1 = t[lson].sum1+t[rson].sum1;
	
	if(t[lson].lsum1 == t[lson].r-t[lson].l+1)
		t[num].lsum1 = t[lson].lsum1+t[rson].lsum1;
	else t[num].lsum1 = t[lson].lsum1;
	if(t[rson].rsum1 == t[rson].r-t[rson].l+1)
		t[num].rsum1 = t[rson].rsum1+t[lson].rsum1;
	else t[num].rsum1 = t[rson].rsum1;

	if(t[lson].lsum0 == t[lson].r-t[lson].l+1)
		t[num].lsum0 = t[lson].lsum0+t[rson].lsum0;
	else t[num].lsum0 = t[lson].lsum0;
	if(t[rson].rsum0 == t[rson].r-t[rson].l+1)
		t[num].rsum0 = t[rson].rsum0+t[lson].rsum0;
	else t[num].rsum0 = t[rson].rsum0;
	
	t[num].max1 = max(t[lson].max1,t[rson].max1);
	t[num].max1 = max(t[lson].rsum1+t[rson].lsum1,t[num].max1);
	
	t[num].max0 = max(t[lson].max0,t[rson].max0);
	t[num].max0 = max(t[lson].rsum0+t[rson].lsum0,t[num].max0);
	return;
}

void downdata(int num){
	int lson = num<<1,rson = num<<1|1;
	if(t[num].flag == 1){
		t[num].flag = -1;
		t[lson].flag = t[rson].flag = 1;
		t[lson].rev = t[rson].rev = false;
		t[lson].lsum1 = t[lson].rsum1 = t[lson].max1 = t[lson].sum1 = t[lson].r-t[lson].l+1;
		t[lson].lsum0 = t[lson].rsum0 = t[lson].max0 = t[lson].sum0 = 0;
		t[rson].lsum1 = t[rson].rsum1 = t[rson].max1 = t[rson].sum1 = t[rson].r-t[rson].l+1;
		t[rson].lsum0 = t[rson].rsum0 = t[rson].max0 = t[rson].sum0 = 0;
	}
	else if(t[num].flag == 0){
		t[num].flag = -1;
		t[lson].flag = t[rson].flag = 0;
		t[lson].rev = t[rson].rev = false;
		t[lson].lsum1 = t[lson].rsum1 = t[lson].max1 = t[lson].sum1 = 0;
		t[lson].lsum0 = t[lson].rsum0 = t[lson].max0 = t[lson].sum0 = t[lson].r-t[lson].l+1;
		t[rson].lsum1 = t[rson].rsum1 = t[rson].max1 = t[rson].sum1 = 0;
		t[rson].lsum0 = t[rson].rsum0 = t[rson].max0 = t[rson].sum0 = t[rson].r-t[rson].l+1;
	}
	if(t[num].rev){
		t[num].rev = false;
		t[lson].rev ^= 1; t[rson].rev ^= 1;
		swap(t[lson].sum1,t[lson].sum0);
		swap(t[lson].max1,t[lson].max0);
		swap(t[lson].lsum1,t[lson].lsum0);
		swap(t[lson].rsum1,t[lson].rsum0);

		swap(t[rson].sum1,t[rson].sum0);
		swap(t[rson].max1,t[rson].max0);
		swap(t[rson].lsum1,t[rson].lsum0);
		swap(t[rson].rsum1,t[rson].rsum0);
	}
}

void build(int l,int r,int num){
	t[num].l = l; t[num].r = r;
	t[num].rev = false; t[num].flag = -1;
	if(l == r){
		t[num].sum1 = t[num].lsum1 = t[num].rsum1 = t[num].max1 = 0;
		t[num].sum0 = t[num].lsum0 = t[num].rsum0 = t[num].max0 = 1;			
		return;
	}
	int mid = (l+r)>>1;
	build(l,mid,num<<1);
	build(mid+1,r,num<<1|1);
	updata(num);
	return;
}

void reverse(int x,int y,int num){
	if(t[num].l >= x && t[num].r <= y){
		t[num].rev ^= 1;
		swap(t[num].sum1,t[num].sum0);
		swap(t[num].max1,t[num].max0);
		swap(t[num].lsum1,t[num].lsum0);
		swap(t[num].rsum1,t[num].rsum0);
		return;
	}
	downdata(num);
	int mid = (t[num].l+t[num].r)>>1;
	if(x <= mid) reverse(x,y,num<<1);
	if(y > mid) reverse(x,y,num<<1|1);
	updata(num);
	return;
}

int query(int x,int y,int num){
	if(t[num].l >= x && t[num].r <= y)
		return t[num].sum1;
	downdata(num);
	int mid = (t[num].l+t[num].r)>>1;
	int ans = 0;
	if(x <= mid) ans += query(x,y,num<<1);
	if(y > mid) ans += query(x,y,num<<1|1);
	return ans;
}

int main(){
	n = read(); m = read();
	build(1,n,1);
	for(int i = 1;i <= m;i++){
		int opt = read(),a = read(),b = read();
		if(opt == 0) reverse(a,b,1);
		else if(opt == 1) printf("%d\n",query(a,b,1));
	}
	return 0;
}
