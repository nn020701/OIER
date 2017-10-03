#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 505
#define M 105
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

char s[N];
int f[N][M][M];
int n,m,ans;

int main(){
	n = read(); m = read();
	scanf("%s",s+1);
	memset(f,-0x3f,sizeof f);
	f[0][0][0] = f[1][0][0] = 0;
	if(s[1] == 'z') f[1][0][1] = 0;
	else f[1][1][0] = 0;
	for(int i = 2;i <= n;i++)
		for(int j = 0;j <= m;j++)
			for(int k = 0;k <= m;k++){
				f[i][j][k] = f[i-1][j][k];
				if(s[i] == 'z' && s[i-1] == 'j') f[i][j][k] = max(f[i][j][k],f[i-2][j][k]+1);
				if(s[i] == 'z' && s[i-1] == 'z' && k) f[i][j][k] = max(f[i][j][k],f[i-2][j][k-1]+1);
				if(s[i] == 'j' && s[i-1] == 'j' && j) f[i][j][k] = max(f[i][j][k],f[i-2][j-1][k]+1);
				if(s[i] == 'j' && s[i-1] == 'z' && j && k) f[i][j][k] = max(f[i][j][k],f[i-2][j-1][k-1]+1);
				if(j == k) ans = max(ans,f[i][j][k]);
			}
	printf("%d\n",ans);
	return 0;
}
