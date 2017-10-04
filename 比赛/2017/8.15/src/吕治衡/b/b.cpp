#include<bits/stdc++.h>
using namespace std;
int n,m,x;
vector<int>a[200000];
vector<int>b[200000];
int main(){
	freopen("b.in","r",stdin);freopen("b.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;for (int i=0;i<=m;i++)a[0].push_back(0),b[0].push_back(0);
	for (int i=1;i<=n;i++)a[i].push_back(0),b[i].push_back(0);
	for (int i=1;i<=n;i++)
		for (int j=1;j<=m;j++){
			cin>>x;
			a[i].push_back(int(1<<x));
			b[i].push_back(int(x==0));
			a[i][j]=a[i][j]^a[i-1][j-1]^a[i-1][j]^a[i][j-1];
			b[i][j]=b[i][j]+b[i][j-1]+b[i-1][j]-b[i-1][j-1];
		}
	int kk=n*m;
	for (;kk>=1;kk--){
			for (int k=1;k*k<=kk;k++)
				if (kk%k==0){
					int x=k,y=kk/k;
					if (n>=x&&m>=y)
						for (int i=x;i<=n;i++)
							for (int j=y;j<=m;j++){
									int xx=a[i][j]^a[i-x][j-y]^a[i-x][j]^a[i][j-y],yy=b[i][j]+b[i-x][j-y]-b[i-x][j]-b[i][j-y];
									if (xx==(xx&(-xx))&&(yy<x*y-1||yy==0)){
											cout<<kk<<endl;return 0;
										}
								}
					swap(x,y);
					if (n>=x&&m>=y)
						for (int i=x;i<=n;i++)
							for (int j=y;j<=m;j++){
									int xx=a[i][j]^a[i-x][j-y]^a[i-x][j]^a[i][j-y],yy=b[i][j]+b[i-x][j-y]-b[i-x][j]-b[i][j-y];
									if (xx==(xx&(-xx))&&(yy<x*y-1||yy==0)){
											cout<<kk<<endl;return 0;
										}
								}
				}
		}
	cout<<0<<endl;return 0;
}
