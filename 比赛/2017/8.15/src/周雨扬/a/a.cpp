#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1005
ll a[N][N],b[N][N];
int c[N][N];
int n,w,Ans;
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
inline ll calc(int x,int y,int l){
	ll tmp=a[x+l-1][y+l-1]-a[x-1][y-1];
	tmp+=b[x+l-1][y]-b[x-1][y+l];
	if (l&1) tmp-=c[x+l/2][y+l/2];
	return tmp;
}
int main(){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read(); w=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]=b[i][j]=c[i][j]=read();
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			a[i][j]+=a[i-1][j-1];
	for (int i=1;i<=n;i++)
		for (int j=n;j;j--)
			b[i][j]+=b[i-1][j+1];
	Ans=0;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			int l=0,r=min(min(i-1,n-i),min(j-1,n-j)),mid,ans=-1;
			while (l<=r){
				int mid=(l+r)/2;
				if (calc(i-mid,j-mid,mid*2+1)<=w)
					ans=mid,l=mid+1;
				else r=mid-1;
			}
			if (ans>=0)
				Ans=max(Ans,2*ans+1);
			l=0,r=min(min(i-1,n-i-1),min(j-1,n-j-1)),ans=-1;
			while (l<=r){
				int mid=(l+r)/2;
				if (calc(i-mid,j-mid,mid*2+2)<=w)
					ans=mid,l=mid+1;
				else r=mid-1;
			}
			if (ans>=0)
				Ans=max(Ans,2*ans+2);
		}
	printf("%d",Ans);
}
