#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define mod 12345678
#define inf 0x7fffffff
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
int t;
int f[305][155][25][25];
int ans;

int main(){
	n = read(); m = read(); k = read();
	t = n+m;
	f[0][0][0][0] = 1;
	for(int i = 0;i < n+m;i++)
		for(int j = 0;j <= n;j++)
			for(int x = 0;x <= k;x++)
				for(int y = 0;y <= k;y++){
					if(f[i][j][x][y]){
						if(x+1 <= k && j+1 <= n)
							(f[i+1][j+1][x+1][max(y-1,0)] += f[i][j][x][y]) %= mod;
						if(y+1 <= k && i+1-j <= m)
							(f[i+1][j][max(x-1,0)][y+1] += f[i][j][x][y]) %= mod;
					}
				}
	for(int i = 0;i <= n;i++)
		for(int x = 0;x <= k;x++)
			for(int y = 0;y <= k;y++)
				(ans += f[n+m][i][x][y]) %= mod;
	printf("%d\n",ans);
	return 0;
}
