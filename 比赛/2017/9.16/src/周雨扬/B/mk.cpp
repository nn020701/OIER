#include<bits/stdc++.h>
using namespace std;
int f[205][205][205],a[205],n,T;
int dp(int l,int r,int pre){
	if (l==r) return (pre+1)*(pre+1);
	if (f[l][r][pre]!=-1) return f[l][r][pre];
	if (a[l]==a[l+1]) return f[l][r][pre]=dp(l+1,r,pre+1);
	int mx=(pre+1)*(pre+1)+dp(l+1,r,0);
	for (int i=l+2;i<=r;i++)
		if (a[i]==a[l]&&a[i-1]!=a[l])
			mx=max(mx,dp(l+1,i-1,0)+dp(i,r,pre+1));
	return f[l][r][pre]=mx;
}
int main(){
	freopen("B.in","w",stdout);
	printf("15\n");
	for (int i=1;i<=15;i++){
		printf("200\n");
		for (int j=1;j<=200;j++)
			a[j]=rand()%2+1;
		/*for (int j=1;j<=150;j++){
			int x=rand()%199+1;
			a[x]=a[x+1];
		}*/
		for (int j=1;j<=200;j++)
			printf("%d ",a[j]);
		puts("");
	}
}
