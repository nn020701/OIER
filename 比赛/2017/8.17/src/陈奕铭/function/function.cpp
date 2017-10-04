#include<iostream>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define mod 1000000007
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

ll n,k;

ll phi(ll x){
	ll t = x,num = sqrt(x);
	for(ll i = 2;i <= num;i++){
		if(x%i == 0){
			t -= t/i;
			while(x%i == 0)
				x /= i;
		}
	}
	if(x > 1) t -= t/x;
	return t;
}

int main(){
	freopen("function.in","r",stdin);
	freopen("function.out","w",stdout);
	ll t = read();
	
	while(t--){
		n = read();k = read();
		k = (k+1)/2;
		for(ll i = 1;i <= k;i++){
			n = phi(n);
			if(n == 1)
				break;
		}
		printf("%lld\n",n%mod);
	}
	return 0;
}
