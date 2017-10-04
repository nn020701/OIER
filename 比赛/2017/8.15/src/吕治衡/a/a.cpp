#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,w,a[2000][2000],f1[2000][2000],f2[2000][2000],ans;
bool ff;
bool pd(int x){
		for (int i=x;i<=n;i++)
			for (int j=x;j<=n;j++){
					int k=f1[i][j]-f1[i-x][j-x]+f2[i][j-x+1]-f2[i-x][j+1];
					if (x&1)k-=a[i-x/2][j-x/2];
					if (k<=w)return true;
				}
		return false;
	}
signed main(){
	freopen("a.in","r",stdin);freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>w;for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)cin>>a[i][j],f1[i][j]=f1[i-1][j-1]+a[i][j],f2[i][j]=f2[i-1][j+1]+a[i][j],ff|=a[i][j]<0;
	if (ff)for (int i=n;i>=1&&ans<30000000;i--)
		if (pd(i)){cout<<i<<endl;return 0;}else ans+=(n-i+1)*(n-i+1);
	int l=0,r=n;
	while (l<r){
			int m=(l+r+1)/2;
			if (pd(m))l=m;else r=m-1;
		}
	cout<<l<<endl;
}
