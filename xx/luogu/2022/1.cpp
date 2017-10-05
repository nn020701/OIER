#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 100005
#define ll long long 
using namespace std;
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

ll k,m,base,num,c,p;

void get(){
	base = 1;
	ll x = k;
	while(x){
		x /= 10;
		base *= 10;
	}
	base /= 10;
	ll Base = base;
	x = k;
	while(x){
		num += x-Base+1;
		x /= 10;
		Base /= 10;
	}
	num--;
}

signed main(){
	k = read(); m = read();
	get();
	if(num > m-1 || (k == base && num < m-1)){
		printf("0\n");
		return 0;
	}
	c = k;
	p = k-base;
	while(num < m-1){
		c *= 10;
		p *= 10;
		num += p;
	}
	printf("%lld\n",max(k,c-1-(num-(m-1))));
	return 0;
}