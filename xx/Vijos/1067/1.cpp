#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define mod 7777777
inline ll read(){
	ll x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

struct matrix{
	ll m[14][14];
	matrix(){
		memset(m,0,sizeof m);
	}
}a,b;
ll k,n;
ll f[15];

matrix mul(matrix a,matrix b){
	matrix ans;
	for(ll k = 1;k <= n;k++)
		for(ll i = 1;i <= n;i++)
			if(a.m[i][k])
				for(ll j = 1;j <= n;j++)
					ans.m[i][j] = (ans.m[i][j]+a.m[i][k]*b.m[k][j])%mod;
	return ans;
}

matrix quick(matrix a,ll p){
	matrix ans;
	for(ll i = 1;i <= n;i++)
		ans.m[i][i] = 1;
	while(p){
		if(p & 1) ans = mul(ans,a);
		p >>= 1;
		a = mul(a,a);
	}
	return ans;
}

matrix mul2(matrix a,matrix b){
	matrix ans;
	for(ll k = 1;k <= n;k++)
		for(ll i = 1;i <= n;i++)
			if(a.m[i][k])
				ans.m[i][1] = (ans.m[i][1]+a.m[i][k]*b.m[k][1])%mod;
	return ans;
}

int main(){
	n = read(); k = read();
	for(ll i = 1;i < n;i++)
		a.m[i][i+1] = 1;
	for(ll i = 1;i <= n;i++)
		a.m[n][i] = 1;
/*	for(ll i = 1;i <= n;i++,puts(""))
		for(ll j = 1;j <= n;j++)
			printf("%d ",a.m[i][j]);*/
	a = quick(a,k);
	f[1] = 1;
	for(ll i = 1;i <= n;i++)
		for(ll j = 1;j <= i;j++)
			f[i] += f[i-j];
	for(ll i = 1;i <= n;i++)
		b.m[i][1] = f[i];
	b = mul2(a,b);
	printf("%lld\n",b.m[1][1]);
	return 0;
}
