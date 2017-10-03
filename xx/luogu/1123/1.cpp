#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 8
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m;
bool vis[N][N];
int a[N][N];
int ans;

void dfs(int x,int y,int sum){
	if(y > m){
		x++;
		y = 1;
	}
	if(x > n){
		ans = max(ans,sum);
		return;
	}
	if((!vis[x][y-1]) && (!vis[x-1][y-1]) && (!vis[x-1][y]) && (!vis[x-1][y+1])){
		vis[x][y] = true;
		dfs(x,y+2,sum+a[x][y]);
		vis[x][y] = false;
	}
	dfs(x,y+1,sum);
}

int main(){
	int t = read();
	while(t--){
		ans = 0;
		memset(vis,0,sizeof vis);
		n = read(); m = read();
		for(int i = 1;i <= n;i++)
			for(int j = 1;j <= m;j++)
				a[i][j] = read();
		dfs(1,1,0);
		printf("%d\n",ans);
	}
	return 0;
}
