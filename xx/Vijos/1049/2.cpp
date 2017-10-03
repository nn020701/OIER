#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 105
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
struct Matrix{
	int m[N][N];
	Matrix(){
		memset(m,0,sizeof m);
	}
}a[15],ans,b;

Matrix mul1(Matrix a,Matrix b){
	Matrix ans;
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			if(a.m[i][k])
				for(int j = 1;j <= n;j++)
					ans.m[i][j] += a.m[i][k]*b.m[k][j];
	return ans;
}

Matrix mul2(Matrix a,Matrix b){
	Matrix ans;
	for(int k = 1;k <= n;k++)
		for(int i = 1;i <= n;i++)
			if(a.m[i][k])
				ans.m[i][1] += a.m[i][k]*b.m[k][1];
	return ans;
}

Matrix quick(Matrix a,int k){
	Matrix ans;
	for(int i = 1;i <= n;i++)
		ans.m[i][i] = 1;
	while(k){
		if(k&1) ans = mul1(ans,a);
		k >>= 1;
		a = mul1(a,a);
	}
	return ans;
}

int main(){
	n = read(); m = read(); k = read();
	for(int i = 1;i <= m;i++){
		for(int j = 1;j <= n;j++){
			int x = read();
			a[i].m[j][x] = 1;
		}
	}
	for(int i = 2;i <= m;i++)
		a[i] = mul1(a[i],a[i-1]);
//	for(int i = 1;i <= n;i)
	ans = quick(a[m],k/m);
	if(k%m != 0)
		ans = mul1(a[k%m],ans);
/*	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= n;j++)
			printf("%d ",ans.m[i][j]);*/
	for(int i = 1;i <= n;i++)
		b.m[i][1] = i;
	ans = mul2(ans,b);
	for(int i = 1;i < n;i++)
		printf("%d ",ans.m[i][1]);
	printf("%d\n",ans.m[n][1]);
	return 0;
}
