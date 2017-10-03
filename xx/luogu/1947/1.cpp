#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 51
#define M 51
#define T 2505
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,m,k;
int dp[N][M][M];
int f[N][T];
int g[N][M];
int sum[N][M];

int getch(){
	char c = getchar();
	while(c != '0' && c != '1') c = getchar();
	if(c == '1') return 1;
	return 0;
}

int main(){
	n = read(); m = read(); k = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++)
			sum[i][j] = sum[i][j-1]+getch();
	for(int i = 1;i <= n;i++)
		for(int l = 1;l <= m;l++)
			for(int r = l+1;r <= m;r++){
				int a = sum[i][r]-sum[i][l-1];
				int b = r-l+1-a;
				if(a > b)
					for(int p = 1;p <= m;p++)
						dp[i][r][p] = max(dp[i][r][p],dp[i][l-1][p-1]+a);
				else
					for(int p = 1;p <= m;p++)
						dp[i][r][p] = max(dp[i][r][p],dp[i][l-1][p-1]+b);
			}
	for(int i = 1;i <= n;i++)
		for(int p = 1;p <= m;p++)
			for(int j = 1;j <= m;j++)
				g[i][p] = max(g[i][p],dp[i][j][p]);
	for(int i = 1;i <= k;i++)
		for(int j = 1;j <= n;j++)
			for(int p = 0;p <= min(m,i);p++)
				f[j][i] = max(f[j][i],f[j-1][i-p]+g[j][p]);
	printf("%d\n",f[n][k]);
	return 0;
}
