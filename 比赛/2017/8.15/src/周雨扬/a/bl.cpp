#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1005
ll a[N][N],b[N][N];
int c[N][N];
int n,w,ans;
const int L=200005;
char LZH[L],*S=LZH,*T=LZH;
inline char gc(){
	if (S==T){
		T=(S=LZH)+fread(LZH,1,L,stdin);
		if (S==T) return EOF;
	}
	return *S++;
}
inline int read(){
	int x=0;
	char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc());
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return x;
}
int calc(int x,int y,int z){
	int s=0;
	for (int i=0;i<=z;i++)
		s+=a[x+i][y+i];
	for (int i=0;i<=z;i++)
		s+=a[x+z-i][y+i];
	if (z%2==0) s-=a[x+z/2][y+z/2];
	return s;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("bl.out","w",stdout);
	n=read(); w=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			for (int k=0;k<=n-i&&k<=n-j;k++)
				if (calc(i,j,k)<=w) ans=max(ans,k+1);
	printf("%d",ans);
}
