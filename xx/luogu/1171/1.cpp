#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define inf 1000000000
#define min(x,y) ((x) < (y) ? (x) : (y))
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){ if(ch == '-') f = -1; ch = getchar(); }
	while(ch >= '0' && ch <= '9'){ x = x*10+ch-'0'; ch = getchar(); }
	return x*f;
}

int n,m,ans;	//×Ü×´Ì¬Êý 
int map[25][25];
int dist[1<<20][21];
int wei,k;

int main(){
	n = read(); m = (1<<n)-1;
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			map[i][j] = read();
	for(int i = 1;i <= m;i += 2)
		for(int j = 1;j <= n;j++)
			dist[i][j] = inf;
	wei = 4; k = 2;
	dist[1][1] = 0;
	for(int i = 3;i <= m;i += 2){
		if(i > wei){
			wei <<= 1;
			k++;
		}
		for(int j = 2;j <= k;j++){
			if((i>>j-1)&1){
				int s = i^(1<<j-1);
				for(int l = 1;l < j;l++)
					dist[i][j] = min(dist[i][j],dist[s][l]+map[l][j]);
				for(int l = j+1;l <= k;l++)
					dist[i][j] = min(dist[i][j],dist[s][l]+map[l][j]);
			}
		}
	}
	ans = inf;
	for(int i = 2;i <= n;i++)
		ans = min(ans,dist[m][i]+map[i][1]);
	printf("%d\n",ans);
	return 0;
}
