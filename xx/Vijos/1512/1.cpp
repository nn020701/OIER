#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define lowbit(x) (x&(-x))
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

ll n,m;
ll t[1025][1025];

void addup(ll x,ll y,ll k){
	for(ll i = x;i <= n;i += lowbit(i))
		for(ll j = y;j <= n;j += lowbit(j))
			t[i][j] += k;
}

ll sum(ll x,ll y){
	ll ans = 0;
	for(ll i = x;i >= 1;i -= lowbit(i))
		for(ll j = y;j >= 1;j -= lowbit(j))
			ans += t[i][j];
	return ans;
}

ll query(ll x1,ll y1,ll x2,ll y2){
	ll ans1 = sum(x1-1,y1-1);
	ll ans2 = sum(x1-1,y2);
	ll ans3 = sum(x2,y1-1);
	ll ans4 = sum(x2,y2);
	return ans4-ans2-ans3+ans1;
}

int main(){
	n = read();
	while(1){
		m = read();
		if(m == 1){
			int x = read()+1,y = read()+1,k = read();
			addup(x,y,k);
		}
		else if(m == 2){
			int x1 = read()+1,y1 = read()+1,x2 = read()+1,y2 = read()+1;
			printf("%lld\n",query(x1,y1,x2,y2));
		}
		else break;
	}
	return 0;
}