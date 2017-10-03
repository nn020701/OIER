#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define ll long long
#define N 2010
#define V 310
inline int read(){
    int x = 0,f = 1;char ch = getchar();
    while(ch<'0' || ch>'9'){if(ch=='-')f = -1;ch = getchar();}
    while(ch>='0' && ch<='9'){x = x*10+ch-'0';ch = getchar();}
    return x*f;
}

int m,n,v,e;
int a[N],b[N];
double dist[V][V];
double c[N];
double f[N][N][2];

inline void init(){
	for(int i = 0;i < V;i++)
		for(int j = 0;j < V;j++)
			if(i == j) dist[i][j] = 0;
			else dist[i][j] = 1e9;
	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
			f[i][j][0] = f[i][j][1] = 1e9;
	f[1][0][0] = 0; f[1][1][1] = 0;
}

inline void floyd(){
	for(int k = 1;k <= v;k++)
		for(int i = 1;i <= v;i++)
			for(int j = 1;j <= v;j++)
				dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

int main(){
	init();
    scanf("%d%d%d%d", &n, &m, &v, &e);
    for (int i = 1;i <= n;i++) scanf("%d", &a[i]);
    for (int i = 1;i <= n;i++) scanf("%d", &b[i]);
    for (int i = 1;i <= n;i++) scanf("%lf", &c[i]);
	for(int i = 1;i <= e;i++){
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		if(x == y) continue;
		if(w < dist[x][y]){
			dist[x][y] = dist[y][x] = w;
		}
	}
	floyd();
	for(int i = 2;i <= n;i++){
		f[i][0][0] = f[i-1][0][0]+dist[a[i-1]][a[i]];
		for(int j = 1;j <= min(i,m);j++){
			f[i][j][0] = min(f[i-1][j][0]+dist[a[i-1]][a[i]],f[i-1][j][1]+dist[a[i-1]][a[i]]*(1.0-c[i-1])+dist[b[i-1]][a[i]]*c[i-1]);
			f[i][j][1] = f[i-1][j-1][0]+dist[a[i-1]][a[i]]*(1.0-c[i])+dist[a[i-1]][b[i]]*c[i];
			double t = f[i-1][j-1][1]+dist[a[i-1]][a[i]]*(1.0-c[i-1])*(1.0-c[i]);	//两次都没申请成功
			t += dist[b[i-1]][a[i]]*(1.0-c[i])*c[i-1];	//第一次申请成功
			t += dist[a[i-1]][b[i]]*(1.0-c[i-1])*c[i];	//第二次申请成功
			t += dist[b[i-1]][b[i]]*c[i]*c[i-1];	//两次都申请成功
			f[i][j][1] = min(f[i][j][1],t);
		}
	}
	double ans = f[n][0][0];
	for(int i = 1;i <= m;i++){
		ans = min(ans,f[n][i][0]);
		ans = min(ans,f[n][i][1]);
	}
	printf("%.2lf\n",ans);
	return 0;
}