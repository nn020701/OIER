#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define ll long long
#define N 20005
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

ll n,k;
struct node{
	ll num,w;
}a[N];
ll e[11];

bool cmp1(node a,node b){
	return a.w > b.w || (a.w == b.w && a.num < b.num);
}

int main(){
	n = read(); k = read();
	
	for(ll i = 1;i <= 10;i++)
		e[i] = read();
	for(ll i = 1;i <= n;i++){
		a[i].w = read();
		a[i].num = i;
	}
	sort(a+1,a+n+1,cmp1);
	for(ll i = 1;i <= n;i++){
		a[i].w += e[(i-1)%10+1];
	}
	sort(a+1,a+n+1,cmp1);
	for(ll i = 1;i < k;i++)
		printf("%lld ",a[i].num);
	printf("%lld\n",a[k].num);
	return 0;
}