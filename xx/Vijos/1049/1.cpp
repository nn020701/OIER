#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

struct Matrix{
	int m[101][101];
	Matrix(){
		memset(m,0,sizeof m);
	}
}a[11],b,c;
int n,m,k;

Matrix mul(Matrix a,Matrix b){
	Matrix ans;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(a.m[i][j] > 0)
				for(int k = 1;k <= n;k++)
					ans.m[i][k] += a.m[i][j]*b.m[j][k];
	return ans;
}

Matrix mul2(Matrix a,Matrix b){
	Matrix ans;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(a.m[i][j] > 0)
				ans.m[i][1] += a.m[i][j]*b.m[j][1];	
	return ans;
}

Matrix quickmul(Matrix a,int p){
	Matrix ans;
	for(int i = 1;i <= n;i++)
		ans.m[i][i] = 1;
	while(p){
		if(p & 1) ans = mul(ans,a);
		p >>= 1;
		a = mul(a,a);
	}
	return ans;
}

int main(){
	n = read(); m = read(); k = read();
	for(int i = 1;i <= m;i++)
		for(int j = 1;j <= n;j++){
			int x = read();
			a[i].m[j][x] = 1;
		}
	for(int i = 1;i <= n;i++)
		b.m[i][1] = i;
	for(int i = 2;i <= m;i++)
		a[i] = mul(a[i],a[i-1]);			
	Matrix ans = quickmul(a[m],k/m);
	c = mul2(ans,b);
	if(k%m != 0) c = mul2(a[k%m],c);
	for(int i = 1;i <= n;i++)
		printf("%d ",c.m[i][1]);
	return 0;
}
