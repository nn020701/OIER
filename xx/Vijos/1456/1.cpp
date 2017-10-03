#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1;ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int n;
int f[17][65540];
int mp[17][17];

int dfs(int d,int x){
	if(d == (1<<n)-1) return 0;
	if(f[x][d] != -1) return f[x][d];
	int ans = 1e9;
	for(int i = 0;i < n;i++)
		if(!(d&(1<<i)))
			ans = min(ans,mp[x][i+1]+dfs(d|(1<<i),i+1));
	f[x][d] = ans;
	return f[x][d];
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			mp[i][j] = read();
	memset(f,-1,sizeof f);	
	printf("%d\n",dfs(0,0));
	return 0;
}