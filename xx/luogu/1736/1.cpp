#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 2505
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int f1[N][N];
int f2[N][N];
int l1[N][N];
int h1[N][N],h2[N][N];
int n,m,ans;
bool num[N][N];

int main(){
	n = read(); m = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			int x = read();
			if(x == 1) num[i][j] = true;
		}
	for(int i = 1;i <= m;i++)
		if(num[1][i] == 1){
			ans = 1;
			f1[1][i] = f2[1][i] = 1;
		}
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= m;j++){
			if(num[i][j])
				h1[i][j] = 0;
			else
				h1[i][j] = h1[i][j-1]+1;
		}
	for(int i = 1;i <= n;i++)
		for(int j = m;j >= 1;j--){
			if(num[i][j])
				h2[i][j] = 0;
			else
				h2[i][j] = h2[i][j+1]+1;
		}

	for(int j = 1;j <= m;j++)
		for(int i = 1;i <= n;i++)
			if(num[i][j])
				l1[i][j] = 0;
			else
				l1[i][j] = l1[i-1][j]+1;
/*	puts("");
	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= m;j++)
			printf("%d ",h1[i][j]);
	puts("");
	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= m;j++)
			printf("%d ",h2[i][j]);
	puts("");
	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= m;j++)
			printf("%d ",l1[i][j]);*/
	for(int i = 2;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(num[i][j]){
				f1[i][j] = min(f1[i-1][j-1],min(l1[i-1][j],h1[i][j-1]))+1;
			}
			ans = max(ans,f1[i][j]);
		}
	}
	for(int i = 2;i <= n;i++)
		for(int j = 1;j <= m;j++){
			if(num[i][j]){
				f2[i][j] = min(f2[i-1][j+1],min(l1[i-1][j],h2[i][j+1]))+1;
			}
			ans = max(ans,f2[i][j]);
		}
/*	puts("");
	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= m;j++)
			printf("%d ",f1[i][j]);
	puts("");
	for(int i = 1;i <= n;i++,puts(""))
		for(int j = 1;j <= m;j++)
			printf("%d ",f2[i][j]);*/
	printf("%d\n",ans);
	return 0;
}