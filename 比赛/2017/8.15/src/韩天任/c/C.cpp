#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdlib>
using namespace std;
long long x,y,z,n,m,ans;
bool f[100005],b[10005][3505];
int main(){
	freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
		cin>>x>>y>>z;
		for (int j=x-z;j<=x+z;j++)
			if (j>0 && j<=n)
				if (b[j][y]!=true){
					b[j][y]=true;
					f[j]=true;
				}
				else
					f[j]=false;
			else
				break;
	}
	ans=0;
	for (int i=1;i<=n;i++)
		if (not f[i])
			ans++;
	cout<<ans;
}
