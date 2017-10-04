#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!(ch>='0'&&ch<='9')){if(ch=='-') f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n;
int a[10010],b[10010];
int f[5010],g[5010];
int main(){
	freopen("airc.in","r",stdin);
	freopen("airc.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();b[i]=read();
	}
	memset(f,0x3f,sizeof f);
	f[0]=0;
	for(int i=1;i<=n;i++){
		memset(g,0x3f,sizeof(g));
		for(int j=1;j<=i&&j<=n/2;j++){
			g[j]=f[j-1]+b[i];
			if(i-j<=j)
				g[j]=min(g[j],f[j]+a[i]);
		}
		memcpy(f,g,sizeof(f));
	}
	cout<<f[n/2];
	return 0;
}
