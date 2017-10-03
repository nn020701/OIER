#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 155
#define INF 100000000
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

double dist[N][N];
double edge[N][N];
double f[N];
double ans1,ans2 = INF;
int n;
double x[N],y[N];

int main(){
	n = read();
	for(int i = 1;i <= n;++i){
		x[i] = read(); y[i] = read();
	}
	// for(int i = 1;i <= n;++i)
	// 	printf("%.6lf %.6lf\n",x[i],y[i]);
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			edge[i][j] = sqrt(double((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])));
	// for(int i = 1;i <= n;++i,puts(""))
	// 	for(int j = 1;j <= n;++j)
	// 		printf("%.6lf ", edge[i][j]);
	for(int i = 1;i <= n;++i){
		char s[N];
		scanf("%s",s+1);
		for(int j = 1;j <= n;++j){
			if(s[j] == '1') dist[i][j] = edge[i][j];
			else dist[i][j] = INF;
		}
	}
	for(int i = 1;i <= n;++i)
		dist[i][i] = 0;
	for(int k = 1;k <= n;++k)
		for(int i = 1;i <= n;++i)
			for(int j = 1;j <= n;++j)
				if(dist[i][k] != INF && dist[k][j] != INF)
					if(dist[i][j] > dist[i][k]+dist[k][j])
						dist[i][j] = dist[i][k]+dist[k][j];
	for(int i = 1;i <= n;++i){
		for(int j = 1;j <= n;++j)
			if(dist[i][j] != INF)
				f[i] = max(f[i],dist[i][j]);
		ans1 = max(ans1,f[i]);
	}
	// for(int i = 1;i <= n;++i,puts(""))
	// 	for(int j = 1;j <= n;++j)
	// 		printf("%.6lf ", dist[i][j]);
	for(int i = 1;i <= n;++i)
		for(int j = 1;j <= n;++j)
			if(dist[i][j] == INF)
				ans2 = min(ans2,f[i]+edge[i][j]+f[j]);
	ans1 = max(ans1,ans2);
	printf("%.6lf\n",ans1);
	return 0;
}