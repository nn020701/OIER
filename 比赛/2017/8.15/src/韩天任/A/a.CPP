#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<cstdlib>
using namespace std;
long long n,k,ans,x;
int zhu[1005][1005],fu[1005][1005],a[1005][1005];
bool b,bb;
int main(){
	freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			cin>>a[i][j];
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++){
			zhu[i][j]=a[i][j]+zhu[i-1][j+1];
			fu[i][j]=a[i][j]+fu[i-1][j-1];
		}
	ans=1;
	x=n;
	while (x>1 && not bb){
		b=false;
		if (x%2!=0)
			b=true;
		int x1,x2,y1,y2;
		x1=x; y1=1;
		x2=x; y2=x;
		for (int i=x;i<=n;i++){
			int temp,cha=0;
			temp=zhu[x1][y1+i-x]+fu[x2][y2+i-x];
			if (b)
				cha=a[x1-(y2-y1-1)][y1+i-x+(y2-y1-1)];
			if (temp-cha<=k){
				ans=x;
				bb=true;
				break;
			}
			temp=zhu[x1+i-x][y1]+fu[x2+i-x][y2];
			if (b)
				cha=a[x1+i-x-(y2-y1-1)][y1+(y2-y1-1)];
			if (temp-cha<=k){
				ans=x;
				bb=true;
				break;
			}
		x--;
		}
	}
	cout<<ans;
}
