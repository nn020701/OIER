#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
struct Matrix{
	int m[35][35];
	Matrix(){
		memset(m,0,sizeof m);
	}
}a;

Matrix mul(Matrix a,Matrix b){
	Matrix ans;
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			if(a.m[i][k])
				for(int j = 1;j <= n;j++)
					ans.m[i][j] = (ans.m[i][j]+a.m[i][k]*b.m[k][j])%m;
	return ans;
}

Matrix add(Matrix a,Matrix b){
	Matrix ans;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			ans.m[i][j] = (a.m[i][j]+b.m[i][j])%m;
	return ans;
}

Matrix quick(Matrix x,int k){
	Matrix ans;
	for(int i = 1;i <= n;i++)
		ans.m[i][i] = 1;
	while(k){
		if(k&1) ans = mul(ans,x);
		x = mul(x,x);
		k >>= 1;
	}
	return ans;
}

Matrix erfen(Matrix a,int k){
	if(k == 1) return a;
	Matrix b = erfen(a,k/2);
	Matrix ans;
	Matrix x = quick(a,k/2);
	ans = mul(b,x);
	ans = add(ans,b);
	if(k%2 != 0){
		x = quick(a,k);
		ans = add(ans,x);
	}
	return ans;
}

int main(){
	n = read(); k = read(); m = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			a.m[i][j] = read();
	Matrix ans = erfen(a,k);
	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= n;j++)
			printf("%d ",ans.m[i][j]);
	return 0;
}
