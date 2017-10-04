#include<bits/stdc++.h>
#define sqr(x) (x)*(x)
#define N 205
using namespace std;
int f[N][N][N],a[N],nxt[N][N],n,T;
int dp(int l,int r,int pre){
	if (l==r) return (pre+1)*(pre+1);
	if (f[l][r][pre]!=-1) return f[l][r][pre];
	if (a[l]==a[l+1]) return f[l][r][pre]=dp(l+1,r,pre+1);
	int mx=(pre+1)*(pre+1)+dp(l+1,r,0);
	for (int i=nxt[l][l];i<=r;i=nxt[l][i])
		mx=max(mx,dp(l+1,i-1,0)+dp(i,r,pre+1));
	return f[l][r][pre]=mx;
}
int main(){
	freopen("dt.out","w",stdout);
	for (int i=1;i<=200;i++){
		double ans=0;
		for (int j=1;j<=200;j++)
			for (int k=j;k<=200;k++)
				ans=ans+1.0*(k-j)*(i-1)/i/i*j/i;
		printf("%.15lf\n",ans);
	}
}
