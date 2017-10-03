#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

ll f[81][520][21];
ll n,m,k;
ll zhuan[520],cnt,num[520];

ll gcd(ll x,ll y){
	if(y == 0) return x;
	return gcd(y,x%y);
}

void calc(ll a,ll b,ll ans){
	ll res = 1,k,re = 1;
	for(ll i = 2;i <= a;i++)
		res *= i;
	for(ll i = b;i > b-a;i--){
		re *= i;
		k = gcd(re,res);
		res /= k; re /= k;
	}
	k = gcd(ans,re);
	ans /= k; re /= k;
	printf("%lld/%lld\n",re,ans*res);
}

int main(){
	n = read(); m = read(); k = read();
	if(n < m) swap(n,m);
	for(ll i = 0;i < (1<<m);i++)
		if(!(i&(i<<1))){
			zhuan[++cnt] = i;
			ll j = i;
			while(j){
				if(j&1) num[cnt]++;
				j >>= 1;
			}
		}
	for(ll i = 1;i <= cnt;i++)
		f[1][i][num[i]] = 1;
	for(ll l = 2;l <= n;l++)
		for(ll i = 1;i <= cnt;i++)
			for(ll j = 1;j <= cnt;j++)
				if(!(zhuan[i]&zhuan[j]))
					for(ll z = 0;z <= k-num[i];z++)
						f[l][i][z+num[i]] += f[l-1][j][z];
	ll ans = 0;
	for(int i = 1;i <= cnt;i++)
		ans += f[n][i][k];
	if(ans == 0) printf("Impossible!\n");
	else calc(k,n*m,ans);
	return 0;
}