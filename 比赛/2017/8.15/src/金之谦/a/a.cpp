#include <cstdio>
#include <cstring>
#include <iostream>
#include <cstdlib>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <vector>
#include <ctime>
#include <climits>
#define int long long
using namespace std;
inline int read(){
	int k=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){k=k*10+ch-'0';ch=getchar();}
	return k*f;
}
int a[1010][1010],n,w,zhu[1010][1010],fu[1010][1010];
inline bool check(int x){
	for(int i=0;i<=n-x;i++)
		for(int j=0;j<=n-x;j++){
			int X=zhu[i+x][j+x]-zhu[i][j],Y=fu[i+x][j+1]-fu[i][j+x+1];
			int sum=X+Y-((x&1)?a[i+x-(x/2)][j+x-(x/2)]:0);
			if(sum<=w)return 1;
		}
	return 0;
}
signed main()
{
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	n=read();w=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)a[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			zhu[i][j]=a[i][j]+zhu[i-1][j-1];
			fu[i][j]=a[i][j]+fu[i-1][j+1];
		}
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	cout<<ans<<endl;
	return 0;
}
