#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 105
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

const int p[6][6] = {
	{0},
	{0,5,-1,-2,-1,-3},
	{0,-1,5,-3,-2,-4},
	{0,-2,-3,5,-2,-2},
	{0,-1,-2,-2,5,-1},
	{0,-3,-4,-2,-1,0}
};
int n,m;
int f[N][N];
char s1[N],s2[N];
int a[N],b[N];

int main(){
	scanf("%d%s",&n,s1+1);
	scanf("%d%s",&m,s2+1);
	memset(f,-0x3f,sizeof f);
	for(int i = 1;i <= n;i++)
		if(s1[i] == 'A') a[i] = 1;
		else if(s1[i] == 'C') a[i] = 2;
		else if(s1[i] == 'G') a[i] = 3;
		else a[i] = 4;
	for(int i = 1;i <= m;i++)
		if(s2[i] == 'A') b[i] = 1;
		else if(s2[i] == 'C') b[i] = 2;
		else if(s2[i] == 'G') b[i] = 3;
		else b[i] = 4;
	f[0][0] = 0;
	for(int i = 1;i <= n;i++)
		f[i][0] = f[i-1][0] + p[a[i]][5];
	for(int i = 1;i <= m;i++)	
		f[0][i] = f[0][i-1] + p[b[i]][5];
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			f[i][j] = max(f[i][j],f[i][j-1]+p[b[j]][5]);
			f[i][j] = max(f[i][j],f[i-1][j]+p[a[i]][5]);
			f[i][j] = max(f[i][j],f[i-1][j-1]+p[a[i]][b[j]]);
		}
	printf("%d\n",f[n][m]);
	return 0;
}
