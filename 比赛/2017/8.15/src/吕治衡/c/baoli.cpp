#include<bits/stdc++.h>
using namespace std;
int n,m,x,y,z,ans;
bool flag[2000][2000],f[2000];
int main(){
	freopen("c.in","r",stdin);freopen("baoli.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for (int i=1;i<=m;i++){
			cin>>x>>y>>z;
			for (int j=1;j<=n;j++)
				if (abs(j-x)<=z){
					if (flag[j][y])f[j]=false;
						else f[j]=true,flag[j][y]=true;
				}
		}
	for (int i=1;i<=n;i++)ans+=!f[i];
	cout<<ans<<endl;
}
