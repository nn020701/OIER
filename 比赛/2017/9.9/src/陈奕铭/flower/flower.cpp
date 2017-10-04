#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define mod 1000000007
#define M 105

inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n,m;
ll ans;

struct Matrix{
	ll a[M][M];
	Matrix(){
		memset(a,0,sizeof a);
	}
}a;

Matrix cheng(Matrix a,Matrix b){
	Matrix ans;
	for(int k = 0;k <= m;k++)
		for(int i = 0;i <= m;i++)
			if(a.a[i][k] > 0)
				for(int j = 0;j <= m;j++)
					ans.a[i][j] = (ans.a[i][j] + a.a[i][k]*b.a[k][j]%mod)%mod;
	return ans;
}

Matrix kuaisu(int n,Matrix x){
	Matrix ans;
	for(int i = 0;i <= m;i++)
		ans.a[i][i] = 1;
	while(n){
		if(n & 1)
			ans = cheng(ans,x);
		x = cheng(x,x);
		n >>= 1;
	}
	return ans;
}

int main(){
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
	n = read(); m = read();
	for(int i = 1;i <= m;i++){
		char s[M];
		scanf("%s",s+1);
		for(int j = 1;j <= m;j++)
			if(s[j] == '0')
				a.a[i][j] = 1;
	}
	for(int i = 1;i <= m;i++)
		a.a[0][i] = a.a[i][0] = 1;
	a.a[0][0] = 1;
	a = kuaisu(n,a);

	for(int i = 0;i <= m;i++)
		ans = (ans + a.a[0][i])%mod;
	printf("%lld\n",ans);
	return 0;
}