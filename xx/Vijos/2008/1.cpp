#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define eps 1e-6
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

double x[20],y[20];
int n,m;
int f[20][20],d[600000];

double Abs(double a){
	if(a < 0) return -a;
	return a;
}

void work(){
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++){
			double a,b;
			a = (y[i]*x[j]-y[j]*x[i])/(x[i]*x[i]*x[j]-x[j]*x[j]*x[i]);
			if(a >= 0) continue;
			b = (y[j]*x[i]*x[i]-y[i]*x[j]*x[j])/(x[i]*x[i]*x[j]-x[j]*x[j]*x[i]);
			for(int k = 1;k <= n;k++){
				double y1 = a*x[k]*x[k]+b*x[k];
				if(Abs(y1 - y[k]) <= eps)
					f[i][j] |= (1<<(k-1));
			}
		}
	for(int i = 1;i <= n;i++)
		f[i][i] |= (1<<(i-1));
}

void dp(){
	d[0] = 0;
	for(int i = 0;i <= (1<<n)-2;i++){
		int p = 0;
		while(i&(1<<p)) p++;
		p++;
		for(int j = p;j <= n;j++)
			d[i|(f[p][j])] = min(d[i|(f[p][j])],d[i]+1);
	}
}

int main(){
	int t = read();
	while(t--){
		n = read(),m = read();
		memset(f,0,sizeof f);
		memset(d,0x3f,sizeof d);
		for(int i = 1;i <= n;i++)
			scanf("%lf %lf",&x[i],&y[i]);
		work();
		dp();
		printf("%d\n",d[(1<<n)-1]);
	}
	return 0;
}