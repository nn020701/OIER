#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define N 1000005
#define ll long long 
using namespace std;
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0';ch = getchar();}
	return x*f;
}

ll n;
ll h[N];
ll sum[N];
ll v[N];
ll stack[N],top;
ll ans;

signed main(){
	n = read();
	for(ll i = 1;i <= n;i++){
		h[i] = read(); v[i] = read();
	}
	for(ll i = 1;i <= n;i++){
		while(top > 0 && h[stack[top]] <= h[i])
			top--;
		if(top > 0)
			sum[stack[top]] += v[i];
		stack[++top] = i;
	}
	top = 0;
	for(ll i = n;i >= 1;i--){
		while(top > 0 && h[stack[top]] <= h[i])
			top--;
		if(top > 0)
			sum[stack[top]] += v[i];
		stack[++top] = i;
	}
	for(int i = 1;i <= n;++i)
		ans = max(ans,sum[i]);
	printf("%lld\n",ans);
	return 0;
}