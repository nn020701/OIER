#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define ll long long
inline int read(){
	int x = 0,f = 1;char ch = getchar();
	while(ch < '0' || ch > '9'){if(ch == '-')f = -1; ch = getchar();}
	while(ch >= '0' && ch <= '9'){x = x*10+ch-'0'; ch = getchar();}
	return x*f;
}

bool vis[10001][10001];

int main(){
	freopen("jz.in","r",stdin);
	freopen("jz.out","w",stdout);
	int n = read(),q = read();
	int ans = 1;
	int x = 1,y = 1;
	vis[x][y] = true;
	while(q--){
		int opt = read(),a = read();
		if(opt == 1){
			for(int i = 1;i <= a;++i){
				--x;
				if(!vis[x][y]){
					ans++;
					vis[x][y] = true;
				}
			}
		}
		else if(opt == 2){
			for(int i = 1;i <= a;++i){
				--y;
				if(!vis[x][y]){
					ans++;
					vis[x][y] = true;
				}
			}
		}
		else if(opt == 3){
			for(int i = 1;i <= a;++i){
				++y;
				if(!vis[x][y]){
					ans++;
					vis[x][y] = true;
				}
			}
		}
		else{
			for(int i = 1;i <= a;++i){
				++x;
				if(!vis[x][y]){
					ans++;
					vis[x][y] = true;
				}
			}
		}
	}
	printf("%d\n",ans);
	return 0;
}
