#include<bits/stdc++.h>
#define For(i,x,y) for(int i=x;i<=y;i++)
#define Rep(i,x,y) for(int i=x;i>=y;i--)
#define N 10005
using namespace std;
inline int read(){int x=0,f=0;char ch=getchar();for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=1;for(;ch>='0'&&ch<='9';ch=getchar()) x=(x<<1)+(x<<3)+ch-48;return f?-x:x;}
vector <int> a[N];
vector <int> f[10][N];
int n,m,ans,p[10];
int main(){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	n=read();m=read();
	For(i,1,n) a[i].push_back(0);
	For(i,1,n) For(j,1,m){int x=read();a[i].push_back(x);}
	For(i,1,n) For(j,0,9) f[j][i].push_back(0);
	For(j,0,9) For(i,1,m) f[j][0].push_back(0);
	For(i,1,n) For(k,0,9) For(j,1,m){
		if(a[i][j]==k) f[k][i].push_back(f[k][i][j-1]+f[k][i-1][j]-f[k][i-1][j-1]+1);
		else f[k][i].push_back(f[k][i][j-1]+f[k][i-1][j]-f[k][i-1][j-1]);
	}
	For(i,1,n) For(j,1,m){
		For(k,1,i) For(l,1,j){
			if(ans>(i-k+1)*(j-l+1)) continue;
			For(gg,0,9){
				p[gg]=f[gg][i][j]-f[gg][k-1][l]-f[gg][i][l-1]+f[gg][k-1][l-1];
			}
			int x=0;
			For(gg,0,9) if(p[gg]&1) x++;
			if(x<=1) ans=max(ans,(i-k+1)*(j-l+1));
		}
	}
	printf("%d",ans);
	return 0;
}
