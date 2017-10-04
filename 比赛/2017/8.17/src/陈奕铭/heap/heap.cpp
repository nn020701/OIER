#include<iostream>
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

struct matrix{
	ll m[3][3];
	matrix(){
		memset(m,0,sizeof m);
	}
}a,ans,b;
ll n,k;
char s[100005];

matrix mul(matrix a,matrix b){
	matrix ans;
	for(ll i = 1;i <= 2;i++)
		for(ll j = 1;j <= 2;j++)
			if(a.m[i][j])
				for(ll k = 1;k <= 2;k++)
					(ans.m[i][k] += a.m[i][j]*b.m[j][k]) %= mod;
	return ans;
}

matrix mul2(matrix a,matrix b){
	matrix ans;
	for(ll i = 1;i <= 2;i++)
		for(ll j = 1;j <= 2;j++)
			if(a.m[i][j])
				(ans.m[i][k] += a.m[i][j]*b.m[j][1])%= mod;
	return ans;
}

void work(){
	matrix l; l.m[1][1] = 2; l.m[1][2] = 0; l.m[2][1] = 0; l.m[2][2] = 1;
	matrix r; r.m[1][1] = 2; r.m[1][2] = 1; r.m[2][1] = 0; r.m[2][2] = 1;
	matrix p; p.m[1][1] = 5; p.m[1][2] = 1; p.m[2][1] = 0; p.m[2][2] = 3;
	a.m[1][1] = 1; a.m[2][2] = 1;
	for(ll i = 1;i <= n;i++){
		if(s[i] == 'L')
			a = mul(l,a);
		else if(s[i] == 'R')
			a = mul(r,a);
		else if(s[i] == 'P') continue;
		else a = mul(p,a);
	}
}

matrix quickmul(matrix a,ll k){
	matrix ans;
	ans.m[1][1] = 1; ans.m[2][2] = 1;
	while(k){
		if(k & 1) ans = mul(ans,a);
		k >>= 1;
		a = mul(a,a);
	}
	return ans;
}

int main(){
	freopen("heap.in","r",stdin);
	freopen("heap.out","w",stdout);
	scanf("%s",s+1);
	k = read();
	n = strlen(s+1);
	b.m[1][1] = 1;
	b.m[2][1] = 1;
	work();
	a = quickmul(a,k);
	for(ll i = 1;i <= 2;i++)
		for(ll j = 1;j <= 2;j++)
			if(a.m[i][j])
				(ans.m[i][1] += a.m[i][j]*b.m[j][1]) %= mod;
	printf("%lld\n",ans.m[1][1]);
	return 0;
}
