#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

ll n,m,l;
ll num,x;

int main(){
	n = read(); m = read(); l = read();
	num = 1;
	if(l%2 == 0) x = l/2;
	else x = l/2+1+n/2;
	while(x != l){
		num++;
		if(x%2 == 0) x = x/2;
		else x = x/2+1+n/2;
	}
	m = m%num;
	while(m--){
		if(l%2 == 0) l = l/2;
		else l = l/2+1+n/2;
	}
	printf("%lld\n",l);
	return 0;
}