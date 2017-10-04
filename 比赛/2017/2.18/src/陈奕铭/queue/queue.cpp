#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
const int mod=100000000;
int f[210][2][15][110];
int n1,n2,k1,k2;
int main(){
	freopen("queue.in","r",stdin);
	freopen("queue.out","w",stdout);
	n1=read();n2=read();k1=read();k2=read();
	if(k1==0||k2==0){
		printf("0\n");
		return 0;
	}
	f[1][0][1][1]=1;
	f[1][1][1][0]=1;
	for(int i=2;i<=n1+n2;i++){
			for(int j=2;j<=min(i,k1);j++){
				for(int z=2;z<=min(n1,i);z++)
					f[i][0][j][z]=(f[i][0][j][z]+f[i-1][0][j-1][z-1])%mod;
			}
			for(int j=1;j<=min(i,k1);j++)
				for(int z=1;z<=min(n1,i);z++)
					f[i][1][1][z]=(f[i][1][1][z]+f[i-1][0][j][z])%mod;
			for(int j=2;j<=min(i,k2);j++){
				for(int z=0;z<=min(n1,i);z++)
					f[i][1][j][z]=(f[i][1][j][z]+f[i-1][1][j-1][z])%mod;
			}
			for(int j=1;j<=min(i,k2);j++)
				for(int z=1;z<=min(n1,i);z++)
					f[i][0][1][z]=(f[i][0][1][z]+f[i-1][1][j][z-1])%mod;
	}
	int ans=0;	
	for(int i=1;i<=k1;i++)
		ans=(ans+f[n1+n2][0][i][n1])%mod;
	for(int i=1;i<=k2;i++)
		ans=(ans+f[n1+n2][1][i][n1])%mod;
	printf("%d\n",ans);
	return 0;
}
