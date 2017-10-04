#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
#define N 1005
int n,Ans,a[N][N],w,f1[N][N],f2[N][N],f3[N][N],f4[N][N];
inline bool pd1(int x,int y,int len){
	if(f1[x][y]-f1[x-len][y-len]+
	   f2[x][y]-f2[x+len][y-len]+
	   f3[x][y]-f3[x-len][y+len]+
	   f4[x][y]-f4[x+len][y+len]-a[x][y]*3<=w) return 1;
	return 0;
}
inline bool pd2(int x,int y,int len){
	if(x<len||y<len||x+len>n||y+len>n) return 0;
	if(f1[x][y]-f1[x-len][y-len]+
	   f2[x+1][y]-f2[x+1+len][y-len]+
	   f3[x][y+1]-f3[x-len][y+1+len]+
	   f4[x+1][y+1]-f4[x+1+len][y+1+len]<=w) return 1;
	return 0;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read();w=read();
	For(i,1,n) For(j,1,n) a[i][j]=read();
	For(i,1,n) For(j,1,n) f1[i][j]=f1[i-1][j-1]+a[i][j];
	Rep(i,n,1) For(j,1,n) f2[i][j]=f2[i+1][j-1]+a[i][j];
	For(i,1,n) Rep(j,n,1) f3[i][j]=f3[i-1][j+1]+a[i][j];
	Rep(i,n,1) Rep(j,n,1) f4[i][j]=f4[i+1][j+1]+a[i][j];
	For(i,1,n) For(j,1,n){
		int l=1,r=min(min(i,j),min(n-i+1,n-j+1)),ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(pd1(i,j,mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		Ans=max(Ans,ans*2-1);
	}
	For(i,1,n-1) For(j,1,n-1){
		int l=1,r=n/2,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(pd2(i,j,mid)) ans=mid,l=mid+1;
			else r=mid-1;
		}
		Ans=max(Ans,ans*2);
	}
	printf("%d",Ans);
	return 0;
}