#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 705
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
double x[N],y[N];
double f[N][N];
int ans;

int main(){
	n = read();
	for(int i = 1;i <= n;i++)
		x[i] = read(),y[i] = read();
	for(int i = 1;i <= n;i++)
		for(int j = 1;j <= n;j++)
			if(i != j)
				f[i][j] = (y[i]-y[j])/(x[i]-x[j]);
	for(int i = 1;i <= n;i++){
		int num = 0;
		sort(f[i]+1,f[i]+n+1);
		for(int j = 3;j <= n;j++)
			if(f[i][j] == f[i][j-1]){
				num++;
				ans = max(ans,num);
			}
			else num = 0;
	}
	printf("%d\n",ans+2);
	return 0;
}
