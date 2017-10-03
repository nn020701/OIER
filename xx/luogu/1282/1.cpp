#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define N 1005
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;
int a[N],b[N],c[N];
int f[N][10005];
int INF;

int main(){
	n = read();
	int num = 0;
	for(int i = 1;i <= n;i++){
		a[i] = read(); b[i] = read();
		c[i] = a[i]-b[i];
		num += abs(c[i]);
		
	}
	memset(f,0x3f,sizeof f);
	INF = f[0][0];
	f[1][2*num-c[1]] = 1;
	f[1][2*num+c[1]] = 0;
	for(int i = 2;i <= n;i++)
		for(int j = num;j <= num*3;j++)
			if(f[i-1][j] < INF){
				f[i][j+c[i]] = min(f[i][j+c[i]],f[i-1][j]);
				f[i][j-c[i]] = min(f[i][j-c[i]],f[i-1][j]+1);
			}
	for(int i = num*2;i >= num;i--){
		if(f[n][i] < INF || f[n][num*4-i] < INF){
			if(f[n][i] < INF && f[n][num*4-i] < INF){
				int ans = min(min(f[n][i],n-f[n][i]),min(f[n][num*4-i],n-f[n][num*4-i]));
				printf("%d\n",ans);
			}
			else if(f[n][i] < INF){
				int ans = min(f[n][i],n-f[n][i]);
				printf("%d\n",ans);
			}
			else{
				int ans = min(f[n][num*4-i],n-f[n][num*4-i]);
				printf("%d\n",ans);
			}
			break;
		}
	}
	return 0;
}