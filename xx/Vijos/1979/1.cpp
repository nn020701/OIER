#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define ll long long
#define N 200005
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

int deep[N];
int vis[N];
int tp[N];
int ans = 10000000;
int n,cnt;

void bfs(int x){
	deep[x] = 1;
	while(1){
		int y = tp[x];
		if(vis[y] != 0 && vis[y] != vis[x]) return;
		vis[y] = vis[x];
		if(deep[y] != 0){
			ans = min(ans,deep[x]+1-deep[y]);
			return;
		}
		deep[y] = deep[x]+1;
		x = y;
	}
}

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		tp[i] = read();
	for(int i = 1;i <= n;i++)
		if(vis[i] == 0){
			vis[i] = ++cnt;
			bfs(i);
		}
	printf("%d\n",ans);
	return 0;
}