#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
#define N 32
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

struct Matrix{
	int a[N][N];
	Matrix(){
		memset(a,0,sizeof a);
	}
}a,ans;
int n,k,m;

Matrix mul(Matrix a,Matrix b){
	Matrix ans;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(a.a[i][j] > 0)
				for(int k = 1;k <= n;k++)
					ans.a[i][k] = (ans.a[i][k]+a.a[i][j]*b.a[j][k])%m;
	return ans;
}

Matrix add(Matrix a,Matrix b){
	Matrix ans;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			ans.a[i][j] = (a.a[i][j]+b.a[i][j])%m;
	return ans;
}

Matrix quickmod(Matrix a,int k){
	Matrix ans;
	for(int i = 1;i <= n;i++)
		ans.a[i][i] = 1;
	while(k){
		if(k & 1) ans = mul(ans,a);
		k >>= 1;
		a = mul(a,a);
	}
	return ans;
}

Matrix solve(Matrix a,int k){
	if(k == 1) return a;
	Matrix ans;
	for(int i = 1;i <= n;i++) ans.a[i][i] = 1;
	ans = add(ans,quickmod(a,k>>1));
	ans = mul(ans,solve(a,k>>1));
	if(k&1) ans = add(ans,quickmod(a,k));
	return ans;
}

int main(){
	n = read(); k = read(); m = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			a.a[i][j] = read();
	ans = solve(a,k);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < n;j++)
			printf("%d ",ans.a[i][j]);
		printf("%d\n",ans.a[i][n]);
	}
	return 0;
}
