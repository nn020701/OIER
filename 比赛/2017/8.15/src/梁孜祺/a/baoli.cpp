#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
#define N 1005
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
int n,w,a[N][N],f[N][N],g[N][N],ans;
inline int pd(int i,int j,int len){
	if(len&1) return a[i+len/2][j+len/2];
	return 0;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("baoli.out","w",stdout);
	n=read();w=read();
	For(i,1,n) For(j,1,n) a[i][j]=read();
	For(i,1,n) For(j,1,n) f[i][j]=f[i-1][j-1]+a[i][j];
	Rep(i,n,1) For(j,1,n) g[i][j]=g[i+1][j-1]+a[i][j];
	For(i,1,n) For(j,1,n) For(len,ans+1,n){
		if(i+len-1>n||j+len-1>n) break;
		if(f[i+len-1][j+len-1]-f[i-1][j-1]+g[i][j+len-1]-g[i+len][j-1]-pd(i,j,len)<=w) ans=max(ans,len);
	}
	printf("%d\n",ans);
	return 0;
}