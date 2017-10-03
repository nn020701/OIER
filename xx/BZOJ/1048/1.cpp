#include<iostream>
#include<cstdio>
#include<cmath>
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

int a,b,n;
double c[15][15],s[15][15];
double f[11][11][11][11][11];
double ww;

int main(){
	a = read(); b = read(); n = read();
	for(int i = 1;i <= a;i++)
		for(int j = 1;j <= b;j++)
			c[i][j] = read();
	for(int i = 1;i <= a;i++)
		for(int j = 1;j <= b;j++)
			s[i][j] = s[i-1][j]+s[i][j-1]-s[i-1][j-1]+c[i][j];
	memset(f,-1,sizeof f);
	ww = s[a][b]/a*b;
//	solve(1,a,1,b,n);
	printf("%.2lf\n",sqrt(f[1][a][1][b][n]/n));
	return 0;
}
